#ifndef ENTITY_H
#define ENTITY_H


#include<SFML/Graphics.hpp>


class entity{
    protected:
    //Texture and Image combo is here 
    sf::Sprite sprite;
    public:
    //
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow &window) = 0;


    float x();
    float y();

};


class moving_entity :public entity{

 protected:
 sf::Vector2f velocity;


};

#endif



