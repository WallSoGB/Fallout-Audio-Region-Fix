#include "TESSound.hpp"
#include "BGSAcousticSpace.hpp"
#include "BSAudioManager.hpp"
#include "BSGameSound.hpp"
#include "BSRandom.hpp"
#include "BSWin32Audio.hpp"
#include "INISettingCollection.hpp"
#include "Interface.hpp"
#include "PlayerCharacter.hpp"
#include "Sky.hpp"
#include "TES.hpp"
#include "TESObjectCELL.hpp"
#include "TESRegion.hpp"
#include "TESRegionDataList.hpp"
#include "TESRegionDataSound.hpp"
#include "TESWeather.hpp"

#define FIX_REGION_SOUND_TRANSITION
#define DEBUG_SOUND_TRANSITION 0

uint8_t TESSound::GetStartsAt() const {
	return kData.ucStartsAt;
}

uint8_t TESSound::GetEndsAt() const {
	return kData.ucEndsAt;
}

TESSound::Data TESSound::GetData() const {
	return kData;
}

const char* TESSound::GetFilePath() const {
	return GetPath();
}

// GAME - 0x82EC10
TESSound* TESSound::GetNoActivateSound() {
	return StdCall<TESSound*>(0x82EC10);
}

BSSoundHandle* TESSound::GetUnderwaterAmbiance() {
	return (BSSoundHandle*)0x11DD0A0;
}

void TESSound::SetUnderwaterAmbiance(BSSoundHandle& arHandle) {
	(*(BSSoundHandle*)0x11DD0A0) = arHandle;
}

void TESSound::SetUnderwaterAmbiance(BSSoundHandle* apHandle) {
	(*(BSSoundHandle*)0x11DD0A0) = apHandle;
}

// GAME - 0x839AB0
void TESSound::InitFootstepSounds() {
	CdeclCall(0x839AB0);
}

// GAME - 0x839D30
void TESSound::ResetPlayingWeaponSounds() {
	CdeclCall(0x839D30);
}

// GAME - 0x82D7C0
void TESSound::UpdateRegionSounds() {
	PlayerCharacter* pPlayer = PlayerCharacter::GetSingleton();
	BSWin32Audio* pWinAudio = BSWin32Audio::GetSingleton();
	BSSimpleList<TESRegionSound*>* pRegionSounds = &pPlayer->kRegionSounds;
	const bool bPlayerUnderwater = BSAudioManager::GetSingleton()->bIsPlayerUnderwater;

	BGSAcousticSpace* pAcousticSpace = nullptr;
	TESObjectCELL* pPlayerCell = nullptr;

	if (!pPlayer)
		pAcousticSpace = nullptr;
	else if (pPlayer->GetParentCell()) {
		pPlayerCell = pPlayer->GetParentCell();
		pAcousticSpace = pPlayerCell->GetAcousticSpace();
	}
	else
		pAcousticSpace = nullptr;

	// Transition from exterior to interior
	{
		const BGSAcousticSpace* pCurrSpace = BGSAcousticSpace::GetCurrentSpace();
		if ((pCurrSpace && !pCurrSpace->bIsInterior) && (pAcousticSpace && pAcousticSpace->bIsInterior)) {
			BGSAcousticSpace::SetCurrentSpace(pAcousticSpace);
			BGSAcousticSpace::SetJustChanged(false);
			BGSAcousticSpace::SetCurrentCellSpace(nullptr);
		}
	}

	// Override current space with cell's acoustic space
	{
		BGSAcousticSpace* pCurrCellSpace = BGSAcousticSpace::GetCurrentCellSpace();
		if (BGSAcousticSpace::GetJustChanged()) {
			if (pCurrCellSpace != BGSAcousticSpace::GetCurrentSpace()) {
				BGSAcousticSpace::SetCurrentSpace(pCurrCellSpace);
			}
			else {
				BGSAcousticSpace::SetCurrentCellSpace(nullptr);
				BGSAcousticSpace::SetJustChanged(false);
			}
		}
	}

	// Precache no activate sound (why?)
	{
		TESSound* pNoActivateSound = GetNoActivateSound();
		if (pNoActivateSound) {
			constexpr uint32_t eFlags = BSGameSound::FLAG_UNKBIT8 | BSGameSound::FLAG_SYSTEM_SOUND | BSGameSound::FLAG_2D;
			pWinAudio->PrecacheSound(pNoActivateSound->GetFilePath(), eFlags, pNoActivateSound);
		}
	}

	// Clear space if no cell or no player
	{
		const BGSAcousticSpace* pCurrSpace = BGSAcousticSpace::GetCurrentSpace();
		if (!pCurrSpace && pPlayerCell && pPlayerCell->GetAcousticSpace() != pCurrSpace)
			BGSAcousticSpace::SetCurrentSpace(pAcousticSpace);
		else if (!pPlayerCell && !pPlayer->bPreventRegionSoundUpdates)
			BGSAcousticSpace::RemoveCurrentSpace(nullptr);
	}

	// Use current's space sounds instead of player's cell
	{
		const BGSAcousticSpace* pCurrSpace = BGSAcousticSpace::GetCurrentSpace();
		if (pCurrSpace && pCurrSpace->pRegion) {
			TESRegionDataList* pDataList = pCurrSpace->pRegion->pDataEntries;
			TESRegionDataSound* pRegionDataSounds = static_cast<TESRegionDataSound*>(pDataList->Find(REGION_DATA_SOUND_ID));
			if (pRegionDataSounds)
				pRegionSounds = &pRegionDataSounds->kSoundTypes;
		}
	}

	// Set environment type
	{
		const BGSAcousticSpace* pCurrSpace = BGSAcousticSpace::GetCurrentSpace();
		pWinAudio->SetEnvironmentType(pCurrSpace ? pCurrSpace->eEnvironmentType : 0);
	}

	// Play underwater sounds
	{
		BSSoundHandle* pUnderwaterAmbiance = GetUnderwaterAmbiance();
		if (bPlayerUnderwater && pPlayerCell && !pUnderwaterAmbiance->IsPlaying()) {
			constexpr uint32_t eFlags = BSGameSound::FLAG_MAYBE_UNDERWATER | BSGameSound::FLAG_UNKBIT8 | BSGameSound::FLAG_2D;
			BSSoundHandle kHandle = pWinAudio->GetSoundHandleByEditorName("AMBUnderwaterLP", eFlags);
			SetUnderwaterAmbiance(kHandle);

			pUnderwaterAmbiance->bAssumeSuccess = true;
			pUnderwaterAmbiance->Play(false);
		}
		else if (!bPlayerUnderwater || !pPlayerCell) {
			if (pUnderwaterAmbiance->IsPlaying())
				pUnderwaterAmbiance->FadeOutAndRelease(300);
		}
	}

	InitFootstepSounds();
	ResetPlayingWeaponSounds();

	// ?? Set alongside bPreventRegionSoundUpdates when moving to a new cell
	if (*(bool*)0x11DCFA6)
		return;

	const Sky* pSky = TES::GetSingleton()->GetSky();
	const float fGameHour = pSky ? pSky->fCurrentGameHour : 0.f;

	pWinAudio->SetGameHour(fGameHour);

	// Clear playing loop sounds
	if (abs(int(pWinAudio->GetTimeDelta() - BGSAcousticSpace::GetTimeDelta())) <= 1000) {
		auto pPlayingLoopSounds = BGSAcousticSpace::GetPlayingLoopSounds();
		if (!pRegionSounds->IsEmpty() || pPlayingLoopSounds->GetCount() == 0)
			return;

		NiTMapIterator kIter = pPlayingLoopSounds->GetFirstPos();
		while (kIter) {
			uint32_t uiFormID = 0;
			BSSoundHandle* pHandle = nullptr;
			pPlayingLoopSounds->GetNext(kIter, uiFormID, pHandle);
			pPlayingLoopSounds->RemoveAt(uiFormID);
			kIter = pPlayingLoopSounds->GetFirstPos();

			pHandle->FadeOutAndRelease(300);
			if (pHandle)
				delete pHandle;

			pHandle = 0;
		}
		return;
	}

	// Clear current music marker
	if (pPlayer)
		pPlayer->pCurrMusicMarker = nullptr;

	// Update looping sounds
	if (!Interface::IsTopMenuID(Interface::Pause))
		TES::GetSingleton()->HandleCellLoopingSounds();
	
	float fFadeTime = INISettingCollection::Audio::fASFadeStartTime->Float();
	if (BGSAcousticSpace::GetCurrentSound()->IsPlaying())
		fFadeTime = INISettingCollection::Audio::fASFadeInTime->Float();

	// Holyyy fuck
	{
		const BGSAcousticSpace* pCurrSpace = BGSAcousticSpace::GetCurrentSpace();
		if (pCurrSpace && pPlayer) {
#ifdef FIX_REGION_SOUND_TRANSITION
			bool bInvalidated = BGSAcousticSpace::GetJustChanged();
			BSSoundHandle* pCurrentSound = BGSAcousticSpace::GetCurrentSound();
			if (!pCurrentSound->IsValid())
				bInvalidated = true;
#endif

			if (pCurrSpace->bIsInterior) {
#ifndef FIX_REGION_SOUND_TRANSITION
				bool bInvalidated = BGSAcousticSpace::GetJustChanged();
				BSSoundHandle* pCurrentSound = BGSAcousticSpace::GetCurrentSound();
				if (!pCurrentSound->IsValid())
					bInvalidated = true;
#endif

				if (bInvalidated) {
					if (BGSAcousticSpace::GetJustChanged()) {
						BGSAcousticSpace::SetCurrentCellSpace(nullptr);
						BGSAcousticSpace::SetJustChanged(false);
					}

					if (pCurrentSound->IsPlaying()) {
						pCurrentSound->FadeOutAndRelease(INISettingCollection::Audio::fASFadeOutTime->Float() * 500.f);
						pCurrentSound->Reset();
					}

					if (pCurrSpace->pDawnSound) {
						constexpr uint32_t eFlags = BSGameSound::FLAG_DONT_CACHE | BSGameSound::FLAG_REGION_MUTE_WHEN_SUBMERGED | BSGameSound::FLAG_LOOP | BSGameSound::FLAG_2D;
						const char* pDawnSoundName = pCurrSpace->pDawnSound->GetFilePath();
						BSSoundHandle kHandle = pWinAudio->GetSoundHandleByFilePath(pDawnSoundName, eFlags, pCurrSpace->pDawnSound);
						BGSAcousticSpace::SetCurrentSound(kHandle);
						kHandle.FadeInPlay((fFadeTime * 1000.f));
					}
				}
				goto Play_Loop_Sounds;
			}
#ifdef FIX_REGION_SOUND_TRANSITION
			bool bHasChanged = bInvalidated;
#else
			bool bHasChanged = BGSAcousticSpace::GetJustChanged();
#endif
			if (!bHasChanged) {
				switch (BGSAcousticSpace::GetCurrentTimeOfDay()) {
				case BGSAcousticSpace::DAWN:
					if (INISettingCollection::Audio::fDayTime->Float() < fGameHour)
						bHasChanged = true;
					break;
				case BGSAcousticSpace::NOON:
					if (INISettingCollection::Audio::fDuskTime->Float() < fGameHour)
						bHasChanged = true;
					break;
				case BGSAcousticSpace::DUSK:
					if (INISettingCollection::Audio::fNightTime->Float() < fGameHour)
						bHasChanged = true;
					break;
				case BGSAcousticSpace::NIGHT:
					if (INISettingCollection::Audio::fDawnTime->Float() < fGameHour && INISettingCollection::Audio::fNightTime->Float() > fGameHour)
						bHasChanged = true;
					break;
				default:
					break;
				}
#if DEBUG_SOUND_TRANSITION
				if (bHasChanged) {
					char cBuffer[128];
					sprintf_s(cBuffer, "Time of day changed to: %s", BGSAcousticSpace::GetTimeOfDayName(BGSAcousticSpace::GetCurrentTimeOfDay()));
					Interface::ShowNotify(cBuffer, Interface::Emotion::HAPPY, nullptr, nullptr, 2.f, true);
				}
#endif
			}

			if (!bHasChanged)
				goto Play_Loop_Sounds;

			if (BGSAcousticSpace::GetJustChanged()) {
				BGSAcousticSpace::SetCurrentCellSpace(nullptr);
				BGSAcousticSpace::SetJustChanged(false);
			}
			else {
				BGSAcousticSpace::GetCurrentSound()->FadeOutAndRelease(INISettingCollection::Audio::fASFadeOutTime->Float() * 1000.f);
				BGSAcousticSpace::GetCurrentSound()->Reset();
			}

			TESSound* pTimeOfDaySound = pCurrSpace->GetSoundForTime(fGameHour);
			if (pTimeOfDaySound) {
				constexpr uint32_t eFlags = BSGameSound::FLAG_DONT_CACHE | BSGameSound::FLAG_REGION_MUTE_WHEN_SUBMERGED | BSGameSound::FLAG_LOOP | BSGameSound::FLAG_2D;
				const char* pPath = pTimeOfDaySound->GetFilePath();
				BSSoundHandle kHandle = pWinAudio->GetSoundHandleByFilePath(pPath, eFlags, pTimeOfDaySound);
				BGSAcousticSpace::SetCurrentSound(kHandle);
#if !DEBUG_SOUND_TRANSITION
				kHandle.FadeInPlay((fFadeTime * 1000.f));
#else
				kHandle.Play(true);
				char cBuffer[512];
				sprintf_s(cBuffer, "Playing: \"%s\"", pPath);
				Interface::ShowNotify(cBuffer, Interface::Emotion::HAPPY, nullptr, nullptr, 2.f, true);
#endif
			}
			goto Play_Loop_Sounds;
		}

#if !DEBUG_SOUND_TRANSITION
		BGSAcousticSpace::GetCurrentSound()->FadeOutAndRelease(1000);
#else
		BGSAcousticSpace::GetCurrentSound()->Stop();
		BGSAcousticSpace::GetCurrentSound()->Release();
		Interface::ShowNotify("Fading out current sound", Interface::Emotion::SAD, nullptr, nullptr, 2.f, true);
#endif
		BGSAcousticSpace::GetCurrentSound()->Reset();

	Play_Loop_Sounds:
		if (pRegionSounds->IsEmpty() || Interface::IsTopMenuID(Interface::Pause))
			goto Exit;

		const BSWin32AudioListener* pAudioListener = pWinAudio->pListener;
		auto pPlayingLoopSounds = BGSAcousticSpace::GetPlayingLoopSounds();
		{

			auto pRegionSoundsIter = pRegionSounds;
			while (pRegionSoundsIter && !pRegionSoundsIter->IsEmpty()) {
				TESSound* pSound = nullptr;
				bool bSomethingWithWeather = true;
				bool bPlayingSoundFound = false;
				const TESRegionSound* pRegionSound = pRegionSoundsIter->GetItem();

				if (pRegionSound && pRegionSound->pSound) {
					pSound = pRegionSound->pSound;
					const float fStartsAt = float(pSound->GetStartsAt()) * 0.09375f;
					const float fEndsAt = float(pSound->GetEndsAt()) * 0.09375f;
					bool bHasWeatherFlags = TESSound::ConvertFlags(pSound->GetData().uiSoundFlags.Get()) != 0;

					if (pSky) {
						uint16_t usRegionSoundFlags = pRegionSound->uiFlags.Get();
						if (usRegionSoundFlags && pSky->pCurrentWeather) {
							uint8_t ucWeatherFlags = pSky->pCurrentWeather->GetWeatherDataRaw(TESWeather::WD_FLAGS);
							if ((ucWeatherFlags & uint8_t(usRegionSoundFlags)) == 0 && ucWeatherFlags)
								bSomethingWithWeather = false;
						}

						if (fabsf(fEndsAt - fStartsAt) >= 0.09375f && (fEndsAt > fStartsAt && (fGameHour < fStartsAt || fGameHour > fEndsAt) || fEndsAt < fStartsAt && fGameHour < fStartsAt && fGameHour > fEndsAt))
							bSomethingWithWeather = false;
					}

					BSSoundHandle* pFoundHandle = nullptr;
					uint32_t uiFormID = pSound->GetFormID();
					bPlayingSoundFound = pPlayingLoopSounds->GetAt(uiFormID, pFoundHandle);
					if (bHasWeatherFlags && !bPlayingSoundFound && bSomethingWithWeather) {
						constexpr uint32_t eFlags = BSGameSound::FLAG_DONT_CACHE | BSGameSound::FLAG_REGION_MUTE_WHEN_SUBMERGED | BSGameSound::FLAG_LOOP | BSGameSound::FLAG_2D;
						const char* pPath = pSound->GetFilePath();
						BSSoundHandle* pNewHandle = new BSSoundHandle();

						*pNewHandle = pWinAudio->GetSoundHandleByFilePath(pPath, eFlags, pSound);
						pNewHandle->bAssumeSuccess = true;
						pPlayingLoopSounds->SetAt(uiFormID, pNewHandle);
						pNewHandle->FadeInPlay(INISettingCollection::Audio::fRegionLoopFadeInTime->Float() * 1000.f);

					}
					else if (bHasWeatherFlags && bPlayingSoundFound) {
						if (pFoundHandle->IsPlaying() && !bSomethingWithWeather) {
							pFoundHandle->FadeOutAndRelease(INISettingCollection::Audio::fRegionLoopFadeOutTime->Float() * 1000.f);
							pPlayingLoopSounds->RemoveAt(uiFormID);
							if (pFoundHandle)
								delete pFoundHandle;
						}
						else if (pFoundHandle->IsValid() && !pFoundHandle->IsPlaying() && bSomethingWithWeather) {
							pFoundHandle->FadeInPlay(INISettingCollection::Audio::fRegionLoopFadeInTime->Float() * 1000.f);
						}
					}
					else if (!bHasWeatherFlags && bSomethingWithWeather) {
						float fChance = static_cast<float>(pRegionSound->uiChance) / 20000000.f;
						if (BSRandom::IsRandomDecimalBelow(fChance)) {
							BSSoundHandle kSoundToPlay;
							if (pSound->GetFlag(kFlag_2D)) {
								constexpr uint32_t eFlags = BSGameSound::FLAG_DONT_CACHE | BSGameSound::FLAG_REGION_MUTE_WHEN_SUBMERGED | BSGameSound::FLAG_UNKBIT8 | BSGameSound::FLAG_2D;
								const char* pPath = pSound->GetFilePath();
								kSoundToPlay = pWinAudio->GetSoundHandleByFilePath(pPath, eFlags, pSound);
							}
							else {
								constexpr uint32_t eFlags = BSGameSound::FLAG_DONT_CACHE | BSGameSound::FLAG_REGION_MUTE_WHEN_SUBMERGED | BSGameSound::FLAG_UNKBIT8 | BSGameSound::FLAG_3D;
								const char* pPath = pSound->GetFilePath();
								kSoundToPlay = pWinAudio->GetSoundHandleByFilePath(pPath, eFlags, pSound);
							}

							NiPoint3 kPosition;
							if (pAudioListener)
								kPosition = pAudioListener->GetPosition();
							else if (pPlayer)
								kPosition = pPlayer->GetPos();

							float fOffsetX = float(BSRandom::RandomUnsignedInt() % 650 + 100);
							float fOffsetY = float(BSRandom::RandomUnsignedInt() % 650 + 100);
							if (BSRandom::IsRandomDecimalBelow(0.5f))
								fOffsetX = fOffsetX * -1.f;
							if (BSRandom::IsRandomDecimalBelow(0.5f))
								fOffsetY = fOffsetY * -1.f;
							kPosition.x = kPosition.x + fOffsetX;
							kPosition.y = kPosition.y + fOffsetY;
							kPosition.z = kPosition.z + 256.f;

							kSoundToPlay.SetPriority(UINT8_MAX);
							kSoundToPlay.SetPosition(kPosition.x, kPosition.y, kPosition.z);
							kSoundToPlay.Play(false);
						}
					}

					pRegionSoundsIter = pRegionSoundsIter->GetNext();
				}
			}
		}

		// Clear playing loop sounds
		{
			NiTMapIterator kIter = pPlayingLoopSounds->GetFirstPos();
			auto pRegionSoundsIter = pRegionSounds;
			bool bFound = false;
			while (kIter) {
				uint32_t uiFormID = 0;
				BSSoundHandle* pHandle = nullptr;
				pPlayingLoopSounds->GetNext(kIter, uiFormID, pHandle);

				while (pRegionSoundsIter && !pRegionSoundsIter->IsEmpty()) {
					TESRegionSound* pPlayingRegionSound = pRegionSoundsIter->GetItem();
					if (pPlayingRegionSound && pPlayingRegionSound->pSound && pPlayingRegionSound->pSound->GetFormID() == uiFormID) {
						bFound = true;
						break;
					}
					pRegionSoundsIter = pRegionSoundsIter->GetNext();
				}

				if (bFound)
					continue;

				pPlayingLoopSounds->RemoveAt(uiFormID);
				kIter = pPlayingLoopSounds->GetFirstPos();
				pHandle->FadeOutAndRelease(INISettingCollection::Audio::fRegionLoopFadeOutTime->Float() * 1000.f);
				if (pHandle)
					delete pHandle;
			}
		}
	}

	Exit:
	BGSAcousticSpace::SetTimeDelta(pWinAudio->GetTimeDelta());
}

// GAME - 0x5E39B0
uint32_t TESSound::ConvertFlags(uint16_t ausFlags) {
	if ((ausFlags & 0x10) != 0)
		return 0x10;

	if ((ausFlags & 0x200) != 0)
		return 0x2000000;

	if ((ausFlags & 0x400) != 0)
		return 0x4000000;

	return 0;
}
