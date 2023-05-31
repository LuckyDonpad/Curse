//
// Created by super on 25.05.2023.
//

#ifndef TANKS_ASSETMANAGER_HPP
#define TANKS_ASSETMANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>

namespace Donpad {

    class AssetManager {
    public:
        AssetManager(){}
        ~AssetManager(){}
        void LoadTexture(std::string name, std::string filename);
        sf::Texture &GetTexture(std::string name);

        void LoadFont(std::string name, std::string filename);
        sf::Font &GetFont(std::string name);

    private:
        std::map<std::string , sf::Texture> _textures;
        std::map<std::string , sf::Font> _fonts;
    };
}

#endif //TANKS_ASSETMANAGER_HPP
