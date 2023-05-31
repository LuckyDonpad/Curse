//
// Created by super on 25.05.2023.
//

#include "InputManager.hpp"

namespace Donpad {
    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::IntRect tempRect(object.getGlobalBounds().left,
                                 object.getGlobalBounds().top,
                                 object.getGlobalBounds().width,
                                 object.getGlobalBounds().height);
            if (tempRect.contains((sf::Mouse::getPosition(window)))){
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window) {
        return sf::Mouse::getPosition(window);
    }
}