#pragma once

#include "BSAudio.hpp"
#include <dsound.h>

class BSSoundHandle;

class BSWin32Audio : public BSAudio {
public:
	BSWin32Audio();
	virtual ~BSWin32Audio();
	
	struct BufferCaps : public DSBCAPS {
		uint32_t	unk054;
		uint32_t	unk058;
		uint32_t	unk05C;
		BOOL		bUseHRTF;
		uint32_t	unk064;
		uint32_t	unk068;
		uint32_t	unk06C;
		uint32_t	unk070;
		uint32_t	unk074;
		uint32_t	unk078;
		uint32_t	unk07C;
		uint32_t	unk080;
		uint32_t	unk084;
		uint32_t	unk088;
		uint32_t	unk08C;
		uint32_t	unk090;
		uint32_t	unk094;
		uint32_t	unk098;
		uint32_t	unk09C;
	};


	LPDIRECTSOUND8			pDirectSound8;
	LPDIRECTSOUNDBUFFER8	pDirectSoundBuffer;
	BufferCaps				dsbCaps;
	HWND					hWindow;

	static BSWin32Audio* GetSingleton();

	void SetEnvironmentType(uint32_t aeType);

	BSSoundHandle GetSoundHandleByFormID(uint32_t auiFormID, uint32_t auiCreationFlags);
	BSSoundHandle GetSoundHandleByEditorName(const char* apEditorID, uint32_t auiCreationFlags);
	BSSoundHandle GetSoundHandleByFilePath(const char* apPath, uint32_t auiCreationFlags, TESSound* apSound);

	void PrecacheSound(const char* apPath, uint32_t aeFlags, TESSound* apSound);

	void SetGameHour(float afHour);

	uint32_t GetTimeDelta() const;
};

ASSERT_SIZE(BSWin32Audio, 0xA4);
ASSERT_SIZE(BSWin32Audio::BufferCaps, 0x60);