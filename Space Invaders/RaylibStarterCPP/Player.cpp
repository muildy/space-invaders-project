#include "Player.h"


Player::Player() {
    posX = 0;
    posY = 0;
    m_size = INT_MAX;
    m_speed = 2;
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
}
int tempX = 0;
void Player::update()
{

    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        posX -= m_speed;
        std::cout << "A" << tempX << std::endl;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        posX += m_speed;
        std::cout << "D" << tempX << std::endl;

    }
    if (IsKeyPressed(KEY_SPACE)) {
        std::cout << "SPACE" << std::endl;
    }
}
void Player::draw()
{
    DrawCircle(posX, posY, m_size, BEIGE);
}