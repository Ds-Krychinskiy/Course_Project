#include "../../stdafx/stdafx.h"

class Bonus
{
private:
    sf::Sprite bonus_sprite;
    sf::Texture bonus_texture; 
    sf::Image bonus_image;
public:
    Bonus();
    ~Bonus();

    void initImage();
    void initTextur();
    void initSprite();
};

