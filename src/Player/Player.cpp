#include "Player.h"

Player::Player()
{
    this->image_player.loadFromFile("../..texture/owl.jpg");

    if(!this->texture_player.loadFromImage(this->image_player))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file." << "\n";
    }

    this->sprite_player.setTexture(this->texture_player);
    this->sprite_player.scale(0.1f, 0.1f);

}

Player::~Player()
{
}


void Player::render(sf::RenderTarget &window)
{
    window.draw(this->sprite_player);
}
