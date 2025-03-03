#pragma once

#include "TESForm.hpp"
#include "NiColor.hpp"

class TESWeather;
class TESWorldSpace;
class NiPoint2;
class TESRegionDataList;

class TESRegion : public TESForm {
public:
	TESRegion();
	virtual ~TESRegion();

	struct RegionAreaEntry {
		BSSimpleList<NiPoint2*>	kPoints;
		uint32_t				unk08[2];
		float					unk10[4];
		uint32_t				edgeFallOff;
		uint32_t				uiPointCount;
	};

	TESRegionDataList*				pDataEntries;
	BSSimpleList<RegionAreaEntry*>*	pAreaEntries;
	TESWorldSpace*					pWorldSpace;
	TESWeather*						pWeather;
	float							fUnk28;
	NiColor							kExternalEmittance;
};

ASSERT_SIZE(TESRegion, 0x38);