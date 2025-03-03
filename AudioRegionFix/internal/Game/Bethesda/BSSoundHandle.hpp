#pragma once

class BSSoundHandle {
public:
	uint32_t	uiSoundID;
	bool		bAssumeSuccess;
	uint32_t	uiState;

	BSSoundHandle() : uiSoundID(-1), bAssumeSuccess(false), uiState(0) {}
	BSSoundHandle(const BSSoundHandle& arHandle) : uiSoundID(arHandle.uiSoundID), bAssumeSuccess(arHandle.bAssumeSuccess), uiState(arHandle.uiState) {}
	BSSoundHandle(const BSSoundHandle* apHandle) : uiSoundID(apHandle->uiSoundID), bAssumeSuccess(apHandle->bAssumeSuccess), uiState(apHandle->uiState) {}
	~BSSoundHandle() {}

	BSSoundHandle operator=(const BSSoundHandle& arHandle) {
		uiSoundID = arHandle.uiSoundID;
		bAssumeSuccess = arHandle.bAssumeSuccess;
		uiState = arHandle.uiState;
		return *this;
	}

	BSSoundHandle operator=(const BSSoundHandle* apHandle) {
		uiSoundID = apHandle->uiSoundID;
		bAssumeSuccess = apHandle->bAssumeSuccess;
		uiState = apHandle->uiState;
		return *this;
	}

	void Reset();

	bool IsValid() const;
	bool IsInvalid() const { return uiSoundID == -1; }
	bool IsPlaying() const;

	bool Play(bool abUnk);
	bool FadeInPlay(uint32_t auiMilliseconds);
	bool Stop();

	bool Release();

	void SetPriority(uint8_t aucPriority) const;

	bool SetStaticAttenuation(uint16_t ausAttenuation);
	bool SetReverbAttenuation(uint16_t ausAttenuation);
	bool SetVolume(float afVolume);
	bool SetSpeed(float afSpeed);
	bool SetPosition(float afX, float afY, float afZ);
	void SetMinMaxDistance(float afMin, float afMax);
	void SetAttenuationCurve(int16_t ausUnk1, int16_t ausUnk2, uint16_t ausStaticAttenuation, uint16_t ausSystemAttenuation, uint16_t ausDistanceAttenuation);
	bool FadeOutAndRelease(uint32_t auiMilliseconds);
};

ASSERT_SIZE(BSSoundHandle, 0xC);