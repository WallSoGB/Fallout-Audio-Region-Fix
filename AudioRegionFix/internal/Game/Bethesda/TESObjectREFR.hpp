#pragma once

#include "BSSoundHandle.hpp"
#include "TESBoundObject.hpp"
#include "TESChildCell.hpp"
#include "ExtraDataList.hpp"
#include "NiPoint3.hpp"
#include "NiSmartPointer.hpp"

class ExtraScript;
class ActorCause;
class ScriptLocals;
class TESContainer;
class TESSound;
class Animation;
class BipedAnim;
class NiGeometry;
class ExtraDroppedItemList;
class NiNode;
class BSFaceGenNiNode;
class BSFaceGenAnimationData;
class BSAnimNoteReceiver;
class TESWorldSpace;
class MagicCaster;
class MagicTarget;
class TrapEntry;
class TargetEntry;
class TESActorBase;
class TESObjectWEAP;
class TESTopic;
class bhkSimpleShapePhantom;
class Actor;

struct LoadedRefData;

struct ReferenceData {
	TESBoundObject* pObjectReference;
	NiPoint3		kRotation;
	NiPoint3		kPosition;
};

ASSERT_SIZE(ReferenceData, 0x1C);

enum SitSleepStates {
	NORMAL					= 0,
	LOAD_SIT_IDLE			= 1,
	WANT_TO_SIT				= 2,
	WAITING_FOR_SIT_ANIM	= 3,
	SITTING					= 4,
	WANT_TO_STAND			= 5,
	LOADING_SLEEP_IDLE		= 6,
	WANT_TO_SLEEP			= 7,
	WAITING_FOR_SLEEP_ANIM	= 8,
	SLEEPING				= 9,
	WANT_TO_WAKE			= 10,
};

class TESObjectREFR : public TESForm, public TESChildCell {
public:
	TESObjectREFR();
	virtual ~TESObjectREFR();

	virtual bool					GetStartingPosition(NiPoint3& arPos, NiPoint3& arRot, TESForm* apParentLocation, TESObjectCELL* apCell);
	virtual BSSoundHandle			VoiceSoundFunction(TESTopic* apTopic, Actor* apTarget, bool, bool, bool, bool, bool);
	virtual void					Unk_50();
	virtual void					DamageObject(float afDamage, bool abForce);
	virtual bool					GetCastShadows() const;
	virtual void					SetCastShadows();
	virtual bool					GetMotionBlur() const;
	virtual void					SetMotionBlur(bool abVal);
	virtual void					Unk_56();
	virtual bool					IsObstacle() const;
	virtual bool					IsQuestObject() const;
	virtual void					SetActorCause(ActorCause* apActorCause);
	virtual ActorCause*				GetActorCause();
	virtual NiPoint3*				GetStartingAngle(NiPoint3& arRot);
	virtual NiPoint3*				GetStartingLocation(NiPoint3& arPos);
	virtual void					SetStartingPosition(NiPoint3 akPos);
	virtual void					UpdateRefLight();
	virtual TESObjectREFR*			RemoveItem(TESBoundObject* apObject, ExtraDataList* apExtraList, uint32_t auiCount, bool, bool, TESObjectREFR* apDestRef, NiPoint3*, NiPoint3*, bool, bool);
	virtual void					RemoveItemType(uint32_t auiTypeID, bool, uint32_t auiCount);
	virtual bool					AddWornItem(TESBoundObject* apObject, uint32_t auiCount, ExtraDataList* apExtraList, bool unused = 0);
	virtual bool					RemoveWornItem(TESBoundObject* apObject, uint32_t auiCount, ExtraDataList* apExtraList);
	virtual void					DoTrap(TrapEntry*, TargetEntry*);
	virtual void					AddBoundObjectItem(TESBoundObject* apObject, ExtraDataList* apExtraList, uint32_t auiCount);
	virtual NiPoint3*				GetHeadPosition(NiPoint3& arPos);
	virtual MagicCaster*			GetMagicCaster() const;
	virtual MagicTarget*			GetMagicTarget() const;
	virtual bool					IsChild(bool abCheckHeight);
	virtual TESActorBase*			GetTemplateActorBase();
	virtual void					SetTemplateActorBase(TESActorBase* apBase);
	virtual NiNode*					GetFaceNodeBiped(NiNode* apNode = nullptr) const;
	virtual BSFaceGenNiNode*		GetFaceNodeSkinned(NiNode* apNode = nullptr) const;
	virtual BSFaceGenNiNode*		GetFaceNode(NiNode* apNode = nullptr) const;
	virtual BSFaceGenAnimationData* GetFaceAnimationData(NiNode* apNode = nullptr) const;
	virtual bool					ClampToGround();
	virtual bool					DetachHavok();
	virtual void					InitHavok();
	virtual NiNode*					Load3D(bool abBackgroundLoading);
	virtual void					Set3D(NiNode* apNode, bool abDebugPrint);
	virtual NiNode*					Get3D();
	virtual void					Unk_75();
	virtual NiPoint3				GetBoundMin() const;
	virtual NiPoint3				GetBoundMax() const;
	virtual void					UpdateAnimation();
	virtual Animation*				GetAnimation() const;
	virtual BipedAnim*				GetBiped() const;
	virtual BipedAnim*				CallGetBiped() const;
	virtual void					SetBiped(BipedAnim* apBiped);
	virtual NiPoint3*				GetPos() const;
	virtual void					Unk_7E(bool);
	virtual void					ResetHavokSimulation(bool abRecursive);
	virtual void					SetActionComplete(bool abVal);
	virtual void					Unk_81(bool);
	virtual void					ResetInventory(bool abLeveledOnly);
	virtual NiNode*					GetProjectileNode() const;
	virtual void					SetProjectileNode(NiNode* apNode);
	virtual uint32_t				DoGetSitSleepState() const;
	virtual bool					IsCharacter() const;
	virtual bool					IsCreature() const;
	virtual bool					IsExplosion() const;
	virtual bool					IsProjectile() const;
	virtual void					SetParentCell(TESObjectCELL* apCell);
	virtual bool					IsDead(bool abNotEssential) const;
	virtual bool					IsKnockedOut() const;
	virtual bool					IsParalyzed() const;
	virtual BSAnimNoteReceiver*		CreateExtraAnimNoteReceiver();
	virtual BSAnimNoteReceiver*		GetExtraDataAnimNoteReceiver();

	TESSound*		pLoopSound;
	ReferenceData	kData;
	float			fRefScale;
	TESObjectCELL*	pParentCell;
	ExtraDataList	kExtraList;
	LoadedRefData*	pLoadedData;

	TESObjectCELL* GetParentCell() const;

	TESBoundObject* GetObjectReference() const;

	float GetRadius();
};

ASSERT_SIZE(TESObjectREFR, 0x68);

struct LoadedRefData {
	TESObjectREFR*						pCurrentWaterType;
	uint32_t							iUnderwaterCount;
	float								fRelevantWaterHeight;
	float								fCachedRadius;
	Bitfield32							uiFlags;
	NiPointer<NiNode>					spNode;
	NiPointer<bhkSimpleShapePhantom>	spPhantom;
};

ASSERT_SIZE(LoadedRefData, 0x1C);