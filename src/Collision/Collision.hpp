//
// Created by super on 31.05.2023.
//

#ifndef TANKS_COLLISION_HPP
#define TANKS_COLLISION_HPP

#include <SFML/Graphics.hpp>

namespace Donpad {

    class Collision {
    public:
        bool CheckSpriteCollision(sf::Sprite sprite_1, sf::Sprite sprite_2);

        bool CheckLowerBorderCollision(sf::Sprite sprite);
    };
}

#endif //TANKS_COLLISION_HPP
