#pragma once

class TESRegion;

enum RegionDataID {
	REGION_DATA_NONE			= 0,
	REGION_DATA_GENERAL_ID		= 1,
	REGION_DATA_OBJECTS_ID		= 2,
	REGION_DATA_WEATHER_ID		= 3,
	REGION_DATA_MAP_ID			= 4,
	REGION_DATA_LANDSCAPE_ID	= 5,
	REGION_DATA_GRASS_ID		= 6,
	REGION_DATA_SOUND_ID		= 7,
	REGION_DATA_IMPOSTER		= 8,
	REGION_DATA_COUNT			= 9,
};

struct RegionData {
	RegionDataID	eDataTypeID;
	bool			bOverride;
	uint8_t			cPriority;
};

class TESRegionData {
public:
	TESRegionData();
	virtual					~TESRegionData();
	virtual void			Save();
	virtual bool			LoadRegionData(RegionData* apData);
	virtual void			Initialize(TESRegion* apRegion);
	virtual RegionDataID	GetID() const;
	virtual TESRegionData*	Copy();
	virtual TESRegionData*	Blend(TESRegionData* apRegionData);
	virtual void			BlendInto(TESRegionData* apRegionData, uint32_t auiTotalBlending);
	virtual bool			Validate() const;

	bool	bOverride;
	bool	bIgnore;
	uint8_t	cPriority;
};

ASSERT_SIZE(TESRegionData, 0x8)