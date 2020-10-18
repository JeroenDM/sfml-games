#pragma once

#include <SFML/Window.hpp>

bool userWantsToQuit(sf::Event event)
{
    if (event.type == sf::Event::Closed)
    {
        return true;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return true;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        return true;
    }
    else
    {
        return false;
    }
}