#pragma once

template <typename T>
class BSStringT {
public:
	BSStringT() {};
	~BSStringT();

	T*			pString = nullptr;
	uint16_t	sLen	= 0;
	uint16_t	sMaxLen = 0;

	inline const T* c_str() const {
		return pString;
	}
};

typedef BSStringT<char>		BSString;
typedef BSStringT<wchar_t>	BSWideString;