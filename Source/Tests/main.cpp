#include <cassert>
#include "Utils/Math.h"
#include "Game/Character.h"

int main()
{
    assert(max(3,0) == 3);
    assert(max(-3,0) == 0);

    Character hero1("first test hero");
    assert(!hero1.IsCharacterDead());
    hero1.TakeDamage(20);
    assert(!hero1.IsCharacterDead());
    hero1.TakeDamage(200);
    assert(hero1.IsCharacterDead());

    return 0;
}