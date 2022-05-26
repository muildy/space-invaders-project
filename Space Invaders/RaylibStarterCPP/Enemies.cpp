#include "Enemies.h"
#include "Helper.h"



Enemies::Enemies()
{


	posX = 0;
	posY = 0;
	m_size = 9999.999f;
}

Enemies::~Enemies()
{
}

Enemies::Enemies(int x, int y, float size)
{
	posX = x;
	posY = y;
	m_size = size;
}

void Enemies::update(Vector2 updatePos)
{
	posX = updatePos.x;
	posY = updatePos.y;

}

void Enemies::draw()
{
	DrawCircle(posX, posY, m_size, BLUE);
}