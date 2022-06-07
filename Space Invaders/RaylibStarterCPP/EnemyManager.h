#pragma once
#include <vector>
#include "Enemy.h"
 
#define width 11  //amount of enemies acros
#define height 5  //amount of enemies deep

class EnemyManager
{
public:
	std::vector<Enemy*> enemies;
	/// <summary>
	/// fills the vector with enemies
	/// </summary>
	EnemyManager();
	~EnemyManager();

	void update(float deltaTime);
	void draw();


	void removeEnemy(int value);
	
	int direction = 1;	//multiplied to the movement 
};

