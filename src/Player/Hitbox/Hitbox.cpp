#include "./Hitbox.h"

Hitbox::Hitbox()
{}

Hitbox::Hitbox(const sf::Vector2f& parentPosition, sf::Vector2f size, sf::Vector2f offset) :
	m_Hitbox(sf::RectangleShape(size)),
	m_Offset(offset)
{
	this->m_Hitbox.setPosition(parentPosition + this->m_Offset);
	this->m_Hitbox.setFillColor(sf::Color(0, 0, 0, 0));
	this->m_Hitbox.setOutlineThickness(1.f);
	this->m_Hitbox.setOutlineColor(sf::Color::Red);
}

Hitbox::~Hitbox()
{}

void Hitbox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->m_Hitbox);
}

void Hitbox::update(const sf::Vector2f& parentPosition)
{
	this->m_Hitbox.setPosition(parentPosition + this->m_Offset);
}

sf::FloatRect Hitbox::getGlobalBounds() const
{
	return this->m_Hitbox.getGlobalBounds();
}
