#include "Enemies.h"
#include "Helper.h"



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

void Enemies::update(Vector2 updatePos)
{
	posX = posX;// % screenWidth;
	posY = posX;// / screenWidth;

}

void Enemies::draw()
{
	DrawCircle(posX, posY, m_size, BLUE);
}