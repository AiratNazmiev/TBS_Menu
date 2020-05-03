//
// Created by airat on 09.03.2020.
//

#include "game.h"

#include <SFML/Graphics.hpp>
#include <iostream>

//const float Game::PlayerSpeed = 500.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML App", sf::Style::Close),
               mFont(),
               mStatisticsText(),
               mStatisticsUpdateTime(),
               mStatisticsNumFrames(0),
               menu_(true),
               playing_(false),
               menu_window_("../Media/background_menu_sunset.png",
                            {{
                                     "../Media/connect_button.png",
                                     "../Media/create_button.png",
                                     "../Media/exit_button.png",
                                     "../Media/nickname_textbox.png",
                                     "../Media/ip_textbox.png"
                             }},
                            {{
                                     {sf::IntRect{{440, 450},
                                                  {200, 50}}},
                                     {sf::IntRect{{440, 520},
                                                  {200, 50}}},
                                     {sf::IntRect{{440, 590},
                                                  {200, 50}}},
                                     {sf::IntRect{{800, 100},
                                                  {250, 30}}},
                                     {sf::IntRect{{30,  100},
                                                  {250, 30}}}
                             }},
                            {{
                                     "../Media/Chilanka-Regular.ttf",
                                     "../Media/Chilanka-Regular.ttf"
                             }},
                            {
                                    18,
                                    18
                            },
                            {
                                    sf::Color::Black,
                                    sf::Color::Black
                            },
                            {
                                    false,
                                    false
                            },
                            {
                                    "127.0.0.1",
                                    "Enter Nickname"
                            }
               ) {

    // font for fps

    if (!mFont.loadFromFile("../Media/Sansation.ttf")) {
        throw std::runtime_error("Cannot load font");
    }

    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(0.f, 0.f);
    mStatisticsText.setCharacterSize(10);

    //
}

void Game::run() {
    sf::Clock clock{};
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (mWindow.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            update(TimePerFrame);
        }

        updateStatistics(elapsedTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event{};

    while (mWindow.pollEvent(event)) {

        switch (event.type) {
            case sf::Event::MouseButtonPressed:
                handleMouse(event.mouseButton.button);
                break;
            case sf::Event::TextEntered: // (!) goes before keyPressed
                if (menu_) {
                    if (menu_window_.textbox_nickname.getSelected()) {
                        menu_window_.textbox_nickname.typedOn(event);
                    }

                    if (menu_window_.textbox_ip.getSelected()) {
                        menu_window_.textbox_ip.typedOn(event);
                    }
                    break;
                }
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    if (playing_) {
        //
    } else if (menu_) {
        //menu
    }
}

void Game::render() {
    mWindow.RenderWindow::setVerticalSyncEnabled(true);
    mWindow.clear();

    if (playing_) {

        mWindow.draw(mStatisticsText);
    } else if (menu_) {
        mWindow.draw(menu_window_);
    }

    mWindow.RenderWindow::display();
}

void Game::updateStatistics(sf::Time elapsedTime) {
    if (playing_) {
        mStatisticsUpdateTime += elapsedTime;
        ++mStatisticsNumFrames;

        if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
            mStatisticsText.setString(
                    "FPS: " + std::to_string(mStatisticsNumFrames) + "\n" +
                    "ping: " + std::to_string(mStatisticsUpdateTime.asMilliseconds() / mStatisticsNumFrames) +
                    "ms"
            );
            mStatisticsUpdateTime -= sf::seconds(1.0f);
            mStatisticsNumFrames = 0;
        }
    } else if (menu_) {
        //menu
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (playing_) {
        switch (key) {
            //
        }
    } else if (menu_) {
        switch (key) {
            case sf::Keyboard::Return:
                if (menu_window_.textbox_nickname.getSelected()) {
                    menu_window_.textbox_nickname.setSelected(false);
                }

                if (menu_window_.textbox_ip.getSelected()) {
                    menu_window_.textbox_ip.setSelected(false);
                }
                break;

            default:;
        }
    }
}

void Game::handleMouse(sf::Mouse::Button button) {
    if (menu_) {
        switch (button) {
            case sf::Mouse::Left:
                if (menu_window_.button_connect.getDimensions().contains(sf::Mouse::getPosition(mWindow))) {
                    menu_ = false;
                    playing_ = true;
                }

                if (menu_window_.button_create.getDimensions().contains(sf::Mouse::getPosition(mWindow))) {
                    //
                }

                if (menu_window_.button_exit.getDimensions().contains(sf::Mouse::getPosition(mWindow))) {
                    mWindow.close();
                }

                if (menu_window_.textbox_nickname.getDimensions().contains(sf::Mouse::getPosition(mWindow)) &&
                    !menu_window_.textbox_ip.getSelected()) {
                    menu_window_.textbox_nickname.setSelected(true);
                }

                if (menu_window_.textbox_ip.getDimensions().contains(sf::Mouse::getPosition(mWindow)) &&
                    !menu_window_.textbox_nickname.getSelected()) {
                    menu_window_.textbox_ip.setSelected(true);
                }
                break;

            default:;
        }
    } else if (playing_) {
        //
    }
}