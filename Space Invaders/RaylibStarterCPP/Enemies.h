#pragma once
#include "GameObject.h"

class Enemies : public GameObject {
public:
	Enemies();
	~Enemies();

	Enemies(int x, int y, float size);

	void update(Vector2 updatePos);
	void draw() override;

private:

};