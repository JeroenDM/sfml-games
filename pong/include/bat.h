#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Bat
{
private:
    sf::Vector2f position_;
    sf::RectangleShape shape_;
    sf::SoundBuffer sound_buffer_;
    sf::Sound sound_;

    float speed_{1000.0f};
    bool moving_right_{false};
    bool moving_left_{false};

    public:
    Bat(float start_x, float start_y);

    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void playHitSound();

    void update(sf::Time dt);
};