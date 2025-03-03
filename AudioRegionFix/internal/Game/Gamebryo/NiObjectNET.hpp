#pragma once

#include "NiObject.hpp"
#include "NiFixedString.hpp"

class NiTimeController;
class NiExtraData;

class NiObjectNET : public NiObject {
public:
	NiObjectNET();
	virtual ~NiObjectNET();

	enum CopyType {
		COPY_NONE	= 0,
		COPY_EXACT	= 1,
		COPY_UNIQUE = 2,
	};

	NiFixedString					m_kName;
	NiPointer<NiTimeController>		m_spControllers;
	NiExtraData**					m_ppkExtra;
	uint16_t						m_usExtraDataSize;
	uint16_t						m_usMaxSize;

	NIRTTI_ADDRESS(0x11F4304);

	const char* GetName() const { return m_kName.m_kHandle; };
	void SetName(const NiFixedString& arString) { m_kName = arString;	};

	NiTimeController* GetControllers() const { return m_spControllers; };
	NiTimeController* GetController(const NiRTTI* apRTTI) const;
	NiTimeController* GetController(const NiRTTI& arRTTI) const;
	template <class ControllerType>
	ControllerType* GetController() const {
		return (ControllerType*)GetController(ControllerType::ms_RTTI);
	}

	void RemoveController(NiTimeController* apController);

	NiExtraData* GetExtraData(const NiFixedString& arKey) const;
	bool AddExtraData(NiExtraData* apExtraData);
	bool AddExtraData(const NiFixedString& arKey, NiExtraData* apExtraData);
	bool RemoveExtraData(const NiFixedString& arKey);
	void DeleteExtraData(uint16_t ausIndex);

	static CopyType GetDefaultCopyType();
	static char GetDefaultAppendCharacter();
};

ASSERT_SIZE(NiObjectNET, 0x18);