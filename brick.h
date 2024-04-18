#ifndef BRICK_H
#define BRICK_H
#include "entity.h"


class brick : public entity{
    private:
    static sf::Texture texture;

    public:
    brick(float x,float y);
    void update() override;
    void draw(sf::RenderWindow &window) override;

};

#endif