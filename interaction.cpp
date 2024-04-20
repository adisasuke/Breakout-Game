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

    if(isInteraction(b,br))
    {

        br.destroy();

        float left_overlap = b.right() - br.left();
        float right_overlap = br.right() - b.left();
        float top_overlap = b.bottom() - br.top();
        float bottom_overlap = br.bottom() - b.top();

        bool from_left = left_overlap < right_overlap;
        bool from_bottom = bottom_overlap < top_overlap;


        float min_x_overlap = from_left ? left_overlap : right_overlap;
        float min_y_overlap = from_bottom ? bottom_overlap : top_overlap;


        if(min_x_overlap < min_y_overlap)
        {
            if(from_left)
                b.move_left();
            else
                b.move_right();
        }
        else
        {
            if(from_bottom)
                b.move_down();
            else
                b.move_up();

        }

    }
    
}