#include "Character.h"
#include "Weapon.h"
#include <iostream>
#include "Utils/Math.h"

Character::Character(const char* name) : m_name(name)
{
    const int bulletsCount = RandomInt(1, 10);
    m_weapon = new Weapon(bulletsCount);
}

Character::~Character()
{
    delete m_weapon;
    m_weapon = nullptr;
}

const char* Character::GetCharsName() const
{
    return m_name;
}

int Character::GetCharsHealth() const
{
    return m_health;
}

bool Character::IsCharacterDead() const
{
    return m_health <= 0;
}

bool Character::Attack(Character& target)
{
    const bool fired = m_weapon->Fire();
    if (fired)
    {
        const int damage = m_weapon->Damage();
        std::cout << m_name << " is attacking with damage = " << damage << std::endl;
        target.TakeDamage(damage);
    }
    else
    {
        std::cout << m_name << " cannot attack, cause of no bullets in weapon " << std::endl;
    }

    std::cout << std::endl;
    return fired;
}

void Character::TakeDamage(int Damage)
{
    m_health -= Damage;
    if (m_health <= 0)
    {
        m_health = 0;
    }

    std::cout << m_name << " was attacked, current health = " << m_health << std::endl;
}
