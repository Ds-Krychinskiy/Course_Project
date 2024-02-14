#include "Game.h"
#include "../GUI/Menu/Menu.h"


Game::Game() : window({ Game::s_WindowSizeX, Game::s_WindowSizeY }, Game::s_Name)
{ 
    this->pushState(new Menu(this)); 
}

Game::~Game()
{
    while (!m_States.empty())
    {
	    popState();
    }
}

void Game::render(sf::RenderTarget &window)
{
    this->player->render(window);
}

sf::RenderWindow *Game::get_window()
{
    return &this->window;
}

const std::string Game::get_name_of_window()
{
    return s_Name;
}

void Game::run()
{   
    sf::Event event;
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / Game::s_MaxFPS);
    while(this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            this->peekState()->handleEvent(event);
        } 
        peekState()->update(timePerFrame);
    }
}

void Game::pushState(State* state)
{
	this->m_States.push(state);
}

State* Game::peekState() const
{
	if (this->m_States.empty())
		return nullptr;

	return this->m_States.top();
}

void Game::popState()
{
	delete this->m_States.top();
	this->m_States.pop();
}

void Game::changeState(State* state)
{
	if (!this->m_States.empty())
		this->popState();
	this->pushState(state);
}

void Game::returnToMain()
{
	while (this->m_States.size() > 1)
		this->popState();
}