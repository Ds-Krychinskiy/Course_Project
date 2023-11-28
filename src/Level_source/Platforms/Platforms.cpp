#include "Platforms.h"


Platforms::Platforms()
{
    this->initImage();
    this->initTexture();
    this->initSprite();
}

Platforms::~Platforms()
{
}


void Platforms::initImage()
{
    this->platforms_image.loadFromFile("../texture/brick.png");
};

void Platforms::initTexture()
{
    if(!this->platforms_texture.loadFromImage(this->platforms_image))
    {
        std::cout << "ERROR::Platforms::Platforms 9 line:: Could not load texture file." << "\n";
    }
};
void Platforms::initSprite()
{
    this->platforms_sprite.setTexture(this->platforms_texture);

};