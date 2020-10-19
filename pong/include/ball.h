#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Ball
{
private:
    sf::Vector2f position_;
    sf::CircleShape shape_;
    sf::SoundBuffer sound_buffer_;
    sf::Sound sound_;

    const float initial_speed_{3000.0f};
    float speed_{initial_speed_};
    float direction_x_{0.2f};
    float direction_y_{0.2f};

public:
    Ball(float start_x_, float start_y_);
    void update(sf::Time dt);

    sf::FloatRect getPosition();
    sf::CircleShape getShape();
    float getXVelocity();

    void reboundSides();
    void reboundBatOrTop();
    void reboundBottom();
    void playHitWallSound();
    void resetSpeed();
};