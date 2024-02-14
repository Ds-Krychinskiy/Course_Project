#include "GameState.h"

GameState::GameState(Game* game) : State(game), m_FrameTime(0.f)
{	
	
}
GameState::~GameState() 
{	
	
}


void GameState::render()
{
}

void GameState::update(sf::Time deltaTime)
{
}

void GameState::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::Closed)
	{
		this->m_Game->get_window()->close();
	}
	else if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			// m_Player->stop();
			// m_Game->pushState(new PauseState(m_Game));
		}
	}
}
