#include "background.h"
#include "iostream"

sf::Texture background::texture;
void background::update()
{

}

void background::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

background::background(float x,float y)
{
    std::cout<<"this code is running"<<std::endl;
    if(!texture.loadFromFile("./background.jpg"))
    {
        std::cout<<"Unable to load image in texture please check "<<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(x,y);

}
