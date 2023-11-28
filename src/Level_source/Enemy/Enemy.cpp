#include "Enemy.h"
Enemy::Enemy(float pos_x, float pos_y)
{
    this->initImage();
    this->initTexture();
    this->initSprite();
}

Enemy::~Enemy()
{
}

void Enemy::initImage()
{
    this->image_enemy.loadFromFile("../../../texture/orc.jpg");
};

void Enemy::initTexture()
{
    if(!this->texture_enemy.loadFromImage(this->image_enemy))
    {
        std::cout << "ERROR::ENEMY::INITTEXTURE:: Could not load texture file." << "\n";
    }
};


void Enemy::initSprite()
{
    this->sprite_enemy.setTexture(this->texture_enemy);
};
