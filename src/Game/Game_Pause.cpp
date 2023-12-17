#include "./Game_Pause.h"


Game_Pause::Game_Pause(Game* game) : State(game)
{
	m_TitleLabel.getText().setString(Game::get_name_of_window());
	m_TitleLabel.getText().setFont(ResourceManager::getInstance().getFont(res::Font::Pixel));
	m_TitleLabel.getText().setCharacterSize(50);
	m_TitleLabel.getText().setPosition(m_Game->get_window().getSize().x / 2.f
			- m_TitleLabel.getText().getGlobalBounds().width / 2.f,
		20.f);

	m_BackgroundTexture =
		ResourceManager::getInstance().getTexture(res::Texture::PauseBackground);
	m_BackgroundTexture.setRepeated(true);
	m_Background.setTexture(m_BackgroundTexture);
	m_Background.setScale(1.5, 1.5);

	m_ContinueButton.setText("continue");
	m_ContinueButton.setFont(res::Font::Roboto);
	m_ContinueButton.setAlignment(Button::Alignment::Center);
	m_ContinueButton.setSize(sf::Vector2f(200, 30));
	m_ContinueButton.setPosition(sf::Vector2f(m_Game->get_window().getSize().x / 2.f
			- m_ContinueButton.getGlobalBounds().width / 2.f,
		100));
	m_ContinueButton.setAction([&]() {
		std::cerr << "Switch back to GameState : Continue the game" << std::endl;
		m_Game->popState();
		throw bool{ false };
	});

	m_MainMenuButton.setText("exit to mainmenu");
	m_MainMenuButton.setFont(res::Font::Roboto);
	m_MainMenuButton.setAlignment(Button::Alignment::Center);
	m_MainMenuButton.setSize(sf::Vector2f(200, 30));
	m_MainMenuButton.setPosition(sf::Vector2f(m_Game->get_window().getSize().x / 2.f
			- m_MainMenuButton.getGlobalBounds().width / 2.f,
		200));
	m_MainMenuButton.setAction([&]() { m_Game->returnToMain(); });
}

void Game_Pause::render()
{
	m_Game->get_window().clear();
	m_Game->get_window().draw(m_Background);
	m_Game->get_window().draw(m_ContinueButton);
	m_Game->get_window().draw(m_MainMenuButton);
	m_Game->get_window().draw(m_TitleLabel);
	m_Game->get_window().display();
}

void Game_Pause::update(sf::Time deltaTime)
{
	m_Game->get_window().setView(m_Game->get_window().getDefaultView());
}

void Game_Pause::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		m_Game->get_window().close();
	}
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			std::cerr << "Switch back to GameState : Continue the game" << std::endl;
			m_Game->popState();
			return;
		}
	}
	try
	{
		m_ContinueButton.handleEvent(event);
		m_MainMenuButton.handleEvent(event);
	}
	catch (bool e)
	{
		return;
	}
}
