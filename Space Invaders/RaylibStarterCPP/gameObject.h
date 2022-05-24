#pragma once

#include "raylib.h"
#include "raymath.h"

#include <iostream> 

/// <summary>
///			^ ~ y
///			|
///		<-	+	-> ~ x
///			|
///			v
/// the game object is the parent class to all objects required in the game
/// </summary>
class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void update() = 0;
	virtual void draw() = 0;

	int AAAAAa();

protected:
	int health;
	int posY;
	int posX;


};