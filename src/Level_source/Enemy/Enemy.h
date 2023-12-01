#pragma once
#include "../../stdafx/stdafx.h"

class Enemy
{
private:
    sf::Sprite sprite_enemy;
    sf::Texture texture_enemy; 
    sf::Image image_enemy;
    sf::IntRect currentFrame;


    unsigned pointCount;

    float movementSpeed;


    int hp;
    int hpMax;
    int damage;
    int points;


public:
    Enemy();
    ~Enemy();
    void initImage();
    void initTexture();
    void initSprite();
    const sf::Sprite &get_sprite_player() const;

    void enemy_position_changes();
    void move(const float pos_x, const float pos_y);

    const sf::FloatRect getBounds() const;
    const int &getPoints() const;
    const int &getDamage() const;
    //Functions
    void update();
    void render(sf::RenderTarget& window);
};

