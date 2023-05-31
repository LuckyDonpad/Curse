//
// Created by super on 31.05.2023.
//

#include "Collision.hpp"
#include "DEFINITIONS.hpp"

namespace Donpad {
    bool Collision::CheckSpriteCollision(sf::Sprite sprite_1, sf::Sprite sprite_2) {
        sf::Rect<float> rect_1 = sprite_1.getGlobalBounds();
        sf::Rect<float> rect_2 = sprite_2.getGlobalBounds();
        return rect_1.intersects(rect_2);
    }

    bool Collision::CheckLowerBorderCollision(sf::Sprite sprite) {
        return sprite.getPosition().y > SCREEN_HEIGHT - sprite.getGlobalBounds().height/2;
    }
}