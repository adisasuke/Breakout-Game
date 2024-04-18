#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>
#include"entity.h"

class ball : public moving_entity{
    private:
    static sf::Texture texture;

    public:
    ball(float height,float width);
    void update() override;
    void draw(sf::RenderWindow &window) override;

    void move_up() override;
    void move_down() override;
    void move_left() override;
    void move_right() override;

};




#endif