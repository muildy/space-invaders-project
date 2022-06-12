#include "Player.h"


Player::Player() {
    posX = 0;
    posY = 0;
    m_size = INT_MAX;
    m_speed = 2;
    isPlayer = true;
}
Player::~Player()
{
}

Player::Player(int x, int y)
{
    posX = x;
    posY = y;
    m_size = 5;
    m_speed = 10;
    isPlayer = true;
}

void Player::update(float deltaTime)
{

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        posX -= m_speed + (m_speed * deltaTime);
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        posX += m_speed + (m_speed * deltaTime);
    }
}
void Player::draw()
{
    DrawCircle(posX, posY, m_size, RED);
}

bool Player::isalive()
{
    return alive;
}
