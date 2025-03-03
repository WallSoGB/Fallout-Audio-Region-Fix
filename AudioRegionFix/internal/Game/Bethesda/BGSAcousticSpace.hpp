#pragma once

#include "TESBoundObject.hpp"
#include "NiTMap.hpp"

class TESSound;
class TESRegion;
class BSSoundHandle;

class BGSAcousticSpace : public TESBoundObject {
public:
	BGSAcousticSpace();
	~BGSAcousticSpace();

	enum TimeOfDay {
		DAWN	= 0,
		NOON	= 1,
		DUSK	= 2,
		NIGHT	= 3,
		COUNT	= 4
	};

	bool		bIsInterior;

	union {
		TESSound* pTimeOfDaySounds[TimeOfDay::COUNT];

		struct {
			TESSound* pDawnSound;
			TESSound* pNoonSound;
			TESSound* pDuskSound;
			TESSound* pNightSound;
		};
	};

	TESSound*	pWallaSound;
	TESRegion*	pRegion;
	uint32_t	eEnvironmentType;
	uint32_t	uiWallaTriggerCount;

	static BGSAcousticSpace* GetCurrentCellSpace();
	static void SetCurrentCellSpace(BGSAcousticSpace* apSpace);

	static BGSAcousticSpace* GetCurrentSpace();
	static void SetCurrentSpace(BGSAcousticSpace* apSpace);
	static void RemoveCurrentSpace(BGSAcousticSpace* apSpace);

	static BSSoundHandle* GetCurrentSound();
	static void SetCurrentSound(BSSoundHandle& arSound);

	static NiTMap<uint32_t, BSSoundHandle*>* GetPlayingLoopSounds();

	static TimeOfDay GetCurrentTimeOfDay();
	static void SetCurrentTimeOfDay(TimeOfDay aeTimeOfDay);

	static bool GetJustChanged();
	static void SetJustChanged(bool abJustChanged);

	static uint32_t GetTimeDelta();
	static void SetTimeDelta(uint32_t auiTimeDelta);

	static const char* GetTimeOfDayName(TimeOfDay aeTimeOfDay);

	TESSound* GetSoundForTime(float afTime) const;

private:
	static BGSAcousticSpace** const pCurrentSpace;
	static BGSAcousticSpace** const pCurrentCellSpace;
	static bool* const bJustChanged;
};

ASSERT_SIZE(BGSAcousticSpace, 0x54);