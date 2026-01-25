#include "gtest/gtest.h"
#include "Types.h"
#include "Player.h"
#include "PlatformManager.h"

namespace
{
    int randFuncIndex = 0;
    float mockRandomFuncFromArray(float min = 0.f, float max = 0.f)
    {
        const std::vector<float> randomValues = {10.f, 20.f, 30.f, 40.f, 50.f, 60.f, 70.f, 80.f, 90.f, 100.f};
        return randomValues[(randFuncIndex++) % randomValues.size()];
    }
}

TEST(PlayerTest, JumpVelocityShouldBeSetCorrectly)
{
    const ScreenSize screensize{500, 700};
    Player player(screensize);
    player.jump();

    ASSERT_EQ(player.velocityY(), -500.0f);
}

TEST(PlatformManagerTest, PlatformPositionShouldBeSetCorrectly)
{
    const ScreenSize screensize{500, 700};
    PlatformManager platformManager(screensize, mockRandomFuncFromArray);

    const float platformCount = 10;
    const auto platforms = platformManager.getPlatforms();
    ASSERT_EQ(platforms.size(), platformCount);

    randFuncIndex = 0;
    const float verticalSpacing = static_cast<float>(screensize.height) / platformCount;
    for (size_t i = 0; i < platforms.size(); i++)
    {
        const float exprectedX = mockRandomFuncFromArray();
        const float exprectedY = i * verticalSpacing + mockRandomFuncFromArray();

        EXPECT_NEAR(platforms[i].x, exprectedX, 0.001f);
        EXPECT_NEAR(platforms[i].y, exprectedY, 0.001f);
    }
}