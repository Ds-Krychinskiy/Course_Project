#include "./Button.h"
#include "Button.h"

Button::Button(/* args */)
{
}

Button::~Button()
{
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->m_OuterButton);
	target.draw(this->m_InnerButton);
	target.draw(this->m_Text);
}


void Button::handleEvent(const sf::Event &event)
{
}
