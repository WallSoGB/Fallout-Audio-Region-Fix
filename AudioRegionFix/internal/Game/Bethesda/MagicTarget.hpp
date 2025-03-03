#pragma once

#include "BSSimpleList.hpp"

class Actor;
class TESBoundObject;
class TESObjectREFR;
class EffectItem;
class ActiveEffect;
class MagicCaster;
class MagicItem;

typedef BSSimpleList<ActiveEffect*> EffectList;

class MagicTarget {
public:
	MagicTarget();
	virtual bool		AddTarget(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool);
	virtual Actor*		GetTargetAsActor() const;
	virtual EffectList* GetActiveEffectList() const;
	virtual bool		MagicTargetIsActor() const;
	virtual bool		IsInvulnerable() const;
	virtual void		EffectAdded(ActiveEffect* apEffect);
	virtual void		EffectRemoved(ActiveEffect* apEffect);
	virtual void		EffectAbsorbed(MagicCaster* apCaster, ActiveEffect* apEffect);
	virtual void		EffectReflected(MagicCaster* apCaster, ActiveEffect* apEffect);
	virtual float		CheckResistance(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);
	virtual bool		CheckAbsorb(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect, bool);
	virtual bool		CheckReflect(MagicCaster* apCaster, MagicItem* apItem, ActiveEffect* apEffect);


	struct SpellDispelData {
		MagicItem*		pSpell;
		MagicCaster*	pCaster;
		ActiveEffect*	pActiveEffect;
	};

	bool							byt004;
	bool							bUpdating;
	BSSimpleList<SpellDispelData*>	kPostUpdateDispelList;
};

ASSERT_SIZE(MagicTarget, 0x010);