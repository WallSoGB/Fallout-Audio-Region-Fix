#pragma once

#include "BSMemory.hpp"

template <typename T_Data>
class BSSimpleArray {
public:
	BSSimpleArray() { InitialSetup(0, 0); }
	BSSimpleArray(uint32_t auiSize) { InitialSetup(auiSize, auiSize); }
	BSSimpleArray(const BSSimpleArray&) = delete;
	BSSimpleArray& operator=(const BSSimpleArray&) = delete;

	virtual			~BSSimpleArray() { Clear(); };
	virtual T_Data* Allocate(uint32_t auiCount) { return BSNew<T_Data>(auiCount); };
	virtual void    Deallocate(T_Data* apData) { BSFree(apData); };
	virtual T_Data* Reallocate(T_Data* apData, uint32_t auiCount) { return (T_Data*)BSReallocate(apData, sizeof(T_Data) * auiCount); };

	T_Data*		pBuffer;
	uint32_t	uiSize;
	uint32_t	uiAllocSize;

	uint32_t GetSize() const { return uiSize; }
	uint32_t GetAllocSize() const { return uiAllocSize; }
	bool IsEmpty() const { return uiSize == 0; }
	bool IsFull() const { return uiSize == uiAllocSize; }
	T_Data& GetAt(const uint32_t idx) const { return pBuffer[idx]; }
	T_Data& GetLast() { return pBuffer[uiSize - 1]; }

	class Iterator {
	public:
		Iterator(T_Data* node) : m_node(node) {}

		T_Data* operator*() { return m_node; }
		const T_Data* operator*() const { return m_node; }

		Iterator& operator++() {
			m_node++;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return m_node != other.m_node;
		}

	private:
		T_Data* m_node;
	};

	Iterator begin() { return Iterator(&GetAt(0)); }
	Iterator end() { return Iterator(&GetLast()); }

	template <typename FUNC, typename... ARGS>
	void ForEach(FUNC&& func, ARGS... args) {
		for (uint32_t i = 0; i < uiSize; i++)
			func(GetAt(i), args...);
	}

	// 0x822780
	void ConstructItems(T_Data* apData, uint32_t auiCount) {
		for (uint32_t i = 0; i < auiCount; i++)
			new (&apData[i]) T_Data;
	}

	// 0x822820
	void DestructItems(T_Data* apData, uint32_t auiCount) {
		for (uint32_t i = 0; i < auiCount; ++i)
			apData[i].~T_Data();
	}

	void InitialSetup(uint32_t auiSize, uint32_t auiAllocSize) {
		pBuffer = nullptr;
		uiSize = 0;
		uiAllocSize = 0;
		if (auiSize > auiAllocSize)
			auiAllocSize = auiSize;

		if (auiAllocSize) {
			pBuffer = Allocate(auiAllocSize);
			uiAllocSize = auiAllocSize;
		}

		if (auiAllocSize) {
			ConstructItems(pBuffer, auiAllocSize);
			uiSize = auiAllocSize;
		}
	}

	// 0x6A8500
	void FreeArray() {
		Deallocate(pBuffer);
		pBuffer = nullptr;
	}

	// 0x6C6200
	void Clear(bool abFree = true) {
		if (!pBuffer)
			return;

		DestructItems(pBuffer, uiSize);

		if (abFree) {
			FreeArray();
			pBuffer = nullptr;
			uiAllocSize = 0;
		}

		uiSize = 0;
	}

	void CopyItems(T_Data* apNewBuffer, T_Data* apOldBuffer, uint32_t auiSize) {
		if (!auiSize)
			return;

		if (apNewBuffer >= apOldBuffer) {
			if (apNewBuffer > apOldBuffer) {
				for (uint32_t i = auiSize - 1; i >= 0; --i)
					memcpy(&apNewBuffer[i], &apOldBuffer[i], sizeof(T_Data));
			}
		}
		else {
			for (uint32_t j = 0; j < auiSize; ++j)
				memcpy(&apNewBuffer[j], &apOldBuffer[j], sizeof(T_Data));
		}
	}

	// 0x42FC00
	void Resize(uint32_t auiNewSize, uint32_t auiSize) {
		if (!pBuffer) {
			pBuffer = Allocate(auiNewSize);
			uiAllocSize = auiNewSize;
		}
		else if (auiSize == uiAllocSize) {
			pBuffer = Reallocate(pBuffer, auiNewSize);
		}
		else {
			T_Data* pNewBuffer = Allocate(auiNewSize);
			CopyItems(pNewBuffer, pBuffer, auiSize);
			FreeArray();
			pBuffer = pNewBuffer;
		}
	}

	// 0x695230
	void SetSize(uint32_t auiSize, bool abFree = true) {
		if (!auiSize) {
			Clear(abFree);
			return;
		}

		if (auiSize > uiAllocSize) {
			if (uiAllocSize)
				Resize(auiSize, uiSize);
			else
				pBuffer = Allocate(auiSize);

			uiAllocSize = auiSize;
			ConstructItems(&pBuffer[uiSize], auiSize - uiSize);
		}
		else if (auiSize >= uiSize) {
			ConstructItems(&pBuffer[uiSize], auiSize - uiSize);
		}
		else {
			DestructItems(&pBuffer[auiSize], uiSize - auiSize);

			if (abFree && auiSize <= uiAllocSize >> 2) {
				Resize(auiSize, auiSize);
				uiAllocSize = auiSize;
			}
		}
		uiSize = auiSize;
	}

	// 0x6F9790
	void SetAllocSize(uint32_t auiAllocSize) {
		if (auiAllocSize == uiAllocSize)
			return;

		if (auiAllocSize < uiSize) {
			uiSize = auiAllocSize;
		}
		Resize(auiAllocSize, uiSize);
		uiAllocSize = auiAllocSize;
	}

	// 0x9A3910
	uint32_t GetResizeSize() {
		if (uiAllocSize <= 1024)
			return 2 * uiAllocSize;
		else
			return uiAllocSize + 1024;
	}

	// GAME - 0x761540
	uint32_t GetNextIndex() {
		if (!IsFull())
			return uiSize++;

		if (uiAllocSize) {
			uint32_t a2 = GetResizeSize();
			Resize(a2, uiSize);
			uiAllocSize = a2;
		}
		else {
			pBuffer = Allocate(4);
			uiAllocSize = 4;
		}

		return uiSize++;
	}

	// GAME - 0xB5C360
	uint32_t GetCurrentIndex() {
		if (!IsFull())
			return uiSize++;

		if (!uiAllocSize) {
			pBuffer = Allocate(4);
			uiSize++;
			uiAllocSize = 4;
			return uiSize - 1;
		}

		uint32_t uiResizeSize = GetResizeSize();
		Resize(uiResizeSize, uiSize);
		uiAllocSize = uiResizeSize;
		return uiSize++;
	}

	// GAME - 0x7CB2E0
	uint32_t Add(const T_Data& aItem) {
		uint32_t uiNext = GetNextIndex();
		ConstructItems(&pBuffer[uiNext], 1);
		pBuffer[uiNext] = aItem;
		return uiNext;
	}

	void SetAt(uint32_t auiIndex, const T_Data& aItem) {
		if (auiIndex == uiSize) {
			pBuffer[GetNextIndex()] = aItem;
			return;
		}

		if (auiIndex != uiAllocSize) {
			CopyItems(pBuffer[auiIndex + 1], pBuffer[auiIndex], uiSize - auiIndex);
		}
		else {
			uint32_t uiResizeSize = GetResizeSize();
			T_Data* pNewBuffer = Allocate(uiResizeSize);
			CopyItems(pNewBuffer, pBuffer, auiIndex);
			CopyItems(&pNewBuffer[auiIndex + 1], &pBuffer[auiIndex], uiSize - auiIndex);
			Deallocate(pBuffer);
			pBuffer = pNewBuffer;
			uiAllocSize = uiResizeSize;
		}
		++uiSize;
		pBuffer[auiIndex] = aItem;
	}

	bool HasSufficientCapacity() {
		if (uiAllocSize <= 1024u) {
			if (uiSize <= uiAllocSize >> 2)
				return true;
		}
		else if (uiSize <= (uiAllocSize - 2048))
			return true;

		return false;
	}

	uint32_t GetOptimalCapacity() {
		if (uiAllocSize <= 2048u)
			return uiAllocSize >> 1;
		else
			return uiAllocSize - 1024;
	}

	void MoveItems(T_Data* apNewBuffer, const T_Data* apOldBuffer, const uint32_t auiSize) {
		if (!auiSize)
			return;

		if (apNewBuffer < apOldBuffer) {
			for (uint32_t j = 0; j < auiSize; ++j)
				memcpy(&apNewBuffer[j], &apOldBuffer[j], sizeof(T_Data));
		}
		else if (apNewBuffer > apOldBuffer) {
			for (uint32_t i = auiSize - 1; i >= 0; --i)
				memcpy(&apNewBuffer[i], &apOldBuffer[i], sizeof(T_Data));
		}
	}

	void RemoveAt(uint32_t auiIndex, bool abResize) {
		if (abResize && BSSimpleArray::HasSufficientCapacity()) {
			uint32_t uiOptimalCapacity = GetOptimalCapacity();
			T_Data* pNewBuffer = Allocate(uiOptimalCapacity);
			MoveItems(pNewBuffer, pBuffer, auiIndex);
			DestructItems(&pBuffer[auiIndex], 1);
			MoveItems(&pNewBuffer[auiIndex], &pBuffer[auiIndex + 1], uiSize - 1);
			FreeArray();
			pBuffer = pNewBuffer;
			uiAllocSize = uiOptimalCapacity;
		}
		else
		{
			DestructItems(&pBuffer[auiIndex], 1);
			MoveItems(&pBuffer[auiIndex], &pBuffer[auiIndex + 1], uiSize - auiIndex - 1);
		}
		--uiSize;
	}

	// 0x719B20
	int32_t Find(const T_Data& aItem, uint32_t auiStartPosition, bool(__cdecl* apCompareFunc)(const T_Data&, const T_Data&)) {
		while (auiStartPosition < uiSize) {
			if (pBuffer && apCompareFunc(pBuffer[auiStartPosition], aItem))
				return auiStartPosition;
			++auiStartPosition;
		}
		return -1;
	}
};

ASSERT_SIZE(BSSimpleArray<uint32_t>, 0x10);