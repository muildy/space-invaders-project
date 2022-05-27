#pragma once
class GameObject
{
public:
    //GameObject();
    //~GameObject();

    virtual void update() = 0;
    virtual void draw() = 0;


protected:
    int posX;
    int posY;
};


