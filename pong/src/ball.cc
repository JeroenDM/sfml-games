#include "ball.h"

Ball::Ball(float start_x, float start_y) : position_(start_x, start_y)
{
    shape_.setRadius(30);
    shape_.setPosition(position_);

    sound_buffer_.loadFromFile("../sound/wall_hit.wav");
    sound_.setBuffer(sound_buffer_);
}

void Ball::update(sf::Time dt)
{
    position_.x += direction_x_ * speed_ * dt.asSeconds();
    position_.y += direction_y_ * speed_ * dt.asSeconds();

    shape_.setPosition(position_);
}

sf::FloatRect Ball::getPosition()
{
    return shape_.getGlobalBounds();
}

sf::CircleShape Ball::getShape()
{
    return shape_;
}

float Ball::getXVelocity()
{
    return direction_x_;
}

void Ball::reboundSides()
{
    direction_x_ = -direction_x_;
    playHitWallSound();
}

void Ball::reboundBatOrTop()
{
    direction_y_ = -direction_y_;
    playHitWallSound();
    speed_ *= 1.01f;
}

void Ball::reboundBottom()
{
    position_.x = 500;
    position_.y = 500;
    direction_y_ = -direction_y_;
}

void Ball::playHitWallSound()
{
    sound_.play();
}

void Ball::resetSpeed()
{
    speed_ = initial_speed_;
}