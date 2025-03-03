#pragma once

#include "BSSimpleList.hpp"
#include "TESRegionData.hpp"

class TESRegionDataList : public BSSimpleList<TESRegionData*> {
public:
	bool bOwnsDataMemory;

	TESRegionData* Find(RegionDataID aeID) const;
};

ASSERT_SIZE(TESRegionDataList, 0xC);