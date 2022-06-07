#pragma once
#include "GameObject.h"
#include "Player.h"
#include <vector>


class Bullet :public GameObject
{
public:
	bool isEnemy;
	std::vector<Bullet*> bullets;

	Bullet();
	~Bullet();

	/// <summary>
	/// Handles the bullets movements and conditions
	/// including the direction and collisions it might have
	/// </summary>
	/// <param name="deltaTime"></param>
	Bullet(int x, int y, bool _isenemy);
	
	void addBullet(int _x, int _y, bool isEnemy);

	void update(float deltaTime);
	void draw();
private:
	int bulletSpeed = 100;
};

