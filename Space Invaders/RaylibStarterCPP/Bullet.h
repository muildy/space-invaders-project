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

	/// <summary>
	/// uses parameters to create a bullet at location given, and moves up if isEnemy is false, vice versa
	/// </summary>
	/// <param name="_x, _y, isEnemy"></param>
	void addBullet(int _x, int _y, bool isEnemy);

	/// <summary>
	/// checks the 
	/// </summary>
	/// <param name="_x, _y, _size"></param>
	/// <returns>returns true if something enters the bullet radius</returns>
	bool bulletCheck(int _x, int _y, int _size);

	void deleteBullet(int index);

	void update(float deltaTime);
	void draw();
private:
	int bulletSpeed = 100;
};

