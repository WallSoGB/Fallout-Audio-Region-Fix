#pragma once

#include "NiAVObject.hpp"
#include "NiTPointerList.hpp"
#include "NiTPointerMap.hpp"

class BSGameSound;
class BSSoundHandle;
class BSSoundInfo;
class AudioLoadTask;
class BSAudioManagerThread;
class BSSoundMessage;
class TESSound;

class SoundMessageStack {
public:
	uint32_t		uiCount;
	bool			bBottomless;
	BSSoundMessage* pTop;
	uint32_t		uiTimeLastAllocated;
};

typedef NiTPointerList<BSSoundMessage*> SoundMessageList;

class BSAudioManager {
public:
	BSAudioManager();
	virtual ~BSAudioManager();

	struct UnkStruct {
		uint32_t uiFlags;
		uint16_t usState;
	};

	uint32_t								uiMessageListIndex;
	uint32_t								uiMessageProcessingListIndex;
	SoundMessageList						kMessages[2];
	SoundMessageStack						kFreeMessages;
	SoundMessageStack						kRequest034;
	SoundMessageStack						kGarbageMessages;
	NiTPointerMap<uint32_t, BSGameSound*>	kPlayingSounds;
	NiTPointerMap<uint32_t, BSSoundInfo*>	kPlayingSoundInfos1;
	NiTPointerMap<uint32_t, BSSoundInfo*>	kDebugSoundInfos;
	NiTPointerMap<uint32_t, NiAVObjectPtr>	kMovingObjects;
	NiTPointerList<BSGameSound*>			kCachedSounds;
	uint32_t								uiUsedCacheSize;
	uint32_t								unk0A4;
	float									fGameHour;
	CRITICAL_SECTION						kMessageCS;
	CRITICAL_SECTION						kDebugCS;
	CRITICAL_SECTION						kCacheListCS;
	CRITICAL_SECTION						kMessageProcessingCS;
	CRITICAL_SECTION						kTaskCS;
	NiTPointerList<AudioLoadTask*>			kTaskList;
	uint32_t								uiLastTickCount;
	bool									bInitedSounds;
	bool									byte135;
	uint32_t								uiThreadID;
	BSAudioManagerThread*					pUpdateThread;
	float									fVolumes[12];
	uint32_t								unk170;
	bool									byte174;
	bool									bIsPlayerUnderwater;
	UnkStruct*								pUnk178;
	uint32_t								uiSomeCount_17C; // Counter for 178
	uint32_t								uiSoundCacheIndex;
	bool									bIgnoreTimescale;
	bool									byte185;
	bool									byte186;
	bool									byte187;

	static BSAudioManager* GetSingleton();
};

ASSERT_SIZE(BSAudioManager, 0x188);