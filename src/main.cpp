#include <iostream>
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "assignment 2");
    
    while(window.isOpen())
    {
        // reading the events
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
