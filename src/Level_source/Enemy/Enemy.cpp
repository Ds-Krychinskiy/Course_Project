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
    this->image_enemy.loadFromFile("../orc.jpg");
    if(!this->texture_enemy.loadFromImage(this->image_enemy))
    {
        std::cout << "ERROR::ENEMY::INITTEXTURE:: Could not load texture file." << "\n";
    }
    this->sprite_enemy.setTexture(this->texture_enemy);

};

void Enemy::initTexture()
{
    
};


void Enemy::initSprite()
{
}

void Enemy::render(sf::RenderTarget &target)
{
    target.draw(this->sprite_enemy);
};
