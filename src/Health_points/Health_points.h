#include "stdafx.h"


class Health_points
{
private:
    int hp;
    int hpMax;
public:
    Health_points();
    ~Health_points();
    const int &getHp() const;
    const int &getHpMax() const;

    void setPosition(const sf::Vector2f pos);
    void setPosition(const float x, const float y);
    void setHp(const int hp);
    void loseHp(const int value);
    
    //Functions
    void move(const float dirX, const float dirY);

    void update();
    void render(sf::RenderTarget& target);
};


