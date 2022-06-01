#include "Bullet.h"


#include <iostream>
Bullet::Bullet(int x, int y, bool _isenemy)
{
    this->posX = x;
    this->posY = y;
    this->m_size = 5;
    this->isEnemy = _isenemy;
}
void Bullet::update(float deltaTime) {
    std::cout << "bullet go" << std::endl;

    if (isEnemy) {
        this->posY = this->posY + (bulletSpeed * deltaTime);
    }
    else {
        this->posY = this->posY - (bulletSpeed * deltaTime);
    }

}


void Bullet::draw() {
    DrawEllipseLines(posX, posY, m_size, m_size + 2,BLUE);
  }