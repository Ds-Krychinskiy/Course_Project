#pragma once

#include "./stdafx/stdafx.h"
#include "./engine/State/State.h"
#include "./engine/gui/Label.h"
#include "./engine/gui/Button.h"
#include "./engine/audio/MusicPlayer.h"

class PauseState : public State
{
public:
	PauseState(Game* game);

	// Inherited via State
	virtual void render() override;
	virtual void update(sf::Time deltaTime) override;
	virtual void handleEvent(const sf::Event& event) override;

private:
	sf::Texture m_BackgroundTexture;
	sf::Sprite m_Background;

	Button m_ContinueButton;
	Button m_MainMenuButton;

	MusicPlayer m_MusicPlayer;

	Label m_TitleLabel;
};
