#include "Player.h"

Player::Player()
{
    this->movementSpeed = 5.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;

    this->image_player.loadFromFile("../../texture/owl.png");

    if(!this->texture_player.loadFromImage(this->image_player))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file." << "\n";
    }

    this->sprite_player.setTexture(this->texture_player);
}

Player::~Player()
{
}


void Player::render(sf::RenderTarget &window)
{
    window.draw(this->sprite_player);
}

const sf::Vector2f &Player::getPos() const
{
    return this->sprite_player.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return this->sprite_player.getGlobalBounds();
}

void Player::setPosition(const sf::Vector2f pos)
{
    this->sprite_player.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
    this->sprite_player.setPosition(x,y);
}


const sf::Sprite Player::get_sprite_player() const
{
    return this->sprite_player;
}

void Player::move(const float dirX, const float dirY)
{
    this->sprite_player.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}