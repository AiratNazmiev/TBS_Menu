//
// Created by airat on 09.03.2020.
//

#ifndef TBS_GAME_H
#define TBS_GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Field_draw.h"
#include "hexagonal_tile.h"
#include "Prim_game.hpp"

class Game : private sf::NonCopyable {
public:
    Game();

    void run();

private:
    void processEvents();

    void update();

    void render();

    void updateStatistics(sf::Time elapsedTime);

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    void handleMouse(sf::Mouse::Button button);

private:
    static const sf::Time TimePerFrame;
    const unsigned WINDOW_HEIGHT = 720;
    const unsigned WINDOW_WIDTH = 1080;

    sf::RenderWindow mWindow;
    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;

    std::size_t mStatisticsNumFrames;

    Menu menu_window_;
    gm::Field field_;
    Field_draw field_window_;

    //
    //hexagonal_tile hex_;
    //

    bool menu_;
    bool playing_;
};


#endif //TBS_GAME_H
