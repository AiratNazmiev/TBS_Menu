//
// Created by airat on 29.04.2020.
//

#ifndef TBS_TEXTBOX_H
#define TBS_TEXTBOX_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

// Define keys:
static const int DELETE_KEY = 8;
static const int ENTER_KEY = 13;
static const int ESCAPE_KEY = 27;

static const int max_string_length = 15;

class Textbox : public sf::Drawable {
public:
    Textbox(const std::string &texture_file,
            const sf::IntRect &dimensions,
            const std::string &font_file,
            int size,
            const sf::Color &color,
            bool sel,
            const std::string &default_str);

    // Make sure font is passed by reference:
    void setFont(const sf::Font &fonts);

    void setPosition(const sf::Vector2f &point);

    // Set char limits:
    void setLimit(bool ToF);

    void setLimit(bool ToF, int lim);

    // Change selected state:
    void setSelected(bool sel);

    bool getSelected() const;

    sf::IntRect getDimensions() const;

    std::string getText();

    void drawTo(sf::RenderWindow &window) const;

    virtual void draw(sf::RenderTarget &render, sf::RenderStates states) const override;

    // Function for event loop:
    void typedOn(sf::Event input);

private:
    sf::Text textbox_;
    sf::IntRect dimensions_;

    sf::Texture texture_;
    sf::Sprite sprite_;

    sf::Font font_;
    std::string text_;

    bool isSelected_ = false;
    bool hasLimit_ = false;
    int limit_ = 0;

    // Delete the last character of the text_:
    void deleteLastChar();

    // Get user input:
    void inputLogic(int charTyped);
};


#endif //TBS_TEXTBOX_H
