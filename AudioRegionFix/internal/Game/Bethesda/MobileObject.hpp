#pragma once

#include "TESObjectREFR.hpp"

class CFilter;
struct PackageLocation;
class TESTopic;
class DialogueResponse;
class BaseProcess;
class TESIdleForm;
class TESPackage;

class MobileObject : public TESObjectREFR {
public:
	MobileObject();
	virtual ~MobileObject();

	virtual bool			MoveToHigh();
	virtual bool			MoveToLow();
	virtual bool			MoveToMiddleLow();
	virtual bool			MoveToMiddleHigh();
	virtual void			Move(float afDeltaTime, NiPoint3& arDeltaMove, bool abDefer);
	virtual void			Jump();
	virtual void			Unk_96();
	virtual void			Process(float afDeltaTime);
	virtual void			ChangeProcessLevel();
	virtual void			UpdateActorInDialogue(float afTime, DialogueResponse* apResponse, bool);
	virtual void			UpdateAnimation2(float = 0);
	virtual bool			GetBufferedPackageEvaluation() const;
	virtual bool			Unk_9C();
	virtual bool			IsNPCInCombat(bool abNoSearch) const;
	virtual void			SetIsInDialogMenu(bool abInDialog);
	virtual void			Unk_9F();
	virtual bool			StartConversation(Actor* apTalkingActor, PackageLocation& arSubjectLocation, PackageLocation& arTargetLocation, bool abHeadTrack, bool abAllowMovement, bool a7, TESTopic* apTopic, bool a9, bool a10);
	virtual float			SpeakSoundFunction(char* apPath, BSSoundHandle* apSound, uint32_t aeEmotion, uint32_t aeEmotionValue, uint32_t auiResponseTextLength, TESIdleForm* apSpeakerAnimation, TESIdleForm* apListenerAnimation, Actor* apListener, bool a10, bool a11, bool a12, bool a13, bool a14);
	virtual void			EndDialogue();
	virtual void			SetRunOnceExtraPackage(TESPackage* apPackage, uint8_t aucDay);
	virtual bool			HasStartingWorldOrCellA3();
	virtual TESWorldSpace*	GetStartingWorldspace();
	virtual TESObjectCELL*	GetStartingCell();
	virtual NiPoint3*		GetStartingPos2(NiPoint3&);
	virtual bool			DetachCharController();
	virtual bool			RemoveCharController();
	virtual void			SetPosition(NiPoint3& arPosition);
	virtual void			GetVelocity(NiPoint3& arVelocity) const;
	virtual void			HandleRunDetection(float afDelta);
	virtual float			GetDetectionTimer() const;
	virtual void			DecreaseDetectionTimer();
	virtual float			GetHeading(bool arg1) const;
	virtual void			SetHeadingToRef(TESObjectREFR* apRef);
	virtual void			SetHeading(float afValue);
	virtual void			GetCurrentTarget();
	virtual bool			IsAtPoint(NiPoint3& arPoint, float afRadius, bool abExpandRadius, bool abAlwaysTestHeight);
	virtual uint32_t		GetEmotion() const;
	virtual void			SetEmotion(uint32_t);
	virtual uint32_t		GetEmotionValue() const;
	virtual void			SetEmotionValue(uint32_t);
	virtual void			SetSize(float afSize);
	virtual float			Unk_B9() const;
	virtual bool			IsDying() const;
	virtual bool			Unk_BB() const;
	virtual void			SetDisplayGeometry(bool abShow);
	virtual void			PutCreatedPackage(TESPackage* apPackage, bool abTempPackage, bool abIsaCreatedPackage);
	virtual void			Update(float afDelta);
	virtual void			ClearCombatData();
	virtual MobileObject*	Unk_C0(void*, MobileObject**);

	BaseProcess*	pCurrentProcess;
	TESObjectREFR*	pActivatorRef;
	MobileObject*	pCriminalRef;
	float			unk74;
	float			unk78;
	bool			bSpeakingDone;
	bool			bTalkingToPlayer;
	bool			bUnk7E;
	bool			bSoundFileDone;
	bool			bVoiceFileDone;
	bool			bTalkingThroughActivator;
	bool			bChangingProcess;
	bool			bDoNotRunSayToCallBack;
	uint8_t			ucSoundCallbackSet;
	bool			bSoundCallbackSuccess;
	Bitfield8		ucExtraInfoGeneralTopicDataElementFlags;
	bool			bIsLowLevelProcessing;
};

ASSERT_SIZE(MobileObject, 0x88);