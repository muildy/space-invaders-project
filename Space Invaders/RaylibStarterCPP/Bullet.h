#pragma once
#include "GameObject.h"
#include "Player.h"
#include <vector>


class Bullet :public GameObject
{
public:
	bool isEnemy;			//used for directioning, if its false, it shoots up, if its true, the opposite
	int bulletSpeed = 100;

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
	/// empties the bullet array
	/// </summary>
	void clearBullet();

	/// <summary>
	/// compares the given circle components with all the bullet circles
	/// given some conditions and returns either true or false
	/// </summary>
	/// <param name="elements of a circle and if its a player"></param>
	/// <returns>true if given circle matches with any bullet given
	/// both player and enemy are true, false if not</returns>
	bool bulletCheck(int _x, int _y, int _size, bool isPlayer);

	/// <summary>
	/// deletes the bullet at the given array index
	/// </summary>
	/// <param name="position in the array"></param>
	void deleteBullet(int index);

	void update(float deltaTime);
	void draw();
};

