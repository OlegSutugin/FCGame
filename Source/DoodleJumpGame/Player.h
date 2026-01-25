#pragma once
#include "raylib.h"
#include "Types.h"

class Player
{
public:
    Player(const ScreenSize& screensize);

    Rectangle aabb() const;
    Rectangle sweepAABB() const;

    float y() const;
    void setY(float y);
    float velocityY() const;
    void jump();

    void updatePlayer(float deltaTime);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);

private:
    const ScreenSize c_screensize;
    //positions
    float m_x;
    float m_y;
    float m_previousY;
    float m_velocityY;

};