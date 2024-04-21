#include "game.h"

game::game()
{

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

}

void game::reset()
{

    for(int i=0;i<constants::brick_rows;i++)
    {
        for(int j=0;j<constants::brick_columns;j++)
        {
            float x = constants::brick_width + constants::brick_offset + j*constants::brick_width;
            float y = constants::brick_height + i*constants::brick_height;
            bricks.emplace_back(x,y);
        }
    }

}

void game::run()
{


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

        //use p to pause/unpause the game
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if(!pauseactive)
            {
                if(current_state == game_state::running)
                    current_state = game_state::paused;
                else
                    current_state = game_state::running;
            }   
            pauseactive=true;         

        }
        else
            pauseactive=false;    



        if(current_state==game_state::running)
        {
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

            for(auto &b:bricks)
            {
                b.update();
            }
            
            bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks),
            [](const brick& br) { return br.isdestroyed();}),
            std::end(bricks));

            if(bricks.size()==0)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            reset();

        bg.draw(window);
        b.draw(window);
        p.draw(window);


        for(auto b:bricks)
        {
            b.draw(window);
        }

        window.display();

    }

}

