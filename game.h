//
// Created by airat on 09.03.2020.
//

#ifndef TBS_GAME_H
#define TBS_GAME_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

class Game : private sf::NonCopyable {
public:
    Game();

    void run();

private:
    void processEvents();

    void update(sf::Time deltaTime);

    void render();

    void updateStatistics(sf::Time elapsedTime);

    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    void handleMouse(sf::Mouse::Button button);

private:
    //static const float PlayerSpeed;
    static const sf::Time TimePerFrame;

    const unsigned WINDOW_HEIGHT = 720;
    const unsigned WINDOW_WIDTH = 1080;

    sf::RenderWindow mWindow;
    //sf::Texture mTexture;
    //sf::Sprite mPlayer;
    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;

    std::size_t mStatisticsNumFrames;
    //bool mIsMovingUp;
    //bool mIsMovingDown;
    //bool mIsMovingRight;
    //bool mIsMovingLeft;

    Menu menu_window_;

    bool menu_;
    bool playing_;
};


#endif //TBS_GAME_H
