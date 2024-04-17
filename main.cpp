#include <iostream>
#include <SFML/Graphics.hpp>
#include "background.h"
#include "constants.h"
#include "ball.h"

int main()
{
    
    background bg(0.0f,0.0f);
    ball b(constants::window_width/2.0f,constants::window_height/2.0f);

    sf::RenderWindow window(sf::VideoMode(constants::window_width,constants::window_height),"Welcome to Adi's Game");

    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        window.clear(sf::Color::Black);
        sf::Event event;

        while(window.pollEvent(event))
        {
            if( event.type == sf::Event::Closed  )
                window.close();
        }

        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
            window.close();

        bg.update();
        b.update();

 
        bg.draw(window);
        b.draw(window);
        
        window.display();

    }


    return 0;
}
