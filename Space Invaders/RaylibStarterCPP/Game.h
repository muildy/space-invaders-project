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

private:
	float deltaTime;

	int Score();
	void display();
	int score;
};