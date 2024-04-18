#include <iostream>

#include "ball.h"
#include "constants.h"

sf::Texture ball::texture;



void ball::move_up()
{
    velocity.y = -constants::ball_speed;
}


void ball::move_down()
{
    velocity.y = constants::ball_speed;
}


void ball::move_left()
{
    velocity.x = -constants::ball_speed;
}

void ball::move_right()
{
    velocity.x = constants::ball_speed;
}






ball::ball(float x,float y)
{
    velocity = {constants::ball_speed,constants::ball_speed};
    if(!texture.loadFromFile("./ball.png"))
    {
        std::cout<<"Unable to load image in texture please check "<<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x,y);


}




void ball::update()
{
    sprite.move(velocity);

    if(x() < 0)
        velocity.x = -velocity.x;
    if(x() > constants::window_width)
        velocity.x = -velocity.x;
    if(y() < 0)
        velocity.y = -velocity.y;
    if(y() > constants::window_height)
        velocity.y = -velocity.y;


}


void ball::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}