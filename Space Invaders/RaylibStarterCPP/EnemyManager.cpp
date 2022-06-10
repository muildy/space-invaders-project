#include "EnemyManager.h"
#include <iostream>
//for the amount of enemies along the y, place enemies along the x
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

//a carbon copy of the initialiser since you cant initialise a program twice
void EnemyManager::repopulate()
{
	for (int y = 0; y < _height; y++) {
		for (int x = 0; x < _width; x++) {
			enemies.push_back(new Enemy(20 + 30 * x, 20 + 30 * y));
		}
	}
}

//given the enemies list isnt empty, iterate through all elements and delete them
void EnemyManager::depopulate()
{
	if (enemies.size() != 0) {
		for (int i = 0; i < enemies.size(); i++) {
			Enemy* temp = enemies[i];
			enemies.erase(enemies.begin() + i);
			delete(temp);
		}
	}
}

//assigns temp a pointer to enemies, erase the original pointer to enemies and then remove the data
void EnemyManager::removeEnemy(int index)
{
	Enemy* temp = enemies[index];
	enemies.erase(enemies.begin() + index);
	delete(temp);
}

void EnemyManager::update(float deltaTime)
{
	gameOver = false;
	//debug tool
	if (IsKeyPressed(KEY_V)) {
		auto mouse = GetMousePosition();
		enemies.push_back(new Enemy(mouse.x, mouse.y));
	}
	//super basic aabb collision detection for the screen edges only
	int x_min = 1000;
	int x_max = -1000;
	int y_max = -1000;
	//find x min and max
	//if either xmin or xmax are equal to either 10 or screenwidth-10, lower by {amount} and direction is inversed
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i]->posY > y_max)
			y_max = enemies[i]->posY + enemies[i]->m_size;//the size of the enemy is added so they dont clip into the screen edge

		if (enemies[i]->posX < x_min)
			x_min = enemies[i]->posX;
		else if (enemies[i]->posX > x_max)
			x_max = enemies[i]->posX + enemies[i]->m_size;//the size of the enemy is added so they dont clip into the screen edge
	}
	if (y_max >= GetScreenHeight()-60) {
		gameOver = true;
	}

	//if the largest x is larger than or equal to the edge of the screen, 
	//or the smallest x is smaller than or equal to 10, move all enemies down and to the opposite direction
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

//iterates through enemies and calls Enemy draw for each
void EnemyManager::draw()
{
	for (Enemy* en : enemies) {
		en->draw();
	}
}