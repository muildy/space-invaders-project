#include "gameObject.h"

GameObject::GameObject()
{
	health = 0;
	posX = 0;
	posY = 0;
}

void GameObject::translateObj(int xMov, int yMov) {
	posX + xMov;
	posY + yMov;
}

GameObject::~GameObject()
{
	//when i do fun pointer stuff, here it goes
}
