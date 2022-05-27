#pragma once
#include <iostream>

#include "raylib.h"
#include "raymath.h"



class Game {
public:
	Game();
	~Game();

private:
	int score(int incr);

	void display();
};