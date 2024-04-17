#ifndef PADDLE_H
#define PADDLE_H

#include "entity.h"

class paddle : public moving_entity{
    private:
    static sf::Texture texture;
    public:
    paddle(float x,float y);
    void update() override;
    void draw(sf::RenderWindow &window) override;
    void process_player_input();

};

#endif