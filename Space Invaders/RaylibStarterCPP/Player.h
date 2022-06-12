#pragma once
#include <iostream>

#include "GameObject.h"
#include "raylib.h"
#include "Bullet.h"

//player class, holds it x and y and what shape is used to draw it
class Player :public GameObject
{
public:
    Player();
    ~Player();

    Player(int x, int y);

    void update(float deltaTime) override;
    void draw() override;

private:
    int m_speed;
};



