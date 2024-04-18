#include"entity.h"


float entity::x()
{
    return sprite.getPosition().x;
}


float entity::y()
{
    return sprite.getPosition().y;
}

sf::FloatRect entity::get_bounding_box()
{
    return sprite.getGlobalBounds();
}

sf::Vector2f entity::get_center()
{
    auto box = get_bounding_box();
    return {box.width/2.0f,box.height/2.0f};
}

float entity::left()
{
    auto box = get_bounding_box();
    return x() - box.width/2.0f;
}


float entity::right()
{
    auto box = get_bounding_box();
    return x() + box.width/2.0f;
}

float entity::top()
{
    auto box = get_bounding_box();
    return y() - box.height/2.0f;
}

float entity::bottom()
{
    auto box = get_bounding_box();
    return y() + box.height/2.0f;
}