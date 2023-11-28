#include "./Bonus.h"

Bonus::Bonus()
{
    this->initImage();
    this->initTextur();
    this->initSprite();
}

Bonus::~Bonus()
{
}


void Bonus::initImage()
{
    this->bonus_image.loadFromFile("../texture/bitcoin.jpg");
};
void Bonus::initTextur()
{
    if(!this->bonus_texture.loadFromImage(this->bonus_image))
    {
        std::cout << "ERROR::BONUS::CONSTRUCTOR 9 line:: Could not load texture file." << "\n";
    };
};
void Bonus::initSprite()
{
    this->bonus_sprite.setTexture(this->bonus_texture);
};