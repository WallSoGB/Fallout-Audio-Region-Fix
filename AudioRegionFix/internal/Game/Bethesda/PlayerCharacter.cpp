#include "PlayerCharacter.hpp"
#include "MusicMarker.hpp"
#include "NiPoint2.hpp"

#define AUDIO_MARKER_DISTANCE_FIX

PlayerCharacter* PlayerCharacter::GetSingleton() {
	return *(PlayerCharacter**)0x011DEA3C;
}

// GAME - 0x969930
MusicMarker* PlayerCharacter::GetCurrentMusicMarker() {
	if (pCurrMusicMarker)
		return pCurrMusicMarker;

	if (kMusicMarkers.IsEmpty())
		return nullptr;

    MusicMarker* pClosestMarker = nullptr;
    float fMarkerDistance = FLT_MAX;
    bool bPlayerInRadius = false;
    bool bPlayerInCurrentMarker = false;
    auto pIter = &kMusicMarkers;
    const NiPoint2 kPlayerPos = *GetPos();
    while (pIter && pIter->GetItem()) {
        MusicMarker* pMarker = pIter->GetItem();
        pIter = pIter->GetNext();
        if (!pMarker->pReference)
			continue;

        NiPoint2 kMarkerPos = *pMarker->pReference->GetPos();
        float fDistance = (kPlayerPos - kMarkerPos).SqrLength();
        float fRadius = pMarker->pReference->GetRadius();
        bPlayerInRadius = fDistance < fRadius * fRadius;

#ifdef AUDIO_MARKER_DISTANCE_FIX // Credit to karut for the fix
        if (bPlayerInCurrentMarker && !bPlayerInRadius)
            continue;

        if (!bPlayerInCurrentMarker && bPlayerInRadius) [[unlikely]] {
            fMarkerDistance = FLT_MAX;
            bPlayerInCurrentMarker = true;
        }
        if (fMarkerDistance > fDistance) {
            pClosestMarker = pMarker;
            fMarkerDistance = fDistance;
        }
#else
        if (fMarkerDistance > fDistance) {
            if (!bPlayerInCurrentMarker) {
                fMarkerDistance = fDistance;
                pClosestMarker = pMarker;
                bPlayerInCurrentMarker = bPlayerInRadius;
            }
        }
        else if (bPlayerInRadius && !bPlayerInCurrentMarker) {
            fMarkerDistance = fDistance;
            pClosestMarker = pMarker;
            bPlayerInCurrentMarker = bPlayerInRadius;
        }
#endif
    }
    pCurrMusicMarker = pClosestMarker;
    return pClosestMarker;
}
