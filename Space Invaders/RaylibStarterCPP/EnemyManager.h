#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h" 

#define _width 11  //amount of enemies acros
#define _height 5  //amount of enemies deep

class EnemyManager
{
public:
	std::vector<Enemy*> enemies;
	/// <summary>
	/// fills the vector with enemies
	/// </summary>
	EnemyManager();
	~EnemyManager();

	/// <summary>
	/// refills enemies
	/// </summary>
	void repopulate();
	/// <summary>
	/// deletes all enemies inside array
	/// </summary>
	void depopulate();
	/// <summary>
	/// removes a specific Enemy given its position in the list
	/// </summary>
	/// <param name="value"></param>
	void removeEnemy(int value);
	
	void update(float deltaTime);
	void draw();
		
	int direction = 1;	//multiplied to the movement 
	bool gameOver = false;//used so game knows when the player loses
};

