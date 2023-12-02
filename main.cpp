#include "./src/Window/Window.h"
#include "./src/Player_source/Player/Player.h"


void game_start();

void options();

void about_game();



int main() 
{   
    srand(time(static_cast<unsigned>(0)));

    sf::RenderWindow main_window;
    sf::VideoMode desktop;
    sf::Event event;

    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;
    desktop = sf::VideoMode::getDesktopMode();
    main_window.create(sf::VideoMode(1520, 720, desktop.bitsPerPixel), "Course Project", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    main_window.setFramerateLimit(60);
    image_bg.loadFromFile("../texture/libra.jpg");
    if(!world_background_tex.loadFromImage(image_bg))
    {
        std::cout << "File upload failed" << std::endl;
    } 
    world_background.setTexture(world_background_tex);

    std::vector<sf::String> label_menu;
    label_menu = {"Play", "Option", "About", "Exit"};

    Primary_Menu *primary_menu = new Primary_Menu(950, 100, 100, 100, label_menu);
    primary_menu->setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);
    primary_menu->AlignMenu(1);

    while(main_window.isOpen())
    {
        sf::Event event;
        while (main_window.pollEvent(event))
        {

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Escape) { main_window.close(); }
                if (event.key.code == sf::Keyboard::Up) {  primary_menu->MoveUp(); }       
                if (event.key.code == sf::Keyboard::Down) {  primary_menu->MoveDown(); } 
                if (event.key.code == sf::Keyboard::Return)                                    
                {

                    switch (primary_menu->getSelectedMenuNumber())
                    {
                    case 0:game_start();  break;
                    case 1:options();     break;
                    case 2:about_game();  break;
                    case 3:main_window.close(); break;
                    default:break;
                    }
                }
            }

        } 
        main_window.clear();
        main_window.draw(world_background);
        primary_menu->draw(main_window);
        main_window.display();  
    }
    return 0;
}




void game_start()
{
    sf::RenderWindow game_start_window;
    sf::VideoMode desktop;
    sf::Event event;

    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;
    desktop = sf::VideoMode::getDesktopMode();
    game_start_window.create(sf::VideoMode(1520, 720, desktop.bitsPerPixel), "Game_start", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    game_start_window.setFramerateLimit(60);
    image_bg.loadFromFile("../texture/libra.jpg");
    if(!world_background_tex.loadFromImage(image_bg))
    {
        std::cout << "File upload failed" << std::endl;
    } 
    world_background.setTexture(world_background_tex);


    Player player;
    while (game_start_window.isOpen())
    {
        sf::Event event_play;
        while (game_start_window.pollEvent(event_play))
        {
            if (event_play.type == sf::Event::KeyPressed)
            {
                if (event_play.key.code == sf::Keyboard::Escape) { game_start_window.close(); }
            }
        }
        game_start_window.clear();
        game_start_window.draw(world_background);
        player.render(game_start_window);
        game_start_window.display();
    }


};

void options()
{
    sf::RenderWindow options_window;
    sf::VideoMode desktop;
    sf::Event event;

    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;
    desktop = sf::VideoMode::getDesktopMode();
    options_window.create(sf::VideoMode(1520, 720, desktop.bitsPerPixel), "Course Project", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    options_window.setFramerateLimit(60);
    image_bg.loadFromFile("../texture/libra.jpg");
    if(!world_background_tex.loadFromImage(image_bg))
    {
        std::cout << "File upload failed" << std::endl;
    } 
    world_background.setTexture(world_background_tex);

    std::vector<sf::String> label_menu;
    label_menu = {"Color Selection", "Music"};

    Primary_Menu *primary_menu = new Primary_Menu(950, 100, 100, 100, label_menu);
    primary_menu->setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);
    primary_menu->AlignMenu(1.5);


    while (options_window.isOpen())
    {
        sf::Event event_play;
        while (options_window.pollEvent(event_play))
        {
            if (event_play.type == sf::Event::KeyPressed)
            {
                if (event_play.key.code == sf::Keyboard::Escape) { options_window.close(); }
                if (event_play.key.code == sf::Keyboard::Up) {  primary_menu->MoveUp(); }       
                if (event_play.key.code == sf::Keyboard::Down) {  primary_menu->MoveDown(); } 
                if (event_play.key.code == sf::Keyboard::Return)                                    
                {

                    switch (primary_menu->getSelectedMenuNumber())
                    {
                    // case 0:game_start();  break;
                    // case 1:options();     break;
                    // case 2:about_game();  break;
                    case 3:options_window.close(); break;
                    default:break;
                    }
                }
            }
            
        }
        options_window.clear();
        options_window.draw(world_background);
        primary_menu->draw(options_window);
        options_window.display();
    }

};

void about_game()
{
    sf::RenderWindow about_game_window;
    sf::VideoMode desktop;
    sf::Event event;

    sf::Texture world_background_tex;
    sf::Sprite world_background;
    sf::Image image_bg;
    desktop = sf::VideoMode::getDesktopMode();
    about_game_window.create(sf::VideoMode(1520, 720, desktop.bitsPerPixel), "Course Project", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    about_game_window.setFramerateLimit(60);
    image_bg.loadFromFile("../texture/libra.jpg");
    if(!world_background_tex.loadFromImage(image_bg))
    {
        std::cout << "File upload failed" << std::endl;
    } 
    world_background.setTexture(world_background_tex);

    std::vector<sf::String> label_menu;
    label_menu = {"this is my coursework"};

    Primary_Menu *primary_menu = new Primary_Menu(950, 100, 100, 100, label_menu);
    primary_menu->setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);
    primary_menu->AlignMenu(1);




    while (about_game_window.isOpen())
    {
        sf::Event event_play;
        while (about_game_window.pollEvent(event_play))
        {
            if (event_play.type == sf::Event::KeyPressed)
            {
                if (event_play.key.code == sf::Keyboard::Escape) { about_game_window.close(); }
            }
        }
        about_game_window.clear();
        about_game_window.draw(world_background);
        primary_menu->draw(about_game_window);
        about_game_window.display();
    }
};
