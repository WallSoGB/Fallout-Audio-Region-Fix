#pragma once

#include "BSSimpleList.hpp"
#include "NiColor.hpp"
#include "NiSmartPointer.hpp"

class Atmosphere;
class BSMultiBoundNode;
class Clouds;
class ImageSpaceModifierInstanceForm;
class Moon;
class NiNode;
class Precipitation;
class Stars;
class Sun;
class TESClimate;
class TESWeather;

class Sky {
public:
	Sky();
	virtual ~Sky();

	enum SkyObjectType {
		SOT_SUNGLARE = 0x1,
		SOT_CLOUDS = 0x3,
		SOT_STARS = 0x5,
		SOT_MOON = 0x7,
	};

	enum SkyColors {
		SC_SKY_UPPER	= 0,
		SC_FOG			= 1,
		SC_CLOUDS_LOWER = 2,
		SC_AMBIENT		= 3,
		SC_SUNLIGHT		= 4,
		SC_SUN			= 5,
		SC_STARS		= 6,
		SC_SKY_LOWER	= 7,
		SC_HORIZON		= 8,
		SC_CLOUDS_UPPER = 9,
		SC_COUNT,
	};

	struct SkySound {
		uint32_t		unk00;
		uint32_t		unk04;
		uint32_t		unk08;
		TESWeather*		pWeather;
		uint32_t		uiType;
		uint32_t		uiSoundID;
	};

	enum SKY_MODE {
		SM_NONE			= 0,
		SM_INTERIOR		= 1,
		SM_SKYDOME_ONLY = 2,
		SM_FULL			= 3,
	};

	struct COLOR_BLEND {
		uint32_t	uiRGBVal[4];
		float		fBlend[4];
	};

	NiPointer<BSMultiBoundNode>		spRoot;
	NiPointer<NiNode>				spMoonsRoot;
	TESClimate*						pCurrentClimate;
	TESWeather*						pCurrentWeather;
	TESWeather*						pLastWeather;
	TESWeather*						pDefaultWeather;
	TESWeather*						pOverrideWeather;
	Atmosphere*						pAtmosphere;
	Stars*							pStars;
	Sun*							pSun;
	Clouds*							pClouds;
	Moon*							pMasser;
	Moon*							pSecunda;
	Precipitation*					pPrecipitation;
	NiColor							kColors[SC_COUNT];
	NiColor							kColorUnkown0B4;
	NiColor							kColorSunFog;
	float							fWindSpeed;
	float							fWindAngle;
	float							fFogNearPlane;
	float							fFogFarPlane;
	uint32_t						unk0DC;
	uint32_t						unk0E0;
	uint32_t						unk0E4;
	float							fFogPower;
	float							fCurrentGameHour;
	float							fLastWeatherUpdate;
	float							fCurrentWeatherPct;
	SKY_MODE						eMode;
	BSSimpleList<SkySound>*			pSkySoundList;
	float							fFlash;
	uint32_t						uiFlashTime;
	uint32_t						uiLastMoonPhaseUpdate;
	float							fWindowReflectionTimer;
	float							fAccelBeginPct;
	uint32_t						unk114;
	Bitfield32						uiFlags;
	ImageSpaceModifierInstanceForm* pFadeInIMODCurrent;
	ImageSpaceModifierInstanceForm* pFadeOutIMODCurrent;
	ImageSpaceModifierInstanceForm* pFadeInIMODLast;
	ImageSpaceModifierInstanceForm* pFadeOutIMODLast;
	float							f12_0;
	float							f23_99;
	float							f0_0;

	__forceinline NiColor& GetSunLightColor()	{ return kColors[SC_SUNLIGHT]; }
	__forceinline NiColor& GetSunColor()		{ return kColors[SC_SUN]; }
	__forceinline NiColor& GetAmbientColor()	{ return kColors[SC_AMBIENT]; }
	__forceinline NiColor& GetSunFogColor()		{ return kColorSunFog; }
};

ASSERT_SIZE(Sky, 0x138);