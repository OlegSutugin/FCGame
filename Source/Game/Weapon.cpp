#include "Weapon.h"
#include "Utils/Math.h"

Weapon::Weapon(int bullets) : m_bullets(bullets) {}

bool Weapon::Fire()
{
    if (m_bullets <= 0)
    {
        return false;
    }

    --m_bullets;
    return true;
}

int Weapon::Damage() const
{
    return RandomInt(5, 12);
}
