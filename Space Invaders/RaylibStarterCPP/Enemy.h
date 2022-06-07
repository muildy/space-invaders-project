#pragma once
#include "GameObject.h"

class Enemy :
    public GameObject
{
public:
    Enemy();
    Enemy(int x, int y);

    void update(float deltaTime) override;
    void draw() override;

    bool direction = false;
private:
    bool alive;
};

