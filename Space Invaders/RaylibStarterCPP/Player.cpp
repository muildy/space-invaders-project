#include "Player.h"


Player::Player() {
    posX = 0;
    posY = 0;
    Player::m_size = INT_MAX;
}

Player::~Player()
{
}

Player::Player(int x, int y, int size)
{
    posX = x;
    posY = y;
    Player::m_size = size;
}

void Player::update()
{
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        std::cout << "A" << std::endl;
        posX -= 5;
    };
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        std::cout << "D" << std::endl;
        posX += 5;
    };
    if (IsKeyPressed(KEY_SPACE)) {
        std::cout << "SPACE" << std::endl;
    };
}

void Player::draw()
{
	DrawCircle(posX, posY, m_size, BEIGE);
}
