#include <iostream>
#include "paddle.h"
#include "constants.h"

sf::Texture paddle::texture;

paddle::paddle(float x,float y){

    if(!texture.loadFromFile("./paddle.png")){
        std::cout<<"Unable to load paddle image "<<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x,y);    
    sprite.setOrigin(get_center());
}


void paddle::update()
{
    process_player_input();
    sprite.move(velocity);
}

void paddle::process_player_input(){


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(x()>=0)
            velocity = {-constants::paddle_speed,0.0f};
        else
            velocity = {0.0f,0.0f}; 
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(x()<constants::window_width)
            velocity = {constants::paddle_speed,0.0f};
        else
            velocity = {0.0f,0.0f};
    }
    else
    {
        velocity = {0.0f,0.0f};
    }
    
}

void paddle::draw(sf::RenderWindow &window){
    window.draw(sprite);
}