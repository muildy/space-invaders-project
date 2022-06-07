#include "Bullet.h"


#include <iostream>
Bullet::Bullet() {
    std::cout << "jimbo" << std::endl;
}
Bullet::~Bullet()
{

}
Bullet::Bullet(int x, int y, bool _isenemy)
{
    posX = x;
    posY = y;
    m_size = 5;
    isEnemy = _isenemy;
}

void Bullet::addBullet(int _x, int _y, bool isEnemy)
{
    Bullet* newBullet = new Bullet(_x, _y, isEnemy);
    bullets.push_back(newBullet);
}


void Bullet::update(float deltaTime) {
    if (bullets.size() > 0) {
        for (int i = 0; i < bullets.size(); i++) {
            std::cout << "bullet go" << std::endl;
            //check if the player or enemy fired the bullet + which direction it moves
            if (isEnemy) {
                bullets[i]->posY = bullets[i]->posY + (bulletSpeed * deltaTime);
            }
            else {
                bullets[i]->posY = bullets[i]->posY - (bulletSpeed * deltaTime);
                //this->posY = this->posY - (bulletSpeed * deltaTime);
            }

            if ((bullets[i]->posX >= GetScreenWidth() || bullets[i]->posX <= 0) || (bullets[i]->posY <= 0 || bullets[i]->posY >= GetScreenHeight())) {
                std::cout << "deleted" << std::endl;
                Bullet* temp = bullets[i];
                bullets.erase(bullets.begin() + i);
                delete(temp);
            }
        }
    }
}


void Bullet::draw() {
    if (bullets.size() > 0) {
        for (Bullet* b : bullets) {
            std::cout << "drawed" << std::endl;
            DrawEllipseLines(b->posX, b->posY, b->m_size, b->m_size + 2, BLUE);
        }
    }
  }