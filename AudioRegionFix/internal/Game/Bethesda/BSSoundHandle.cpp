#include "BSSoundHandle.hpp"

void BSSoundHandle::Reset() {
	uiSoundID		= -1;
	bAssumeSuccess	= false;
	uiState			= 0;
}

// GAME - 0xAD8CE0
bool BSSoundHandle::IsValid() const {
	return ThisCall<bool>(0xAD8CE0, this);
}

// GAME - 0xAD8930
bool BSSoundHandle::IsPlaying() const {
	return ThisCall<bool>(0xAD8930, this);
}

// GAME - 0xAD8830
bool BSSoundHandle::Play(bool abUnk) {
	return ThisCall<bool>(0xAD8830, this, abUnk);
}

// GAME - 0xAD8D60
bool BSSoundHandle::FadeInPlay(uint32_t auiMilliseconds) {
	return ThisCall<bool>(0xAD8D60, this, auiMilliseconds);
}

// GAME - 0xAD88F0
bool BSSoundHandle::Stop() {
	return ThisCall<bool>(0xAD88F0, this);
}

// GAME - 0xAD8D10
bool BSSoundHandle::Release() {
	return ThisCall<bool>(0xAD8D10, this);
}

// GAME - 0xAD9030
void BSSoundHandle::SetPriority(uint8_t aucPriority) const {
	return ThisCall<void>(0xAD9030, this, aucPriority);
}

// GAME - 0xAD89B0
bool BSSoundHandle::SetStaticAttenuation(uint16_t ausAttenuation) {
	return ThisCall<bool>(0xAD89B0, this, ausAttenuation);
}

// GAME - 0xAD8C70
bool BSSoundHandle::SetReverbAttenuation(uint16_t ausAttenuation) {
	return ThisCall<bool>(0xAD8C70, this, ausAttenuation);
}

// GAME - 0xAD89E0
bool BSSoundHandle::SetVolume(float afVolume) {
	return ThisCall<bool>(0xAD89E0, this, afVolume);
}

// GAME - 0xAD8A90
bool BSSoundHandle::SetSpeed(float afSpeed) {
	return ThisCall<bool>(0xAD8A90, this, afSpeed);
}

// GAME - 0xAD8B60
bool BSSoundHandle::SetPosition(float afX, float afY, float afZ) {
	return ThisCall<bool>(0xAD8B60, this, afX, afY, afZ);
}

// GAME - 0xAD8BE0
void BSSoundHandle::SetMinMaxDistance(float afMin, float afMax) {
	ThisCall(0xAD8BE0, this, afMin, afMax);
}

// GAME - 0xAD8C20
void BSSoundHandle::SetAttenuationCurve(int16_t ausUnk1, int16_t ausUnk2, uint16_t ausStaticAttenuation, uint16_t ausSystemAttenuation, uint16_t ausDistanceAttenuation) {
	ThisCall(0xAD8C20, this, ausUnk1, ausUnk2, ausStaticAttenuation, ausSystemAttenuation, ausDistanceAttenuation);
}

// GAME - 0xAD8DA0
bool BSSoundHandle::FadeOutAndRelease(uint32_t auiMilliseconds) {
	return ThisCall<bool>(0xAD8DA0, this, auiMilliseconds);
}
