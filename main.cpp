#include <iostream>
#include <SFML/Graphics.hpp>
#include "background.h"
#include "constants.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "interaction.h"


int main()
{   
    background bg(0.0f,0.0f);
    ball b(constants::window_width/2.0f,constants::window_height/2.0f);
    paddle p(constants::window_width,constants::window_height - constants::paddle_height);

    sf::RenderWindow window(sf::VideoMode(constants::window_width,constants::window_height),"Welcome to Adi's Game");
    std::vector<brick> bricks;

    for(int i=0;i<constants::brick_rows;i++)
    {
        for(int j=0;j<constants::brick_columns;j++)
        {
            float x = constants::brick_width + constants::brick_offset + j*constants::brick_width;
            float y = constants::brick_height + i*constants::brick_height;
            bricks.emplace_back(x,y);
        }
    }

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
        p.update();
 
         for(auto &b:bricks)
        {
            b.update();
        }

        handleCollision(b,p);

        for(auto &br:bricks)
        {
            handleCollision(b,br);
        }

        bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
        [](const brick& br) { return br.isdestroyed();}),
        std::end(bricks));

        bg.draw(window);
        b.draw(window);
        p.draw(window);


        for(auto b:bricks)
        {
            b.draw(window);
        }

        window.display();

    }

    return 0;
}
