#pragma once
#include "GameObject.h"

class Enemies : public GameObject {
public:
	Enemies();
	~Enemies();

	Enemies(int x, int y, int size);

	void update() override;
	void draw() override;

private:
	int m_size;
};