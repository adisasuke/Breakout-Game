#include<iostream>
#include"brick.h"

sf::Texture brick::texture;


brick::brick(float x,float y){
    if(!texture.loadFromFile("./brick01.png"))
    {
        std::cout<<"Unable to load brick image"<<std::endl;
    }    
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    sprite.setOrigin(get_center());
}


void brick::update(){

}

void brick::draw(sf::RenderWindow &window){
    window.draw(sprite);
}