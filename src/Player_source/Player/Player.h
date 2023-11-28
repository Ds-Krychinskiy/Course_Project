#include "../../stdafx/stdafx.h"
#include "../Health_Points/Health_Points.h"

class Player
{
private:
    sf::Sprite sprite_player;
    sf::Texture texture_player; 
    sf::Image image_player;

    Health_Points health_points;


    float movementSpeed;

    float attackCooldown;
    float attackCooldownMax;

public:
    Player();
    ~Player();

    const sf::Vector2f& getPos() const;
    const sf::FloatRect getBounds() const; 

    void render(sf::RenderTarget &target);

    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);

    const sf::Sprite get_sprite_player() const;

    void move(const float dirX, const float dirY);

};

