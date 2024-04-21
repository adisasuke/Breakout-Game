#ifndef BRICK_H
#define BRICK_H
#include "entity.h"
#include "constants.h"

class brick : public entity{
    private:
    static sf::Texture texture;
    int brick_strength{constants::brick_strength};
    bool destroyed;

    public:
    brick(float x,float y);
    void update() override;
    void draw(sf::RenderWindow &window) override;
    bool isdestroyed() const;
    void destroy();
    
    void set_strenth(int s);
    void weaken();
    bool is_weaken();

};

#endif