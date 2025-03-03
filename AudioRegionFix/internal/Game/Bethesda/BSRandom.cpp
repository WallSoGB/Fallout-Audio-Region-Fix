#include "BSRandom.hpp"

BSRandom* BSRandom::GetSingleton() {
	return (BSRandom*)0x11C4180;
}

uint32_t BSRandom::UnsignedIntBelow(uint32_t auiMax) {
	return ThisCall(0xAA5230, this, auiMax);
}

uint32_t BSRandom::UnsignedInt() {
	return UnsignedIntBelow(0xFFFFFFFF);
}

float BSRandom::GetRandomNumberBetween(float afMin, float afMax) {
	return (UnsignedInt() * (afMax - afMin) / 4294967296.0 + afMin);
}

bool BSRandom::IsRandomDecimalBelow(float afValue) {
	return CdeclCall<bool>(0x4DFF00, afValue);
}

uint32_t BSRandom::RandomUnsignedInt() {
	return GetSingleton()->UnsignedInt();
}
