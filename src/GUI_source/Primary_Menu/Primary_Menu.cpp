#include "./Primary_Menu.h"


void Primary_Menu::setInitText(sf::Text& text, const sf::String& str, float xpos, float ypos) const
{
	text.setFont(this->font);
	text.setFillColor(this->menu_text_color);
	text.setString(str);
	text.setCharacterSize(this->size_font);
	text.setPosition(xpos, ypos);
	text.setOutlineThickness(3);
	text.setOutlineColor(this->border_color);
}

Primary_Menu::~Primary_Menu()
{
}

void Primary_Menu::AlignMenu(int posx)
{

	float nullx = 0;

	for (int i = 0; i < this->max_menu; i++) {

		switch (posx)
		{
		case 0:
			nullx = 0;
			break;
		case 1:
			nullx = this->mainMenu[i].getLocalBounds().width;
			break;
		case 2:
			nullx = this->mainMenu[i].getLocalBounds().width / 2;
			break;
		default:break;
		}

		this->mainMenu[i].setPosition(mainMenu[i].getPosition().x - nullx, this->mainMenu[i].getPosition().y);
	}

}


void Primary_Menu::MoveUp()
{
	this->mainMenuSelected--;

	if (this->mainMenuSelected >= 0) {
		this->mainMenu[mainMenuSelected].setFillColor(this->chose_text_color);
		this->mainMenu[mainMenuSelected + 1].setFillColor(this->menu_text_color);
	}
	else
	{
		this->mainMenu[0].setFillColor(this->menu_text_color);
		this->mainMenuSelected = this->max_menu - 1;
		this->mainMenu[mainMenuSelected].setFillColor(this->chose_text_color);
	}
}

void Primary_Menu::MoveDown()
{
	this->mainMenuSelected++;

	if (this->mainMenuSelected < max_menu) {
		this->mainMenu[mainMenuSelected - 1].setFillColor(this->menu_text_color);
		this->mainMenu[mainMenuSelected].setFillColor(this->chose_text_color);
	}
	else
	{
		this->mainMenu[max_menu - 1].setFillColor(this->menu_text_color);
		this->mainMenuSelected = 0;
		this->mainMenu[mainMenuSelected].setFillColor(this->chose_text_color);
	}

}


void Primary_Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < this->max_menu; i++) window.draw(this->mainMenu[i]);
}


void Primary_Menu::setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor)
{
	this->menu_text_color = menColor;
	this->chose_text_color = ChoColor;
	this->border_color = BordColor;

	for (int i = 0; i < this->max_menu; i++) {
		this->mainMenu[i].setFillColor(this->menu_text_color);
		this->mainMenu[i].setOutlineColor(this->border_color);
	}

	this->mainMenu[mainMenuSelected].setFillColor(this->chose_text_color);
}


Primary_Menu::Primary_Menu(float menux, float menuy, int sizeFont, int step, std::vector<sf::String>& name)
    :menu_X(menux), menu_Y(menuy), menu_Step(step), max_menu(static_cast<int>(name.size())), size_font(sizeFont), mainMenu(name.size())
{   
	this->load_font_from_file();

	for (int i = 0, ypos = static_cast<int>(this->menu_Y); i < this->max_menu; i++, ypos += this->menu_Step)
    {
		this->setInitText(this->mainMenu[i], name[i], this->menu_X, static_cast<float>(ypos));
    }
	this->mainMenuSelected = 0;
	this->mainMenu[mainMenuSelected].setFillColor(this->chose_text_color);
}



int Primary_Menu::getSelectedMenuNumber() const
{
    return this->mainMenuSelected;
}

void Primary_Menu::load_font_from_file()
{
	if(!this->font.loadFromFile("../fonts/font.ttf"))
    {
        std::cout << "in Primary_Menu construction" << std::endl;
    }
};
