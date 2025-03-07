#pragma once

#include "BSSimpleList.hpp"
#include "BSSoundHandle.hpp"
#include "Character.hpp"
#include "NiTArray.hpp"
#include "NiTMap.hpp"
#include "TeleportPath.hpp"
#include "TESRegionList.hpp"

class AlchemyItem;
class BGSNote;
class BGSQuestObjective;
class bhkMouseSpringAction;
class CameraCaster;
class CombatGroup;
class DialoguePackage;
class ImageSpaceModifierInstanceDOF;
class ImageSpaceModifierInstanceDRB;
class MagicItem;
class MagicShaderHitEffect;
class MagicTarget;
class MusicMarker;
class QuestObjectiveTargets;
class TESCaravanCard;
class TESClass;
class TESEnchantableForm;
class TESObjectCELL;
class TESObjectREFR;
class TESObjectWEAP;
class TESQuest;
class TESReputation;
class TESTopic;
class TESWorldspace;
class Animation;
class BipedAnim;
class NiPointLight;
class TESRegion;
class TESRegionSound;
class NiNode;
class bhkRigidBody;

class PlayerCharacter : public Character {
public:
	PlayerCharacter();
	virtual ~PlayerCharacter();

	struct WobbleNodes
	{
		NiNode* pWobbleAnimNodes[12];
		NiNode* pWobbleAnimNodes2[12];
	};

	struct LevelManager {
		struct Data {
			bool		bShouldLevelUp;
			uint32_t	uiXPForNextLevel;
			bool		bIsChangingMaxXP;

			void Reset();
		};

		Data* pData;

		void Reset();
	};

	struct CompassTarget {
		CompassTarget() {};
		~CompassTarget() {};

		Actor*	pTarget			= nullptr;
		bool	bIsHostile		= false;
		bool	bIsUndetected	= false;
	};

	struct PositionRequest {
		TESWorldspace*	pWorldspace;
		TESObjectCELL*	pCell;
		NiPoint3		kPos;
		NiPoint3		kRot;
		bool			bResetWeather;
		void(__cdecl*	pfnCallbackFunc)(void*);
		void*			pCallbackFuncArg;
		TESObjectREFR*	pDestRef;
		TESObjectREFR*	pFastTravelRef;
	};

	struct FlyCamData {
		float		fRotX;
		float		fRotZ;
		NiPoint3	kPosition;
	};

	enum GrabMode {
		kGrabMode_ZKey = 0x1,
		kGrabMode_Telekenesis = 0x3,
	};

	// used to flag controls as disabled in disabledControlFlags
	enum {
		kControlFlag_Movement = 1 << 0,
		kControlFlag_Look = 1 << 1,
		kControlFlag_Pipboy = 1 << 2,
		kControlFlag_Fight = 1 << 3,
		kControlFlag_POVSwitch = 1 << 4,
		kControlFlag_RolloverText = 1 << 5,
		kControlFlag_Sneak = 1 << 6,
	};

	enum KillcamMode {
		kKillcamMode_None = 0x0,
		kKillcamMode_PlayerView = 0x1,
		kKillcamMode_Cinematic = 0x2,
	};

	virtual bool						Unk_139(int, int, int, int, int, int, int);
	virtual BSSimpleList<uint32_t*>*	GetPerkRanks(bool);

	uint32_t							unk1C8;
	uint32_t							unk1CC;
	uint32_t							unk1D0;
	uint32_t							unk1D4;
	uint32_t							unk1D8;
	uint32_t							unk1DC;
	uint32_t							unk1E0;
	uint32_t							unk1E4;
	uint32_t							unk1E8;
	PositionRequest*					pPositionRequest;
	TESObjectWEAP*						pWeap1F0;
	float								fTime1F4;
	uint8_t								byte1F8;
	uint32_t							sandmanDetectionValue;
	uint32_t							unk200;
	uint8_t								byte204;
	uint8_t								byte205;
	bool								bQuestTargetsNeedRecalculated;
	uint8_t								byte207;
	DialoguePackage*					pClosestConversation;
	bool								bIsPlayerMovingIntoNewSpace;
	BSSimpleList<void*>*				pActiveEffects;
	MagicItem*							pMagicItem214;
	MagicTarget*						pMagicTarget218;
	CameraCaster*						pCameraCaster;
	uint32_t							unk220;
	uint32_t							unk224;
	uint32_t							unk228;
	float								fTime22C;
	uint32_t							unk230;
	float								time234;
	BSSimpleList<MagicItem*>*			pConsumedPotions;
	BSSimpleList<TESEnchantableForm*>*  pQueuedEnchantments;
	bool								bShowQuestItems;
	uint8_t								byte241;
	uint8_t								byte242;
	uint8_t								byte243;
	float								fMagicModifiers[77];
	float								fPermAVMods[77];
	float								fHealthAV_4AC;
	float								fActorValues4B0[77];
	BSSimpleList<uint32_t>				kNotes;
	ImageSpaceModifierInstanceDOF*		pIronSightsDOFInstance;
	ImageSpaceModifierInstanceDOF*		pVATSDOFInstance;
	ImageSpaceModifierInstanceDRB*		pVATSDRBInstance;
	bool								bIsDetected;
	bool								bPreventRegionSoundUpdates;
	bool								byte5FA;
	bool								byte5FB;
	BSSimpleList<TESObjectREFR*>		kTeammates;
	TESObjectREFR*						pLastExteriorDoor;
	bool								bIsPlayingCombatAttackSound;
	void*								pActionList;
	BSSimpleList<uint32_t>*				pCasinoDataList;
	BSSimpleList<TESCaravanCard*>*		pCaravanCards1;
	BSSimpleList<TESCaravanCard*>*		pCaravanCards2;
	uint32_t							uiCaravanCapsEarned;
	uint32_t							uiCaravanCapsLost;
	uint32_t							uiNumCaravanWins;
	uint32_t							uiNumCaravanLosses;
	uint32_t							uiLargestCaravanWin;
	uint32_t							unk630;
	bhkMouseSpringAction*				pGrabSpringAction;
	TESObjectREFR*						pGrabbedRef;
	GrabMode							eGrabType;
	float								fCurrentGrabbedItemWeight;
	float								fGrabDistance;
	uint8_t								byte648;
	uint8_t								byte649;
	bool								bIs3rdPersonVisible;
	bool								bIs3rdPerson;
	bool								bThirdPerson;
	bool								bShouldRestoreFirstPersonAfterVanityMode;
	bool								bWasFirstPersonBeforeVanityCam;
	bool								bIsForceFirstPerson;
	bool								byte650;
	bool								bAlwaysRun;
	bool								bAutoMove;
	bool								byte653;
	uint32_t							uiSleepHours;
	bool								bIsResting;
	bool								byte659;
	bool								byte65A;
	bool								byte65B;
	float								unk65C;
	float								fTime660;
	float								fTime664;
	float								fUnused_time668;
	bool								bIsActorWithin_iSneakSkillUseDistance;
	uint8_t								flag66D;
	bool								bCanSleepWait;
	uint8_t								byte66F;
	float								fWorldFOV;
	float								f1stPersonFOV;
	float								fOverShoulderFOV;
	uint32_t							unk67C;
	Bitfield8							cControlFlags;
	bool								bIsWaitingForOpenContainerAnim;
	bool								byte682;
	bool								byte683;
	float								fWaitingForContainerOpenAnimPreventActivateTimer;
	TESObjectREFR*						pActivatedDoor;
	BipedAnim*							pBipedAnims1st;
	Animation*							pFirstPersonArms;
	NiPointer<NiNode>					spPlayerNode;
	float								fEyeHeight;
	NiNode*								pInventoryMenu;
	Animation*							pAnimData6A0;
	MagicShaderHitEffect*				pMagicShaderHitEffect;
	BSSimpleList<TESTopic*>				kTopics;
	BSSimpleList<uint32_t>				kList6B0;
	TESQuest*							pActiveQuest;
	BSSimpleList<uint32_t>				kQuestObjectiveList;
	BSSimpleList<uint32_t>				kQuestTargetList;
	bool								bPlayerGreetFlag;
	float								fPlayerGreetTimer;
	uint32_t							unk6D4;
	bool								bIsAMurderer;
	uint32_t							uiAmountSoldStolen;
	float								fSortActorDistanceListTimer;
	float								fSitHeadingDelta;
	uint8_t								byte6E8;
	uint8_t								byte6E9;
	uint8_t								byte6EA;
	uint8_t								byte6EB;
	MagicItem*							pSelectedSpell;
	TESObjectBOOK*						pSelectedScroll;
	TESObjectREFR*						pPlacedMarker;
	TeleportPath						kPlacedMarkerTarget;
	float								fTimeGrenadeHeld;
	uint32_t							unk734;
	uint32_t							unk738;
	TESClass*							pClass73C_unset;
	uint32_t							unk740;
	uint32_t							uiCrimeCounts[5];
	AlchemyItem*						pPoisonToApply;
	bool								bInCharGen;
	uint8_t								byte75D;
	uint8_t								bCanUseTelekinesis;
	uint8_t								byte75F;
	TESRegion*							pCurrentRegion;
	TESRegionList						kRegionsList;
	BSSimpleList<TESRegionSound*>		kRegionSounds;
	BSSoundHandle						kHeartBeatSound;
	void*								pTESSaveBuffer;
	uint32_t							iLastPlayingTimeUpdate;
	uint32_t							iTotalPlayingTime;
	uint32_t							unk794;
	bool								bIsInSleepPackage;
	bool								bIsTransitioningSeatedState;
	bool								bIsDrinkingPlacedWater;
	bool								bIsPackagePlaying;
	uint8_t								byte79C;
	bool								bIssueNearBorderRegionMsg;
	NiPoint3							kLastBorderRegionPosition;
	void*								pWorldOrCell;
	NiTPrimitiveArray<TESRegion*>*		pRegionArray;
	void*								pMusicType;
	uint32_t							uiGameDifficulty;
	bool								bIsHardcore;
	KillcamMode							eKillCamMode;
	bool								bInCombatWithGuard;
	bool								bIsYoung;
	bool								bIsToddler;
	bool								bCanUsePA;
	BSSimpleList<uint32_t>				kMapMarkers;
	void*								pWorldspaceForMapMarkerUpdates;
	BSSimpleList<MusicMarker*>			kMusicMarkers;
	MusicMarker*						pCurrMusicMarker;
	FlyCamData							kFlycamPos;
	uint32_t							unk7F4;
	BSSoundHandle						kMagicCastSound;
	BSSoundHandle						kMagicFailureSounds[6];
	BSSimpleList<TESObjectREFR*>		kDroppedRefList;
	NiTMap<uint32_t, uint8_t>			unk858;
	NiPointer<NiPointLight>				spThirdPersonLight;
	NiPointer<NiPointLight>				spFirstPersonLight;
	bool								bHasShownNoChargeWarning;
	float								fDropAngleMod;
	float								fLastDropAngleMod;
	LevelManager						kLevelManager;
	BSSimpleList<uint32_t>				kPerkRanksPC;
	BSSimpleList<uint32_t>				kPerkEntriesPC[74];
	BSSimpleList<uint32_t>				kPerkRanksTM;
	BSSimpleList<uint32_t>				kPerkEntriesTM[74];
	Actor*								pAutoAimActor;
	NiPoint3							kBulletAutoAim;
	NiPointer<NiNode>					spAutoAimNode;
	bool								bIsActorWithinInterfaceManagerPickDistance;
	Actor*								pReticleActor;
	BSSimpleList<CompassTarget*>*		pCompassTargets;
	float								fPipboyLightHeldTime;
	float								fAmmoSwapTimer;
	bool								bShouldOpenPipboy;
	char								byteD55;
	char								byteD56;
	char								byteD57;
	NiPoint3							kPtD58;
	CombatGroup*						pCombatGroup;
	uint32_t							uiTeammateCount;
	float								fCombatYieldTimer;
	float								fCombatYieldRetryTimer;
	WobbleNodes							kWobbleAnims;
	NiPoint3							kVectorDD4;
	NiPoint3							kCameraPos;
	bhkRigidBody*						pRigidBody;
	bool								bInCombat;
	bool								bUnseen;
	bool								bIsLODApocalypse;
	bool								byteDF3;
	BSSimpleArray<uint32_t>				kRockitLauncherContainer;
	float								fRockItLauncherWeight;
	bool								bHasNightVisionApplied;
	char								byteE09;
	char								byteE0A;
	char								byteE0B;
	TESReputation*						pModifiedReputation;
	int									unkE10;
	int									unkE14;
	float								fKillCamTimer;
	float								fKillCamCooldown;
	char								byteE20;
	char								bIsUsingTurbo;
	char								byteE22;
	char								byteE23;
	float								fLastHelloTime;
	float								fCounterAttackTimer;
	char								byteE2C;
	bool								bIsCateyeEnabled;
	bool								bIsSpottingImprovedActive;
	char								byteE2F;
	float								fItemDetectionTimer;
	NiNode*								pIronSightNode;
	bool								bNoHardcoreTracking;
	bool								bSkipHCNeedsUpdate;
	char								byteE3A;
	char								byteE3B;
	BSSimpleArray<uint32_t>				kHotkeyedWeaponAmmos;
	TESQuest*							pPatch04DebugQuest;

	static PlayerCharacter* GetSingleton();

	MusicMarker* GetCurrentMusicMarker();
};

ASSERT_OFFSET(PlayerCharacter, kFlycamPos, 0x7E0);
ASSERT_OFFSET(PlayerCharacter, fLastDropAngleMod, 0x874);
ASSERT_OFFSET(PlayerCharacter, fKillCamTimer, 0xE18);
ASSERT_SIZE(PlayerCharacter, 0xE50);