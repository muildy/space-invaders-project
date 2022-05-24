#include "Enemies.h"



Enemies::Enemies()
{
	posX = 0;
	posY = 0;
	m_size = INT_MAX;
}

Enemies::~Enemies()
{
}

Enemies::Enemies(int x, int y, int size)
{
	posX = x;
	posY = y;
	m_size = size;
}

void Enemies::update()
{
	posX += 5;
	//posY = posX % GetScreenWidth;

}

void Enemies::draw()
{
	DrawCircle(posX, posY, m_size, BEIGE);
}