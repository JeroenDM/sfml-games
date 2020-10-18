#include "hud.h"

Hud::Hud(const std::string &font_file_path)
{
    font_.loadFromFile(font_file_path);
    text_.setFont(font_);
    text_.setCharacterSize(75);
    text_.setFillColor(sf::Color::White);
    text_.setPosition(20, 20);
}

void Hud::setString(const std::string& str)
{
    text_.setString(str);
}

sf::Text Hud::getText()
{
    return text_;
}