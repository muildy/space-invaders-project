#pragma once
#include "raylib.h"
class GameObject
{
public:
    //GameObject();
    //~GameObject();

    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
    
    //for use in the player, enemy and blocker thing classes
    Rectangle pos = Rectangle{posX,posY,m_size,m_size};//{x, y, width, height}

    float posX;
    float posY;
protected:
    float m_size;
};
