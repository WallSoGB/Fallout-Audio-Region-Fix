#include "BSAudioManager.hpp"

BSAudioManager* BSAudioManager::GetSingleton() {
    return StdCall<BSAudioManager*>(0xAD9060);
}