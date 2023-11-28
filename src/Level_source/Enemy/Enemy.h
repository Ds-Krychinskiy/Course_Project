#include "../../stdafx/stdafx.h"

class Enemy
{
private:
    sf::Sprite sprite_enemy;
    sf::Texture texture_enemy; 
    sf::Image image_enemy;


    unsigned pointCount;

    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;


public:
    Enemy(float pos_x, float pos_y);
    ~Enemy();
    void initImage();
    void initTexture();
    void initSprite();


    const sf::FloatRect getBounds() const;
    const int &getPoints() const;
    const int &getDamage() const;
    //Functions
    void update();
    void render(sf::RenderTarget* target);
};

