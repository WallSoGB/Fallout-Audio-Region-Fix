#include "BGSAcousticSpace.hpp"
#include "BSSoundHandle.hpp"
#include "BSWin32Audio.hpp"
#include "INISettingCollection.hpp"
#include "Sky.hpp"
#include "TES.hpp"
#include "TESSound.hpp"

// Fixes the issue where the sound is removed, despite the new space having the same sound
#define NO_MATCHING_SOUND_REMOVAL

BGSAcousticSpace** const BGSAcousticSpace::pCurrentSpace = (BGSAcousticSpace**)0x11DCFB4;
BGSAcousticSpace** const BGSAcousticSpace::pCurrentCellSpace = (BGSAcousticSpace**)0x11DCFB8;
bool* const BGSAcousticSpace::bJustChanged = (bool*)0x11DCFB1;

BGSAcousticSpace* BGSAcousticSpace::GetCurrentCellSpace() {
	return *pCurrentCellSpace;
}

void BGSAcousticSpace::SetCurrentCellSpace(BGSAcousticSpace* apSpace) {
	*pCurrentCellSpace = apSpace;
}

BGSAcousticSpace* BGSAcousticSpace::GetCurrentSpace() {
	return *pCurrentSpace;
}

// GAME - 0x82EAE0
void BGSAcousticSpace::SetCurrentSpace(BGSAcousticSpace* apSpace) {
	if (apSpace == *pCurrentSpace)
		return;

	bool bRemoveSound = true;
#ifdef NO_MATCHING_SOUND_REMOVAL
	if (apSpace && *pCurrentSpace) {
		float fTime = TES::GetSingleton()->GetSky()->fCurrentGameHour;
		bRemoveSound = (*pCurrentSpace)->GetSoundForTime(fTime) != apSpace->GetSoundForTime(fTime);
	}
#endif

	if (bRemoveSound) {
		BSSoundHandle* pCurrSound = GetCurrentSound();
		pCurrSound->FadeOutAndRelease(INISettingCollection::Audio::fASFadeOutTime->Float() * 1000.f);
		pCurrSound->Reset();

		if (apSpace)
			BSWin32Audio::GetSingleton()->SetEnvironmentType(apSpace->eEnvironmentType);
	}

	*pCurrentSpace = apSpace;
	*bJustChanged = true;
}

// GAME - 0x82EB70
void BGSAcousticSpace::RemoveCurrentSpace(BGSAcousticSpace* apSpace) {
	CdeclCall(0x82EB70, apSpace);
}

BSSoundHandle* BGSAcousticSpace::GetCurrentSound() {
    return (BSSoundHandle*)0x11DD0D8;
}

void BGSAcousticSpace::SetCurrentSound(BSSoundHandle& arSound) {
	(*(BSSoundHandle*)0x11DD0D8) = arSound;
}

NiTMap<uint32_t, BSSoundHandle*>* BGSAcousticSpace::GetPlayingLoopSounds() {
	return (NiTMap<uint32_t, BSSoundHandle*>*)0x11DD014;
}

BGSAcousticSpace::TimeOfDay BGSAcousticSpace::GetCurrentTimeOfDay() {
    return *(TimeOfDay*)0x11DCFAC;
}

void BGSAcousticSpace::SetCurrentTimeOfDay(TimeOfDay aeTimeOfDay) {
	*(TimeOfDay*)0x11DCFAC = aeTimeOfDay;
}

bool BGSAcousticSpace::GetJustChanged() {
	return *bJustChanged;
}

void BGSAcousticSpace::SetJustChanged(bool abJustChanged) {
	*bJustChanged = abJustChanged;
}

uint32_t BGSAcousticSpace::GetTimeDelta() {
	return *(uint32_t*)0x11DCFC0;
}

void BGSAcousticSpace::SetTimeDelta(uint32_t auiTimeDelta) {
	*(uint32_t*)0x11DCFC0 = auiTimeDelta;
}

const char* BGSAcousticSpace::GetTimeOfDayName(TimeOfDay aeTimeOfDay) {
	switch (aeTimeOfDay) {
	case BGSAcousticSpace::DAWN:
		return "Dawn";
	case BGSAcousticSpace::NOON:
		return "Noon";
	case BGSAcousticSpace::DUSK:
		return "Dusk";
	case BGSAcousticSpace::NIGHT:
		return "Night";
	default:
		return "Unknown";
	}
}


// Based on 0x82DF09
TESSound* BGSAcousticSpace::GetSoundForTime(float afTime) const {
	if (INISettingCollection::Audio::fDawnTime->Float() < afTime) {
		if (INISettingCollection::Audio::fDayTime->Float() >= afTime) {
			BGSAcousticSpace::SetCurrentTimeOfDay(BGSAcousticSpace::DAWN);
			return pDawnSound;
		}

		if (INISettingCollection::Audio::fDuskTime->Float() >= afTime) {
			BGSAcousticSpace::SetCurrentTimeOfDay(BGSAcousticSpace::NOON);
			return pNoonSound;
		}

		if (INISettingCollection::Audio::fNightTime->Float() >= afTime) {
			BGSAcousticSpace::SetCurrentTimeOfDay(BGSAcousticSpace::DUSK);
			return pDuskSound;
		}
	}

	BGSAcousticSpace::SetCurrentTimeOfDay(BGSAcousticSpace::NIGHT);
	return pNightSound;
}
