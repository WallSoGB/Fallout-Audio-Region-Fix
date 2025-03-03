#include "TESObjectREFR.hpp"

// GAME - 0x8D6F30
TESObjectCELL* TESObjectREFR::GetParentCell() const {
	return pParentCell;
}

// GAME - 0x7AF430
TESBoundObject* TESObjectREFR::GetObjectReference() const {
	return kData.pObjectReference;
}