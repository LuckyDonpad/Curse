//
// Created by super on 01.06.2023.
//

#include "HUD.hpp"

namespace Donpad {
    HUD::HUD(Donpad::GameDataRef data) : _data(data) {
        _scoreText.setFont(_data->assets.GetFont("Score"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(64);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(_data->window.getSize().x / 2, _data->window.getSize().y / 8);
    }

    void HUD::Draw() {
        _data->window.draw(_scoreText);
    }

    void HUD::UpdateScore(int i) {
        _scoreText.setString(std::to_string(i));
    }
}