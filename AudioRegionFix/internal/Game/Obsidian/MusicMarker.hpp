#pragma once

class AudioMarker;
class TESObjectREFR;

class MusicMarker {
public:
    TESObjectREFR*  pReference;
    AudioMarker*    pMarker;
};

ASSERT_SIZE(MusicMarker, 0x8);