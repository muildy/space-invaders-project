#pragma once
#include "raylib.h"
struct objPositon {
    int x;
    int y;
};

class GameObject
{
public:
    GameObject();
    ~GameObject();

    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
    

    //for use in the player, enemy and blocker thing classes


    float posX;
    float posY;
protected:
    float m_size = 15;
};
