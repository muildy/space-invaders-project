#pragma once
#include "GameObject.h"

class Enemies : public GameObject {
public:
	struct Enemy {

	};
public:
	Enemies();
	~Enemies();

	Enemies(int x, int y, float size);

	void update();
	void draw() override;

private:

};