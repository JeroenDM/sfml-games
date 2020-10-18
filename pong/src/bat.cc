#include "bat.h"

Bat::Bat(float start_x, float start_y)
{
    position_.x = start_x;
    position_.y = start_y;

    shape_.setSize(sf::Vector2f(50, 5));
    shape_.setPosition(position_);
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