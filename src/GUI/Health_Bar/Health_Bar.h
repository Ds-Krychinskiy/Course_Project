#pragma once

#include "../../stdafx/stdafx.h"


class Health_Bar : public sf::Drawable
{
private:
    unsigned int m_Health;
	unsigned int m_MaxHealth;
    sf::RectangleShape hp_bar;
    sf::RectangleShape hp_bar_back;
    sf::Vector2f m_OffsetFromTopLeft;

	sf::RectangleShape m_HealthBar;
	sf::RectangleShape m_MaxHealthBar;
	Label m_Label;
    
    void alignTextToMid();

public:
    Health_Bar(unsigned int health = 100, unsigned int maxHealth = 100, float length = 250.f,
		float height = 20.f);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(unsigned int health);

	void setOffset(const sf::Vector2f& offsetFromTopLeft);
	void setPosition(const sf::Vector2f& position);

	void setHealth(unsigned int health);
	void setMaxHealth(unsigned int maxHealth);
    

};


