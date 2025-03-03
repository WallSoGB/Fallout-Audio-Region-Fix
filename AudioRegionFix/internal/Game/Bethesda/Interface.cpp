#include "Interface.hpp"

// GAME - 0x702450
bool Interface::IsTopMenuID(Menus aeMenu) {
	return CdeclCall<bool>(0x702450, aeMenu);
}

// GAME - 0x7052F0
bool Interface::ShowNotify(const char* apText, Emotion aeEmotion, const char* apImagePath, const char* apSoundName, float afTime, bool abInstant) {
	return CdeclCall<bool>(0x7052F0, apText, aeEmotion, apImagePath, apSoundName, afTime, abInstant);
}