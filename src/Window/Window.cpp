#include "./Window.h"

Windows::Windows()
{
    this->desktop = sf::VideoMode::getDesktopMode();
    this->window.create(sf::VideoMode(1520, 720, desktop.bitsPerPixel), "Course Project", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    this->window.setFramerateLimit(60);
    this->image_bg.loadFromFile("../texture/libra.jpg");
    if(!this->world_background_tex.loadFromImage(this->image_bg))
    {
        std::cout << "File upload failed" << std::endl;
    } else
    {
        std::cout << !this->world_background_tex.loadFromFile("texture/libra.jpg") << std::endl;
    }
    this->world_background.setTexture(this->world_background_tex);
    this->label_menu = {"Play", "Option", "About", "Exit"};
    this->primary_menu = new Primary_Menu(950, 100, 100, 100,this->label_menu);
    this->primary_menu->setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);
    this->primary_menu->AlignMenu(1);
}


Windows::~Windows()
{

}

const sf::RenderWindow &Windows::getWindows() const
{
    return this->window;
}

void Windows::update()
{
    while(this->window.pollEvent(this->event))
    {
        if(this->event.type == sf::Event::Closed)
        {
            this->window.close();
        }
    //     if (event.type == sf::Event::Resized)
    //     {
    //         sf::FloatRect visibleArea({0, 0}, {static_cast<float>(event.size.width), static_cast<float>(event.size.height)});
    //         this->window.setView(sf::View(visibleArea));
    //     }
    // }
    }
}


void Windows::render()
{
    this->window.clear();
    this->window.draw(this->world_background);
    this->primary_menu->draw(this->window);
    this->player.render(this->window);
    this->window.display();
}
