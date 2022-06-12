#include "Enemy.h"

Enemy::Enemy()
{
	posX = 10;
	posY = 10;
}

Enemy::Enemy(int x, int y)
{
	isPlayer = false;
	posX = x;
	posY = y;
	m_size = 20;
}

void Enemy::update(float deltaTime)
{}

void Enemy::draw()
{
	DrawRectangleLines(posX, posY, m_size, m_size, BLUE);
}
