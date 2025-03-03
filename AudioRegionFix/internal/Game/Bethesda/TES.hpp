#pragma once

#include "BSSimpleList.hpp"
#include "BSString.hpp"
#include "NiPoint3.hpp"
#include "NiSmartPointer.hpp"

class BSTempNodeManager;
class GridCellArray;
class GridDistantArray;
class ImageSpaceModifierInstance;
class LoadedAreaBound;
class NavMeshInfoMap;
class NiDirectionalLight;
class NiFogProperty;
class NiSourceTexture;
class QueuedFile;
class Sky;
class TESActorBase;
class TESObjectCELL;
class TESObjectREFR;
class TESWaterSystem;
class TESWorldSpace;
class bhkPickData;
class NiNode;

class TES {
public:
	virtual bool GetMapNameForLocation(BSString& arName, NiPoint3 akLocation, TESWorldSpace* apWorldSpace) const;

	struct DeathCount {
		TESActorBase*	pActor;
		uint16_t		uiCount;
	};

	GridDistantArray*									pGridDistantArray;
	GridCellArray*										pGridCellArray;
	NiNode*												pObjRoot;
	NiNode*												pLODRoot;
	NiNode*												pObjLODWaterRoot;
	BSTempNodeManager*									pTempNodeManager;
	NiDirectionalLight*									pObjLight;
	NiFogProperty*										pObjFog;
	int32_t												iCurrentGridX;
	int32_t												iCurrentGridY;
	int32_t												iCurrentQueuedX;
	int32_t												iCurrentQueuedY;
	TESObjectCELL*										pInteriorCell;
	TESObjectCELL**										pInteriorBuffer;
	TESObjectCELL**										pExteriorBuffer;
	uint32_t											uiTempInteriorBufferSize;
	uint32_t											uiTempExteriorBufferSize;
	int32_t												iSaveGridX;
	int32_t												iSaveGridY;
	uint8_t												byte50;
	bool												bRunningCellTests;
	uint8_t												bRunningCellTests2;
	uint8_t												gap53;
	uint32_t											renderTestCellsCallback;
	uint32_t											unk58;
	uint32_t											unk5C;
	bool												bShowLandBorders;
	TESWaterSystem*										pWaterManager;
	Sky*												pSky;
	BSSimpleList<NiPointer<ImageSpaceModifierInstance>> kActiveImageSpaceModifiers;
	uint32_t											unk74;
	uint32_t											unk78;
	uint8_t												byte7C;
	uint8_t												byte7D;
	uint8_t												gap7E;
	uint8_t												gap7F;
	float												fCell_delta_x;
	float												fCell_delta_y;
	TESWorldSpace*										pWorldSpace;
	uint32_t*											list8C[2];
	BSSimpleList<TESObjectREFR*>						cellFurnitureList;
	BSSimpleList<DeathCount*>							deathCounts;
	NiPointer<QueuedFile>								spQueuedFileA4;
	NiPointer<NiSourceTexture>							spBloodDecalPreload1;
	NiPointer<QueuedFile>								spQueuedFileAC;
	void*												pParticleCacheHead;
	bool												bFadeWhenLoading;
	bool												bAllowUnusedPurge;
	uint8_t												byteB6;
	uint8_t												byteB7;
	uint32_t											iPlaceableWaterCount;
	NavMeshInfoMap*										pNavMeshInfoMap;
	NiPointer<LoadedAreaBound>							spLoadedAreaBound;

	static TES* GetSingleton();

	Sky* GetSky();

	TESWaterSystem* GetWaterManger() const;

	TESWorldSpace* GetWorldSpace() const;

	TESObjectCELL* GetInterior() const;
	void HandleCellLoopingSounds();
};

ASSERT_SIZE(TES, 0xC4);

extern TES* g_TES;