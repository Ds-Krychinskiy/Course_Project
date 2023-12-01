#include "Enemy.h"

Enemy::Enemy()
{   
    this->movementSpeed = 5.f;
    this->initImage();
    this->initTexture();
    this->initSprite();
}

Enemy::~Enemy()
{
}

void Enemy::initImage()
{
    this->image_enemy.loadFromFile("../texture/orc.jpg");
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
    this->currentFrame = sf::IntRect(100,5,80,80);
    this->sprite_enemy.setTextureRect(this->currentFrame);
    this->sprite_enemy.setScale(1.25, 1.25);
}


void Enemy::move(const float pos_x, const float pos_y) 
{
    this->sprite_enemy.move(this->movementSpeed * pos_x, this->movementSpeed * pos_y);
}

void Enemy::enemy_position_changes()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        int xTexture = 100;
        xTexture = static_cast<int>(sprite_enemy.getPosition().x ) / 50 % 3;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,95,80,80);

        this->sprite_enemy.setTextureRect(this->currentFrame);
        this->move(-1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {   
        int xTexture = 100;
        xTexture = static_cast<int>(sprite_enemy.getPosition().x ) / 50 % 5;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,190,80,80);
        this->sprite_enemy.setTextureRect(this->currentFrame);
        this->move(1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {   
        int xTexture = 100;
        xTexture = static_cast<int>(sprite_enemy.getPosition().y ) / 50 % 5;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,270,70,100);
        this->sprite_enemy.setTextureRect(this->currentFrame);
        this->move(0.f, -1.f);
    }
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    // {
    //     int xTexture = 110;
    //     xTexture = static_cast<int>(sprite_enemy.getPosition().y ) / 50 % 5;
    //     xTexture *= 100;
    //     this->currentFrame = sf::IntRect(xTexture,370,80,80);
    //     this->sprite_enemy.setTextureRect(this->currentFrame);
    //     this->move(0.f, 1.f);
    // }
    // if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
    // {
    //     this->bullets.push_back(
    //         new Bullet(
    //             this->textures["BULLET"],
    //             this->player->getPos().x, 
    //             this->player->getPos().y, 
    //             0.f, 
    //             -1.f, 
    //             5.f
    //             )
    //         );
    // }
}


const sf::Sprite &Enemy::get_sprite_player() const
{
    return this->sprite_enemy;
}

void Enemy::render(sf::RenderTarget &window)
{
    window.draw(this->sprite_enemy);
    this->enemy_position_changes();
};
