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

	//virtual void update() = 0;
	virtual void draw() = 0;


protected:
	int lives;	//player should start with 3 lives
	int posX;
	int posY;
	float m_size;	//size of the circles or squares, is a float for warnings reasons

	bool alive;	//general alive vibe check
};