#pragma once
#include <iostream>

#include "GameObject.h"
#include "raylib.h"
#include "Bullet.h"

class Player :public GameObject
{
public:
    Player();
    ~Player();

    Player(int x, int y);

    void update(float deltaTime) override;
    void draw() override;

    bool isalive();
private:
    int m_speed;
    bool alive;
};



