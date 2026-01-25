#pragma once
#include <vector>
#include "Types.h"
#include "raylib.h"

class PlatformManager
{
public:
    PlatformManager(const ScreenSize& screensize, RandomFunc randFunc);

    void applyScroll(const float offsetY);
    const std::vector<Rectangle> getPlatforms() const;

private:
    void regeneratePlatform(Rectangle& platform);
    const float c_verticalSpacing;
    const ScreenSize c_screenSize;
    std::vector<Rectangle> m_platforms;

    RandomFunc m_randFunc;
};