#pragma once
#include "../../stdafx/stdafx.h"
#include "../Health_Points/Health_Points.h"

class Player
{
private:
    sf::Sprite sprite_player;
    sf::Texture texture_player; 
    sf::Image image_player;
    
    sf::IntRect currentFrame;

    Health_Points health_points;


    float movementSpeed;

    float attackCooldown;
    float attackCooldownMax;
    
    void initImage();
    void initTexture();
    void initSprite();

public:
    Player();
    ~Player();

  



    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const; 


    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);

    const sf::Sprite get_sprite_player() const;



    void player_position_changes();
    void move(const float pos_x, const float pos_y);
    
    void player_animation();

    void update();
    void render(sf::RenderTarget &window);
};

