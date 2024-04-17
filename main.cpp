#include <iostream>
#include <SFML/Graphics.hpp>
#include "background.h"


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(800,600),"My world");
    background bg;

    while(window.isOpen())
    {


        sf::Event event;

        while(window.pollEvent(event))
        {
            if( event.type == sf::Event::Closed )// also add event for keyboard escape to exit
                window.close();

        }
        window.clear(sf::Color::Black);
        bg.update();
        bg.draw(window);
        window.display();


    }


    return 0;
}
