#include "background.h"
#include "iostream"

sf::Texture background::texture;
void background::update()
{

}

void background::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

background::background()
{
    std::cout<<"this code is running"<<std::endl;
    if(!texture.loadFromFile("./sas.jpg",sf::IntRect(10,10,800,600)))
    {
        std::cout<<"Unable to load image in texture please check "<<std::endl;
    }
    sprite.setTexture(texture);

}
