#include "PlatformManager.h"
#include <algorithm>

namespace
{
constexpr int c_platformCount{10};
constexpr float c_platformWidth{70.f};
constexpr float c_platformHeight{15.f};
}  // namespace

PlatformManager::PlatformManager(const ScreenSize& screensize, RandomFunc randFunc) : c_screenSize(screensize), //
      c_verticalSpacing(static_cast<float>(screensize.height) / c_platformCount), m_randFunc(randFunc)
{
    m_platforms.reserve(c_platformCount);

    for (int i = 0; i < c_platformCount; ++i)
    {
        const float x = m_randFunc(0.0f, c_screenSize.width - c_platformWidth);
        const float y = i * c_verticalSpacing + m_randFunc(0.0f, c_verticalSpacing * 0.5f);

        m_platforms.push_back({x, y, c_platformWidth, c_platformHeight});
    }
}

void PlatformManager::applyScroll(const float offsetY)
{
    for (auto& platform : m_platforms)
    {
        platform.y += offsetY;
        if (platform.y > c_screenSize.height)
        {
            regeneratePlatform(platform);
        }
    }
}

void PlatformManager::regeneratePlatform(Rectangle& platform)
{
    const auto minPlatform = std::min_element(m_platforms.begin(), m_platforms.end(),  //
        [](const auto& a, const auto& b) { return a.y < b.y; });

    platform.x = m_randFunc(0.0f, c_screenSize.width - c_platformWidth);
    platform.y = minPlatform->y - (c_verticalSpacing + m_randFunc(0.0f, c_verticalSpacing * 0.5f));
}

const std::vector<Rectangle> PlatformManager::getPlatforms() const
{
    return m_platforms;
}
