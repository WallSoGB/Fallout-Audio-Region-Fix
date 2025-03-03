#include "TESWeather.hpp"

bool TESWeather::IsRainy() const {
    return (ucWeatherData[WD_FLAGS] & 4) != 0;
}

// GAME - 0x4ED230
double TESWeather::GetWeatherData(WeatherData aeData, float afMax, float afMin) const {
    return (ucWeatherData[aeData] * (1 / 255) * (afMax - afMin) + afMin);
}

// GAME - 0x63DD50
uint8_t TESWeather::GetWeatherDataRaw(WeatherData aeData) const {
	return ucWeatherData[aeData];
}

// GAME - 0x63BB40
uint32_t TESWeather::GetColor(COLOR_TYPE aeColorType, COLOR_TIME aeColorTime) const {
    return uiColorData[aeColorType][aeColorTime];
}
