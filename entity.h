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

    //bounding box for a sprite
    sf::FloatRect get_bounding_box();


    //center of the a sprite
    sf::Vector2f get_center();
    
    float left();
    float right();
    float top();
    float bottom();


    float x();
    float y();

    virtual ~entity() {}

};


class moving_entity :public entity{

 protected:
 sf::Vector2f velocity;

 public:
 virtual void move_left() = 0;
 virtual void move_right() = 0;
 virtual void move_up() = 0;
 virtual void move_down() = 0;


};

#endif

