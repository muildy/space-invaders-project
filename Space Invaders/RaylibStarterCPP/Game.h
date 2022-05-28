#pragma once
#include <iostream>
#include <vector>

#include "raylib.h"
#include "raymath.h"
#include "Bullet.h"
#include "Player.h"


class Game {
public:
	Game();
	~Game();


	std::vector<Bullet*> bullets;

private:
	float deltaTime;

	int score(int incr);
	void display();
};