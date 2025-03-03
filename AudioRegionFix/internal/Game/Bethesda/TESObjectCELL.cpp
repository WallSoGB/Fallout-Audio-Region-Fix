#include "TESObjectCELL.hpp"

// GAME - 0x54DDD0
TESWorldSpace* TESObjectCELL::GetWorldSpace() const {
    return IsInterior() ? nullptr : pWorldSpace;
}

// GAME - 0x547590
BGSAcousticSpace* TESObjectCELL::GetAcousticSpace() const {
	return ThisCall<BGSAcousticSpace*>(0x547590, this);
}