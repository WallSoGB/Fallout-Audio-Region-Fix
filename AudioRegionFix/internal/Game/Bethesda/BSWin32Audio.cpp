#include "BSWin32Audio.hpp"
#include "BSSoundHandle.hpp"

// GAME - 0x453A70
BSWin32Audio* BSWin32Audio::GetSingleton() {
	return *(BSWin32Audio**)0x11F6D98;
}

// GAME - 0xAD79B0
void BSWin32Audio::SetEnvironmentType(uint32_t aeType) {
	ThisCall(0xAD79B0, this, aeType);
}

// GAME - 0xAD73B0
BSSoundHandle BSWin32Audio::GetSoundHandleByFormID(uint32_t auiFormID, uint32_t auiCreationFlags) {
	BSSoundHandle kHandle;
	ThisCall(0xAD73B0, this, &kHandle, auiFormID, auiCreationFlags);
	return kHandle;
}

// GAME - 0xAD7550
BSSoundHandle BSWin32Audio::GetSoundHandleByEditorName(const char* apEditorID, uint32_t auiCreationFlags) {
	BSSoundHandle kHandle;
	ThisCall(0xAD7550, this, &kHandle, apEditorID, auiCreationFlags);
	return kHandle;
}

// GAME - 0xAD7480
BSSoundHandle BSWin32Audio::GetSoundHandleByFilePath(const char* apPath, uint32_t auiCreationFlags, TESSound* apSound) {
	BSSoundHandle kHandle;
	ThisCall(0xAD7480, this, &kHandle, apPath, auiCreationFlags, apSound);
	return kHandle;
}

// GAME - 0xAD8100
void BSWin32Audio::PrecacheSound(const char* apPath, uint32_t aeFlags, TESSound* apSound) {
	ThisCall(0xAD8100, this, apPath, aeFlags, apSound);
}

// GAME - 0xAD77F0
void BSWin32Audio::SetGameHour(float afHour, int32_t aiUnk) {
	ThisCall(0xAD77F0, this, afHour, aiUnk);
}

// GAME - 0x63D040
uint32_t BSWin32Audio::GetTimeDelta() const {
	return kTimePassed.uiDelta;
}
