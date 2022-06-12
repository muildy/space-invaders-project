#include "Bullet.h"


#include <iostream>
Bullet::Bullet(){}
Bullet::~Bullet(){}

Bullet::Bullet(int x, int y, bool _isenemy)
{
    posX = x;
    posY = y;
    m_size = 5;
    isEnemy = _isenemy;
    
}

//creates new bullet and adds it to end of vector
void Bullet::addBullet(int _x, int _y, bool isEnemy)
 {
    Bullet* newBullet = new Bullet(_x, _y, isEnemy);
    bullets.push_back(newBullet);
}

//if there are bullets, it iterates through the list and creates a pointer, deleting it and then deleting the data
void Bullet::clearBullet()
{
    if (bullets.size() != 0) {
        for (int i = 0; i < bullets.size(); i++) {
            Bullet* temp = bullets[i];
            bullets.erase(bullets.begin() + i);
            delete(temp);
        }
    }
}

//given that there are bullets, the program loops through all the bullets, creating vectors for raylibs inbuilt 
//circle collision detection, if conditions are met it returns true, if not, then eventually false
bool Bullet::bulletCheck(int _x, int _y, int _size, bool isPlayer)
{
    //bool collisionCheck = false;
    if (bullets.size() > 0) {
        for (int i = 0; i < bullets.size(); i++) {
            Vector2 bulletVect = Vector2{ (float)bullets[i]->posX, (float)bullets[i]->posY};
            Vector2 otherVect = Vector2{ (float)_x, (float)_y };
    
            if ((bullets[i]->isEnemy == isPlayer) && CheckCollisionCircles(bulletVect, bullets[i]->m_size, otherVect, _size)) {
                deleteBullet(i);
                return true;
            }
            else continue;
        }
    }
    return false;
}

void Bullet::deleteBullet(int index)
{
    Bullet* temp = bullets[index];
    bullets.erase(bullets.begin() + index);
    delete(temp);
}


void Bullet::update(float deltaTime) {
    if (bullets.size() > 0) {
        for (int i = 0; unsigned(i) < bullets.size(); i++) 
        {
            //check if the player or enemy fired the bullet + which direction it moves
            if (bullets[i]->isEnemy) {
                bullets[i]->posY = bullets[i]->posY + (bulletSpeed * deltaTime);
            }
            else if(!bullets[i]->isEnemy) {
                bullets[i]->posY = bullets[i]->posY - (bulletSpeed * deltaTime);
            }

            if ((bullets[i]->posX >= GetScreenWidth() || bullets[i]->posX <= 0) || (bullets[i]->posY <= 0 || bullets[i]->posY >= GetScreenHeight())) {
                deleteBullet(i);
            }
        }
    }
}


void Bullet::draw() {
    if (bullets.size() > 0) {
        for (Bullet* b : bullets) {
            DrawEllipseLines(b->posX, b->posY, b->m_size, b->m_size + 2, b->isEnemy?BLUE:RED);
        }
    }
}