#pragma once
#include "GameObject.h"
class Bullet :public GameObject
{
public:
	bool isEnemy;
	Bullet();
	//~Bullet();
	Bullet(int x, int y, bool _isenemy);


	void update(float deltaTime);
	void draw();
private:
	int bulletSpeed = 100;
};

