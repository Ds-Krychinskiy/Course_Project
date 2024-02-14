#include "Health_Bar.h"


Health_Bar::Health_Bar(unsigned int health, unsigned int maxHealth, float length, float height) :
	m_Health(health),
	m_MaxHealth(maxHealth)
{
    this->m_OffsetFromTopLeft = sf::Vector2f(25.f, 25.f);

	// inner bar
	this->m_HealthBar.setSize(
		sf::Vector2f(this->m_Health / this->m_MaxHealth * length, height));
	this->m_HealthBar.setFillColor(sf::Color::Red);
	this->m_HealthBar.setPosition(this->m_OffsetFromTopLeft);

	// outer bar
	this->m_MaxHealthBar.setSize(sf::Vector2f(length, height));
	this->m_MaxHealthBar.setFillColor(sf::Color(25, 25, 25, 200));
	this->m_MaxHealthBar.setPosition(this->m_OffsetFromTopLeft);

	// m_Text
	// this->m_Label.getText().setFont(ResourceManager::getInstance().getFont(res::Font::Roboto));
	this->m_Label.getText().setString("[" + std::to_string(health) + "/" + std::to_string(maxHealth) + "]"); // can be change to std::format after we support c++20
	this->m_Label.getText().setFillColor(sf::Color::White);
	this->m_Label.getText().setCharacterSize(height - 4);
}

void Health_Bar::setOffset(const sf::Vector2f& offsetFromTopLeft)
{
	this->m_OffsetFromTopLeft = offsetFromTopLeft;
}

void Health_Bar::setPosition(const sf::Vector2f& position)
{
	this->m_HealthBar.setPosition(position + this->m_OffsetFromTopLeft);
	this->m_MaxHealthBar.setPosition(position + this->m_OffsetFromTopLeft);
	this->alignTextToMid();
}

void Health_Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->m_MaxHealthBar);
	target.draw(this->m_HealthBar);
	target.draw(this->m_Label);
}

void Health_Bar::update(unsigned int health)
{
	this->m_Health = health;
}

void Health_Bar::setHealth(unsigned int health)
{
	this->m_Health = health;
}

void Health_Bar::setMaxHealth(unsigned int maxHealth)
{
	this->m_MaxHealth = maxHealth;
}

void Health_Bar::alignTextToMid()
{
	float x = this->m_MaxHealthBar.getPosition().x + this->m_MaxHealthBar.getSize().x / 2 - this->m_Label.getText().getGlobalBounds().width / 2;
	float y = this->m_MaxHealthBar.getPosition().y;
	this->m_Label.getText().setPosition(x, y);
}