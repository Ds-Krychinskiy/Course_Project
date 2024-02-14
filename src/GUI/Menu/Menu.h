#pragma once 

#include "../../stdafx/stdafx.h"
#include "../../State/State.h"
#include "../Button/Button.h"


class Menu : public State
{
private:
    Button m_StartButton;
	Button m_ExitButton;

	sf::Texture m_BackgroundTexture;
	sf::Sprite m_Background;

	Label m_TitleLabel;

public:
    Menu(Game *game);


	virtual void render() override;
	virtual void update(sf::Time deltaTime) override;
	virtual void handleEvent(const sf::Event& event) override;
};


