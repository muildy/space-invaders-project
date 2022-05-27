#pragma once
#include <iostream>

#include "GameObject.h"
#include "raylib.h"


class Player :public GameObject
{
public:
    Player();
    ~Player();

    Player(int x, int y);

    void update();//player update is fundamentaly simpler than the other updates due to the player directly updating it
    void draw() override;

private:
    int m_size;
    int m_speed;
    bool alive;
};



