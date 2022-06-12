#pragma once
#include "raylib.h"
struct objPositon {
    int x;
    int y;
};

//base class of Enemy and Player, nothing is protected or private as i forgot about getters or setters until way too late
//and i am out of time
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
    float m_size = 5;
    bool isPlayer;
};
