#pragma once

class Weapon
{
public:
    Weapon(int bullets);
    bool Fire();
    int Damage() const;

private:
    int m_bullets{20};
};