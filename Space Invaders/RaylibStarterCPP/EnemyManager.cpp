#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			enemies.push_back(new Enemy(20 + 30 * x, 20 + 30 * y));
		}
	}
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::update(float deltaTime)
{
	int temp = 0;
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i]->posX >= (GetScreenWidth() - 10) && !enemies[i]->direction) {
			for (int j = temp; j < (i); j++) {
				enemies[j]->posY += 10;
				direction *= -1;
				enemies[j]->direction = true;
			}
			temp = i;
		}
		else if (enemies[i]->posX <= (10) && enemies[i]->direction) {
			for (int j = temp; j < (i); j++) {
				enemies[j]->posY += 10;
				direction *= -1;
				enemies[j]->direction = false;
			}
			temp = i;
		}
		
		
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


