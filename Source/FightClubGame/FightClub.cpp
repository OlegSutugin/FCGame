#include <iostream>
#include "Game/Character.h"
#include <utility>
#include <thread>

int main()
{
    Character hero1("Vasya");
    Character hero2("Petya");

    Character* attacker = &hero1;
    Character* defender = &hero2;

    bool lastfirestatus = true;

    while (true)
    {
        const bool fired = attacker->Attack(*defender);
        if (lastfirestatus == fired && !fired)
        {
            std::cout << "=====GAME OVER=====" << std::endl;
            std::cout << " Draw!!!!" << std::endl;
            break;
        }
        lastfirestatus = fired;

        if (defender->IsCharacterDead())
        {
            std::cout << "=====GAME OVER=====" << std::endl;
            std::cout << attacker->GetCharsName() << " WIN!!" << std::endl;
            std::cout << defender->GetCharsName() << " Lose :( " << std::endl;
            break;
        }

        std::swap(attacker, defender);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
