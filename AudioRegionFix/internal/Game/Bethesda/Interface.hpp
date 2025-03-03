#pragma once

class FORenderedMenu;
class TESObjectREFR;

typedef void(*MessageBoxCallback)();

class Interface {
public:
	enum Emotion : uint32_t {
		NEUTRAL	= 0,
		HAPPY	= 1,
		SAD		= 2,
		PAIN	= 3,
	};

	enum Menus {
		Console = 0x3,
		Message = 0x3E9,
		Inventory = 0x3EA,
		Stats = 0x3EB,
		HUDMainMenu = 0x3EC,
		Loading = 0x3EF,
		Container = 0x3F0,
		Dialog = 0x3F1,
		SleepWait = 0x3F4,
		Pause = 0x3F5,
		LockPick = 0x3F6,
		Quantity = 0x3F8,
		PipboyData = 0x3FF,
		LevelUp = 0x403,
		PipboyRepair = 0x40B,
		SurgeryMenu = 0x40C,
		Credits = 0x417,
		CharGen = 0x418,
		TextEdit = 0x41B,
		Barter = 0x41D,
		Surgery = 0x41E,
		Hacking = 0x41F,
		VATS = 0x420,
		Computers = 0x421,
		VendorRepair = 0x422,
		Tutorial = 0x423,
		SPECIALBook = 0x424,
		ItemModMenu = 0x425,
		LoveTester = 0x432,
		CompanionWheel = 0x433,
		MedicalQuestionnaire = 0x434,
		Recipe = 0x435,
		SlotMachine = 0x438,
		BlackJack = 0x439,
		Roulette = 0x43A,
		Caravan = 0x43B,
		Traits = 0x43C,
		VideoMenu = 0x3FA,
		GamePlayMenu = 0x3FC,
		BookMenu = 0x402,
		AudioMenu = 0x3F9,
	};

	static bool IsTopMenuID(Menus aeMenu);
	static bool ShowNotify(const char* apText, Emotion aeEmotion, const char* apImagePath, const char* apSoundName, float afTime, bool abInstant);
};