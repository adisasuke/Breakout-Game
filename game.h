#include <iostream>
#include <SFML/Graphics.hpp>
#include "background.h"
#include "constants.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include "interaction.h"

enum game_state {paused,running};

class game{
    private:
    background bg(0.0f,0.0f);
    ball b(constants::window_width/2.0f,constants::window_height/2.0f);
    paddle p(constants::window_width,constants::window_height - constants::paddle_height);

    sf::RenderWindow window(sf::VideoMode(constants::window_width,constants::window_height),"Welcome to Adi's Game");
    std::vector<brick> bricks;

    bool pauseactive{false};
    game_state current_state(game_state::running);
    public:
    game();
    void run();
    void reset();

};