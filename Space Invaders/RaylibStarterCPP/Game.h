#pragma once
#include <iostream>
#include <vector>

#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

class Game {
public:
	Game();
	~Game();


	std::vector<Bullet*> bullets;

	std::vector<Enemy*> enemies;

private:
	float deltaTime;

	int score(int incr);
	void display();
};