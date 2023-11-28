#include "../../stdafx/stdafx.h"


class Platforms
{
    private:
    sf::Sprite platforms_sprite;
    sf::Texture platforms_texture; 
    sf::Image platforms_image;
    
    public:
    Platforms();
    ~Platforms();

    void initImage();
    void initTexture();
    void initSprite();
};