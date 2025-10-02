// library
#include <SFML/Graphics.hpp>
#include <iostream>

// main program
int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title");

    // create shape
    sf::RectangleShape shape({100.f, 100.f});

    // start clock
    sf::Clock clock;

    // window loop
    while (window.isOpen())
    {
        // delta time
        float dt = clock.getElapsedTime().asSeconds();
        if (dt >= 1.f / 60.f)
        {
            clock.restart();

            // handle events
            while (auto event = window.pollEvent())
            {
                // on close button release
                if (event->is<sf::Event::Closed>())
                {
                    // close window
                    window.close();
                }
    
                // on window resize
                else if (auto resized = event->getIf<sf::Event::Resized>())
                {
                    // update view
                    window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(resized->size))));
                }
            }

            // move shape
            float v  = 300.f;
            float dx = v*dt;
            float x1 = shape.getPosition().x;
            float x2 = x1 + dx;
            if (x2 >= window.getSize().x)
                x2 = -shape.getSize().x;
            shape.setPosition({x2, 0.f});
            // shape.move({300.f * dt, 0.f});

            // fill window with color
            window.clear(sf::Color(64, 64, 64));

            // draw
            window.draw(shape);

            // update display
            window.display();
        }
    }

    // program end successfully
    return 0;
}