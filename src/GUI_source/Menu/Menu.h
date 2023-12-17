#pragma once 

#include "../../stdafx/stdafx.h"
#include "../GUI_source/Button/Button.h"

class Menu : public State
{
private:
    Button m_StartButton;
	Button m_ExitButton;


public:
    Menu(Game* game);

    ~Menu();

	virtual void render() override;
	virtual void update(sf::Time deltaTime) override;
	virtual void handleEvent(const sf::Event& event) override;
};


