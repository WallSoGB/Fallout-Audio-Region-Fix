#pragma once

#include "BaseFormComponent.hpp"
#include "TESTextureList.hpp"
#include "BSString.hpp"

class TESFile;
class TESModelTextureSwap;

class TESModel : public BaseFormComponent {
public:
	TESModel();
	virtual							~TESModel();
	virtual const char*				GetModel();
	virtual void					SetModel(const char* apcPath);
	virtual TESModelTextureSwap*	GetAsModelMaterialSwap() const;

	enum FacegenFlags {
		HEAD			= 1 << 0,
		TORSO			= 1 << 1,
		RIGHT_HAND		= 1 << 2,
		LEFT_HAND		= 1 << 3,
	};

	BSString		strModel;
	TESTextureList	kTextures;
	Bitfield8		ucFaceGenFlags;
};

ASSERT_SIZE(TESModel, 0x18);