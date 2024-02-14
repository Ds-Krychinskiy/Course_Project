#include "./Button.h"

Button::Button()
{
		// set default color
	this->m_InnerButton.setFillColor(sf::Color(175, 28, 122));
	this->m_OuterButton.setFillColor(sf::Color(237, 255, 104));

	// set default font
	// this->m_Label.getText().setFont(ResourceManager::getInstance().getFont(res::Font::Roboto));

	// set default m_Text color
	this->m_Label.getText().setFillColor(sf::Color::White);

	// set default size
	setSize(sf::Vector2f(300, 50));

	this->m_Alignment = Alignment::Center;

	setPosition(sf::Vector2f(50, 50));
}

Button::~Button()
{

}

void Button::setAlignment(Button::Alignment alignment)
{
	this->m_Alignment = alignment;
}

// void Button::setFont(res::Font font)
// {
// 	m_Label.getText().setFont(ResourceManager::getInstance().getFont(font));
// }
void Button::setAction(std::function<void()> actionToDo)
{
	this->m_ActionToDo = actionToDo;
}


void Button::setPosition(sf::Vector2f position)
{
	// m_OuterButton.setPosition(position);
	// m_InnerButton.setPosition(position.x + m_OuterLineSize, position.y + m_OuterLineSize);

	// float x = 0.f;
	// float y = 0.f;

	// if (m_Alignment == Alignment::Center)
	// {
	// 	x = m_InnerButton.getPosition().x + m_InnerButton.getGlobalBounds().width / 2
	// 		- m_Label.getText().getGlobalBounds().width / 2;
	// 	y = m_InnerButton.getPosition().y + m_InnerButton.getGlobalBounds().height / 2
	// 		- m_Label.getText().getGlobalBounds().height;
	// }
	// else if (m_Alignment == Alignment::Left)
	// {
	// 	x = m_InnerButton.getPosition().x + m_OffsetFromEdge;
	// 	y = m_InnerButton.getPosition().y + m_InnerButton.getGlobalBounds().height / 2
	// 		- m_Label.getText().getGlobalBounds().height;
	// }
	// else if (m_Alignment == Alignment::Right)
	// {
	// 	x = m_InnerButton.getPosition().x + m_InnerButton.getGlobalBounds().width
	// 		- m_Label.getText().getGlobalBounds().width - m_OffsetFromEdge;
	// 	y = m_InnerButton.getPosition().y + m_InnerButton.getGlobalBounds().height / 2
	// 		- m_Label.getText().getGlobalBounds().height;
	// }

	// m_Label.getText().setPosition(x, y);
}


void Button::setSize(sf::Vector2f size)
{
	// m_OuterButton.setSize(size);
	// m_InnerButton.setSize(size - sf::Vector2f(m_OuterLineSize * 2, m_OuterLineSize * 2));
	// m_Label.getText().setCharacterSize(m_InnerButton.getSize().y - 2);
	// setPosition(m_OuterButton.getPosition());
}

void Button::setInnerColor(sf::Color color)
{
	this->m_InnerButton.setFillColor(color);
}

void Button::setOutlineColor(sf::Color color)
{
	m_OuterButton.setFillColor(color);
}


void Button::setTextColor(sf::Color color)
{
	this->m_Label.getText().setFillColor(color);
}
void Button::setText(std::string text)
{
	this->m_Label.getText().setString(text);
	// We should update the position since m_Text size changed
	this->setPosition(m_OuterButton.getPosition());
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_OuterButton);
	target.draw(m_InnerButton);
	target.draw(m_Label);
}

void Button::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (this->m_OuterButton.getGlobalBounds().contains(
				sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
		{
			if (this->m_ActionToDo)
			{
				this->m_ActionToDo();
			}
			else
			{
			}
		}
	}
}