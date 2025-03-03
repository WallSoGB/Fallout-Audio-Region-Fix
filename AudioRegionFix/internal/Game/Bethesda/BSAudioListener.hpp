#pragma once

#include "NiPoint3.hpp"

class BSAudioListener {
public:
	BSAudioListener();
	virtual				~BSAudioListener();
	virtual void		Unk_01();
	virtual void		SetPosition(NiPoint3& arPos);
	virtual NiPoint3*	GetPosition() const;
	virtual void		UpdatePositionAndOrientation();
	virtual void		SetFrontAndTopOrientation(NiPoint3& arTop, NiPoint3& arFront);
	virtual uint32_t	GetUnk10();
	virtual uint32_t	GetUnk1C();
	virtual void		SetVelocity(NiPoint3& arVelocity);
	virtual void		SetFlt040(float);
	virtual void		SetEnvironmentType(uint32_t aeType);
	virtual uint32_t	GetEnvironmentType() const;
	virtual void		SetRolloffFactor(float afValue);

	NiPoint3	kOriginWorldPos;
	uint32_t	unk10;
	uint32_t	unk14;
	uint32_t	unk18;
	uint32_t	unk1C;
	uint32_t	unk20;
	uint32_t	unk24;
	NiPoint3	kVelocity;
	uint32_t	sysTime;
	float		flt38;
	float		fRollOffFactor;
	float		flt40;
	uint32_t	uiEnvironmentType;
};

ASSERT_SIZE(BSAudioListener, 0x48)