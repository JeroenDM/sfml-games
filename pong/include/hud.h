#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class Hud
{
private:
    sf::Text text_;
    sf::Font font_;

public:
    Hud(const std::string &font_file_path);
    void setString(const std::string& str);
    sf::Text getText();
};