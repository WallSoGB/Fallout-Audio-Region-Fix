#pragma once

#include "Actor.hpp"

class TESObjectARMO;
class BipedAnim;

class Character : public Actor {
public:
	Character();
	virtual ~Character();

	virtual void		InitiateCannibalPackage(Actor* apTarget);
	virtual void		Unk_138(void);

	BipedAnim*	pBipedAnim;
	float		fTotalArmorDR;
	float		fTotalArmorDT;
	uint8_t		bIsTrespassing;
	uint8_t		bIsGuard;
	float		fFlyInventoryWeight;
};

ASSERT_SIZE(Character, 0x1C8);