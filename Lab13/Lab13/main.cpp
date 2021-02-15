#include <SFML/Graphics.hpp>
#include <Windows.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    sf::CircleShape triangle(30, 5);
    triangle.setPosition(500, 150);
    triangle.setFillColor(sf::Color::Magenta);
    triangle.setOutlineThickness(5);
    triangle.setOutlineColor(sf::Color::White);

    sf::CircleShape circle;
    circle.setRadius(75);
    circle.setPosition(620, 100);
    circle.setFillColor(sf::Color::Yellow);
    circle.setOutlineThickness(5);
    circle.setOutlineColor(sf::Color::White);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {}
    sf::Text text;
    text.setFont(font);
    text.setString("Today is a sunny day");
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(triangle);
        window.draw(circle);
        window.draw(text);
        window.display();
        window.clear();
    }

    return 0;
}
