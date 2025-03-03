#include "TES.hpp"

TES* TES::GetSingleton() {
	return *(TES**)0x11DEA10;
}

Sky* TES::GetSky() {
	return pSky;
}

// GAME - 0x70EC90
TESWaterSystem* TES::GetWaterManger() const {
    return pWaterManager;
}

// GAME - 0x4FD3E0
TESWorldSpace* TES::GetWorldSpace() const {
	return pWorldSpace;
}

// GAME - 0x5F36F0
TESObjectCELL* TES::GetInterior() const {
	return pInteriorCell;
}

// GAME - 0x455690
void TES::HandleCellLoopingSounds() {
	ThisCall(0x455690, this);
}