//
// Created by super on 25.05.2023.
//

#ifndef TANKS_INPUTMANAGER_HPP
#define TANKS_INPUTMANAGER_HPP
#include <SFML/Graphics.hpp>
namespace Donpad {

    class InputManager {
    public:
        InputManager() {}
        ~InputManager() {}
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}

#endif //TANKS_INPUTMANAGER_HPP
