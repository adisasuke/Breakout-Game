#include<iostream>
#include"brick.h"

sf::Texture brick::texture;

void brick::set_strenth(int s){ brick_strength = s;}
void brick::weaken(){ --brick_strength; }
bool brick::is_weaken() { return brick_strength <= 0; }

sf::Color dull{255,0,0,50};
sf::Color med{255,0,0,150};
sf::Color dark{255,0,0,255};

brick::brick(float x,float y):destroyed{false}
{
    if(!texture.loadFromFile("./brick01.png"))
    {
        std::cout<<"Unable to load brick image"<<std::endl;
    }    
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    sprite.setOrigin(get_center());
}


void brick::update(){

    if(brick_strength == 1)
        sprite.setColor(dull);
    else if(brick_strength == 2)
        sprite.setColor(med);
    else if(brick_strength == 3)
        sprite.setColor(dark);

}

void brick::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

bool brick::isdestroyed() const
{
    return destroyed;
}

void brick::destroy(){
    destroyed=true;
}
