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

};




#endif