#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

#include "bat.h"
#include "hud.h"
#include "ball.h"
#include "input_util.h"

using namespace sf;

void handleInput(RenderWindow &window, Bat &bat)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (userWantsToQuit(event))
        {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }
    }
}

int main()
{

    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Pong", Style::Fullscreen);

    int score{0};
    int lives{3};

    Bat bat(1920.0f / 2, 1080.0f - 20);
    Hud hud("../fonts/positive_system.otf");
    Ball ball(1920.0f / 2, 0);

    Clock clock;

    while (window.isOpen())
    {
        /* Handle input */
        handleInput(window, bat);

        /* Update */
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);
        std::stringstream hud_text;
        hud_text << "Score " << score << "    Lives " << lives;
        hud.setString(hud_text.str());

        // handle ball hitting the bottom
        if (ball.getPosition().top > window.getSize().y)
        {
            ball.reboundBottom();

            lives--;

            if (lives < 1)
            {
                score = 0;
                lives = 3;
                ball.resetSpeed();
            }
        }

        // handle the ball hitting top
        if (ball.getPosition().top < 0)
        {
            ball.reboundBatOrTop();
            score++;
        }

        // handle ball hitting sides
        if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x)
        {
            ball.reboundSides();
        }

        // handle ball hitting bat
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundBatOrTop();
            bat.playHitSound();
        }

        /* Draw */
        window.clear();
        window.draw(hud.getText());
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}