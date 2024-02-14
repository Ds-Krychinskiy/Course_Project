#pragma once

#include "../../stdafx/stdafx.h"


class Widget : public sf::Drawable
{
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void handleEvent(const sf::Event& event) = 0;
};