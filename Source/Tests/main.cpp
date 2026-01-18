//#include <cassert>
#include "Utils/Math.h"
#include "Game/Character.h"
#include <iostream>
#include<gtest/gtest.h>

TEST(Math, MaxShouldBeCalculatedCorrectly)
{
    ASSERT_TRUE(max(3,0) == 3);
    ASSERT_TRUE(max(-3,0) == 0);
}

TEST(Character, CharacterCanBeKilled) 
{
    Character hero1("first test hero");
    ASSERT_TRUE(!hero1.IsCharacterDead());
    hero1.TakeDamage(20);
    ASSERT_TRUE(!hero1.IsCharacterDead());
    hero1.TakeDamage(200);
    ASSERT_TRUE(hero1.IsCharacterDead());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    const auto status = RUN_ALL_TESTS();
    std::cin.get();
    return status;
}