#pragma once

class BSRandom {
public:
	DWORD	dword0;
	DWORD	dword4;
	int		unk8[624];
	DWORD	iter;

	static BSRandom* GetSingleton();

	uint32_t UnsignedIntBelow(uint32_t auiMax);

	uint32_t UnsignedInt();

	float GetRandomNumberBetween(float afMin, float afMax);

	static bool IsRandomDecimalBelow(float afValue);

	static uint32_t RandomUnsignedInt();
};
