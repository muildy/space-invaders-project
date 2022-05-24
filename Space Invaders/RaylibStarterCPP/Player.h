#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:	
	Player();
	~Player();

	Player(int x, int y, int size);
	
	void update() override;
	void draw() override;

private:
	int m_size;
};