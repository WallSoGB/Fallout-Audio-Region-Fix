#include "nvse/PluginAPI.h"
#include "TESSound.hpp"
#include "BGSAcousticSpace.hpp"
#include "PlayerCharacter.hpp"
#include "BSMemory.hpp"

BS_ALLOCATORS

EXTERN_DLL_EXPORT bool NVSEPlugin_Query(const NVSEInterface* nvse, PluginInfo* info) {
	info->infoVersion = PluginInfo::kInfoVersion;
	info->name = "Audio Region Fix";
	info->version = 131;

	return !nvse->isEditor;
}


void __cdecl BGSAcousticSpace__SetCurrentCellSpace(BGSAcousticSpace* apSpace) {
	BGSAcousticSpace::SetCurrentCellSpace(apSpace);
	BGSAcousticSpace::SetJustChanged(true);
}

EXTERN_DLL_EXPORT bool NVSEPlugin_Load(NVSEInterface* nvse) {
	if (!nvse->isEditor) {
		ReplaceCall(0x86FB56, BGSAcousticSpace__SetCurrentCellSpace);
		WriteRelJump(0x82D7C0, TESSound::UpdateRegionSounds);
		WriteRelJump(0x82EAE0, BGSAcousticSpace::SetCurrentSpace);
		WriteRelJumpEx(0x969930, &PlayerCharacter::GetCurrentMusicMarker);
	}

	return true;
}

BOOL WINAPI DllMain(
	HANDLE  hDllHandle,
	DWORD   dwReason,
	LPVOID  lpreserved
)
{
	return TRUE;
}