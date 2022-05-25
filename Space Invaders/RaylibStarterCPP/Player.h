#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:	
	Player();
	~Player();

	Player(int x, int y, int size);
	
	void update();//player update is fundamentaly simpler than the other updates due to the player directly updating it
	void draw() override;

private:
	int m_speed;
};