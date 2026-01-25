#include "Player.h"
#include <algorithm>


namespace
{
// rectangle bounds
constexpr float c_width{40.0f};
constexpr float c_height{40.0f};
constexpr float c_speed{240.0f};
constexpr float c_gravity{400.f};
constexpr float c_jumpVelocityY{-500.f};
}  // namespace

Player::Player(const ScreenSize& screensize) : c_screensize(screensize), m_velocityY(0.f)
{
    m_x = (screensize.width - c_width) * .5f;
    m_y = screensize.height * .5f - 50.f;
    m_previousY = m_y;
}

void Player::updatePlayer(float deltaTime) 
{
    m_velocityY += c_gravity * deltaTime;
    m_previousY = m_y;
    m_y += m_velocityY * deltaTime;

    //wrap player
    const float playercenterX = m_x + c_width * .5f;
    if (playercenterX >= c_screensize.width)
    {
        m_x =0.f;
    }
    else if (playercenterX < 0.f)
    {
        m_x = c_screensize.width - c_width;
    }
}

void Player::moveLeft(float deltaTime)
{
    m_x -= c_speed * deltaTime;
}

void Player::moveRight(float deltaTime) 
{
    m_x += c_speed * deltaTime;
}

Rectangle Player::aabb() const
{
    return {m_x, m_y, c_width, c_height};
}

Rectangle Player::sweepAABB() const
{
    const float startY = std::min(m_previousY, m_y);
    const float endY = std::max(m_previousY, m_y);

    return {m_x, startY, c_width, endY - startY + c_height};
}

float Player::y() const
{
    return m_y;
}

void Player::setY(float y) 
{
    m_y = y;
}

float Player::velocityY() const
{
    return m_velocityY;
}

void Player::jump() 
{
    m_velocityY = c_jumpVelocityY;
}
