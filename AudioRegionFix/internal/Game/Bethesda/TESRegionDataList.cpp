#include "TESRegionDataList.hpp"

// GAME - 0x4F35B0
TESRegionData* TESRegionDataList::Find(RegionDataID aeID) const {
	return ThisCall<TESRegionData*>(0x4F35B0, this, aeID);
}
