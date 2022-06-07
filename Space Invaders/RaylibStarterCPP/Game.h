#pragma once
#include <iostream>
#include <vector>

#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include "Player.h"
#include "EnemyManager.h"

class Game {
public:
	Game();
	~Game();

	//MOVED TO BULLET.H
//	std::vector<Bullet*> bullets;

	//std::vector<Enemy*> enemies;

private:
	float deltaTime;

	int score(int incr);
	void display();
};