#include "Player.h"

Player::Player()
{
    this->movementSpeed = 5.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
    this->initImage();
    this->initTexture();
    this->initSprite();
    std::cout << "Player::Player was work" << std::endl;

}

Player::~Player()
{
}

void Player::initImage()
{
    this->image_player.loadFromFile("../texture/owl.png");
}

void Player::initTexture()
{
    if(!this->texture_player.loadFromImage(this->image_player))
    {
        std::cout << "ERROR::PLAYER::INITTEXTURE:: Could not load texture file." << "\n";
    }
}

void Player::initSprite()
{   
    this->sprite_player.setTexture(this->texture_player);
    this->currentFrame = sf::IntRect(75,100,80,35);

    this->sprite_player.setTextureRect(this->currentFrame);
    this->sprite_player.setScale(2.5, 2.5);
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



void Player::move(const float pos_x, const float pos_y) 
{
    this->sprite_player.move(this->movementSpeed * pos_x, this->movementSpeed * pos_y);
}

void Player::player_position_changes()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        int xTexture = 38;
        xTexture = static_cast<int>(sprite_player.getPosition().x ) / 50 % 3;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,50,80,40);

        this->sprite_player.setTextureRect(this->currentFrame);
        this->move(-1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {   
        int xTexture = 75;
        xTexture = static_cast<int>(sprite_player.getPosition().x ) / 50 % 3;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,100,80,40);
        this->sprite_player.setTextureRect(this->currentFrame);
        this->move(1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {   
        int xTexture = 75;
        xTexture = static_cast<int>(sprite_player.getPosition().y ) / 50 % 3;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,140,77,50);
        this->sprite_player.setTextureRect(this->currentFrame);
        this->move(0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        int xTexture = 0;
        xTexture = static_cast<int>(sprite_player.getPosition().y ) / 50 % 3;
        xTexture *= 80;
        this->currentFrame = sf::IntRect(xTexture,0,80,50);
        this->sprite_player.setTextureRect(this->currentFrame);
        this->move(0.f, 1.f);
    }
    // if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
    // {
    //     this->bullets.push_back(
    //         new Bullet(
    //             this->textures["BULLET"],
    //             this->player->getPos().x, 
    //             this->player->getPos().y, 
    //             0.f, 
    //             -1.f, 
    //             5.f
    //             )
    //         );
    // }
}

void Player::player_animation()
{
}

void Player::update()
{
}

void Player::render(sf::RenderTarget &window)
{
    window.draw(this->sprite_player);
    this->player_position_changes();
}


void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(light);
	target.draw(this->sprite_player);
	// Uncomment the following row to draw the player's m_Hitbox:
	target.draw(this->m_Hitbox);
	// target.draw(m_ParticleEmitter);
}
