#include "EnemyManager.h"
#include <iostream>

EnemyManager::EnemyManager()
{
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			enemies.push_back(new Enemy(20 + 30 * x, 20 + 30 * y));
		}
	}
}

EnemyManager::~EnemyManager()
{

}

void EnemyManager::update(float deltaTime)
{
	//super basic aabb collision detection for the screen edges only
	int x_min = 1000;
	int x_max = -1000;
	int y_max = -1000;
	//find x min and max
	//if either xmin or xmax are equal to either 10 or screenwidth-10, lower by {amount} and direction is inversed
	//when i get around to it, only make this happen if an enemy is destroyed
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i]->posY > y_max)
			y_max = enemies[i]->posY;

		if (enemies[i]->posX < x_min)
			x_min = enemies[i]->posX;
		else if (enemies[i]->posX > x_max)
			x_max = enemies[i]->posX + enemies[i]->m_size;//the size of the enemy is added so they dont clip into the screen edge
	}
	//if the largest x is larger than or equal to the edge of the screen, 
	//or the smallest x is smaller than or equal to 10, move all enemies down and to the opposite direction
	if (y_max >= GetScreenHeight()) {

		std::cout << "Game Over" << std::endl;
	}
	if (x_max >= GetScreenWidth() || x_min <= 10) {
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->posY += 10;
		}
		direction *= -1;
	}

	for (int i = 0; i < enemies.size(); i++) {

		enemies[i]->posX += 5 * direction;
	}
	
}

void EnemyManager::draw()
{
	for (Enemy* en : enemies) {
		en->draw();
	}
}

void EnemyManager::removeEnemy(int value)
{
	enemies.erase(enemies.begin() + value);
}


