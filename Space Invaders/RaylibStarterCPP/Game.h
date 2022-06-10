#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "raymath.h"

#include "DeathScreen.h"

#include "Bullet.h"
#include "Player.h"
#include "EnemyManager.h"

class Game {
public:
	/// <summary>
	/// Issues:
	/// i dont think enemies are being properly removed since the mem usage only increases
	/// player is still a tiny circle at the bottom of screen
	/// need restrictions on how fast player can shoot
	/// also needs restrictions for player movement
	/// </summary>
	Game();
	~Game();

private:
	float deltaTime;
	int score;
	int Score();
	void display();
};