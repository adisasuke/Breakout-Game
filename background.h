#ifndef BACKGROUND_h
#define BACKGROUND_h
#include<SFML/Graphics.hpp>
#include"entity.h"


class background : public entity{
    private:
    static sf::Texture texture;
    public:
    background(float x,float y);
    void update() override;
    void draw(sf::RenderWindow &window) override;


};

#endif