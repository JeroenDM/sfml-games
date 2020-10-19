#include "bat.h"

Bat::Bat(float start_x, float start_y) : position_(start_x, start_y)
{
    shape_.setSize(sf::Vector2f(200, 20));
    shape_.setPosition(position_);

    sound_buffer_.loadFromFile("../sound/hit.wav");
    sound_.setBuffer(sound_buffer_);
}

void Bat::update(sf::Time dt)
{
    if (moving_right_)
    {
        position_.x += speed_ * dt.asSeconds();
    }
    if (moving_left_)
    {
        position_.x -= speed_ * dt.asSeconds();
    }

    shape_.setPosition(position_);
}

sf::FloatRect Bat::getPosition()
{
    return shape_.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
    return shape_;
}

void Bat::moveLeft()
{
    moving_left_ = true;
}

void Bat::moveRight()
{
    moving_right_ = true;
}

void Bat::stopLeft()
{
    moving_left_ = false;
}

void Bat::stopRight()
{
    moving_right_ = false;
}

void Bat::playHitSound()
{
    sound_.play();
}