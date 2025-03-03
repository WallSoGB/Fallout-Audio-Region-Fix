#pragma once

#include "TESForm.hpp"

class NiNode;
class NiAVObject;
class TESObjectREFR;
class TESBoundObject;
class TESWaterForm;
class TESObjectList;

class TESObject : public TESForm {
public:
	TESObject();
	virtual ~TESObject();

	virtual uint32_t		Unk_4E();
	virtual bool			IsBoundAnimObject() const;
	virtual TESWaterForm*	GetWaterType() const;
	virtual bool			IsAutoCalc() const;
	virtual void			SetAutoCalc(bool abVal);
	virtual NiNode*			Clone3D(TESObjectREFR* apRequester, bool abDeepCopy);
	virtual void			UnClone3D(TESObjectREFR* apRequester);
	virtual bool			IsMarker() const;
	virtual bool			IsOcclusionMarker() const;
	virtual void			Unk_57();
	virtual bool			ReplaceModel();
	virtual bool			GetAttachedMarkersVisible(NiAVObject*) const;
	virtual void			SetAttachedMarkersVisible(NiAVObject*, bool);
	virtual uint32_t		IncRef(); // GECK only
	virtual uint32_t		DecRef(); // GECK only
	virtual NiNode*			LoadGraphics(TESObjectREFR* apRef);

	TESObjectList*	pList;
	TESObject*		pPrev;
	TESObject*		pNext;

	TESObject* GetNext() const;
	TESObject* GetPrev() const;

	const char* GetModelFileName(TESObjectREFR* apRef = nullptr) const;
};

ASSERT_SIZE(TESObject, 0x24)