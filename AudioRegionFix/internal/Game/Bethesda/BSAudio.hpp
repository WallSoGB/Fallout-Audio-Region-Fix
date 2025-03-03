#pragma once

#include "BSWin32AudioListener.hpp"

class TESSound;
class BSGameSound;

struct AudioTick {
	uint32_t uiDelta;
	uint32_t uiLastTick;
	uint32_t uiFlags;
};


class BSAudio {
public:
	BSAudio();
	virtual					~BSAudio();
	virtual void			Init(HWND* apWindow);
	virtual void			Shutdown();
	virtual void			Unk_03(int);	// Stub
	virtual uint32_t		Unk_04();		// Stub
	virtual BSGameSound*	GetGameSound(const char* apPath);
	virtual void			PrependDataSoundPath(char* apFilename);
	virtual void 			Unk_07();		// Stub

	bool					bReady;
	bool					bIsInitialized;
	bool					bIsMultithreaded;
	DWORD					dword8;
	BYTE					byteC;
	BSWin32AudioListener*	pListener;
	AudioTick				kTimePassed;
	bool(__cdecl*			GetSoundDataFromFormID)(uint32_t auiFormID, const char* apOutFilePath, uint32_t& arFlags, TESSound*& arSound);
	bool(__cdecl*			GetSoundDataFromEDID)(const char* apEDID, const char* apOutFilePath, uint32_t& arFlags, TESSound*& arSound);
	bool(__cdecl*			PickSoundFileFromFolder)(const char* apOutFilePath);
	uint32_t(__cdecl*		FillGameSoundProps)(uint32_t* mapKey, TESSound* soundForm, uint32_t* outFlags0C);
	void (*					sub_832C40)(void);
	void (*					sub_832C80)(void);
};

ASSERT_SIZE(BSAudio, 0x38);