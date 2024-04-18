#include "interaction.h"


bool isInteraction(entity& a,entity &b)
{
    auto box1 = a.get_bounding_box();
    auto box2 = b.get_bounding_box();
    return box1.intersects(box2);
}

void handleCollision(ball& b,paddle& p){

    if(isInteraction(b,p))
    {
        b.move_up();

        if(b.x()<p.x())
        {
            b.move_left();
        }
        else
        {
            b.move_right();
        }

    }
}

void handleCollision(ball& b,brick &br){
    
}