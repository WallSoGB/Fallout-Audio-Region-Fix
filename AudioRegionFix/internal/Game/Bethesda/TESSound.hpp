#pragma once

#include "TESBoundAnimObject.hpp"
#include "TESSoundFile.hpp"

class BSSoundHandle;

class TESSound : public TESBoundAnimObject, public TESSoundFile {
public:
	TESSound();
	~TESSound();

	enum TESSoundFlags
	{
		kFlag_RandomFrequencyShift = 1,
		kFlag_PlayAtRandom = 2,
		kFlag_EnvironmentIgnored = 4,
		kFlag_RandomLocation = 8,
		kFlag_Loop = 16,
		kFlag_MenuSound = 32,
		kFlag_2D = 64,
		kFlag_360LFE = 128,
		kFlag_DialogueSound = 256,
		kFlag_EnvelopeFast = 512,
		kFlag_EnvelopeSlow = 1024,
		kFlag_2DRadius = 2048,
		kFlag_MuteWhenSubmerged = 4096,
		kFlag_StartAtRandomPosition = 8192,
	};

	struct Data {
		uint8_t		ucMinAttenuationDist;
		uint8_t		ucMaxAttenuationDist;
		uint8_t		ucFrequencyAdj;
		uint8_t		byte03;
		Bitfield32	uiSoundFlags;
		uint16_t	usStaticAttenuation;
		union {
			uint16_t usStartEnd;
			struct {
				uint8_t	ucEndsAt;
				uint8_t	ucStartsAt;
			};
		};
		uint16_t	usAttenuationCurve[5];
		uint16_t	usReverbAttenuation;
		uint32_t	uiPriority;
		uint32_t	uiLoopPointBegin;
		uint32_t	uiLoopPointEnd;

		uint32_t ConvertFlags() const;
	};

	BSString	strEditorID;
	Data		kData;
	uint8_t		ucRngChance;

	void SetFlag(uint32_t pFlag, bool bMod) {
		kData.uiSoundFlags.SetBit(pFlag, bMod);
	}

	bool GetFlag(uint32_t pFlag) const {
		return kData.uiSoundFlags.IsSet(pFlag);
	}

	uint32_t GetStartsAt() const;
	uint32_t GetEndsAt() const;
	TESSound::Data GetData() const;

	const char* GetFilePath() const;

	static TESSound* GetNoActivateSound();

	static BSSoundHandle* GetUnderwaterAmbiance();
	static void SetUnderwaterAmbiance(BSSoundHandle& arHandle);
	static void SetUnderwaterAmbiance(BSSoundHandle* apHandle);

	static void InitFootstepSounds();
	static void ResetPlayingWeaponSounds();

	static void UpdateRegionSounds();
};

ASSERT_SIZE(TESSound, 0x6C);