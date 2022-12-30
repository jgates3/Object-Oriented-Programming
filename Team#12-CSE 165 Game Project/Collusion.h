#pragma once
#ifndef COLLUSION_H
#define COLLUSION_H
#endif // !MOVEMENT_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
using namespace sf;

class PlayerCol {

public:
RectangleShape collusion_player(RectangleShape player);
};

class BotCol {
public:
	RectangleShape collusion_bot(RectangleShape bot);
};


class PlayerWC {
public:
	RectangleShape playerWallCol(sf::RectangleShape player, sf::FloatRect playerbounds, sf::FloatRect wallTopbounds, sf::FloatRect wallBottombounds, sf::FloatRect wallLeftbounds, sf::FloatRect wallRightbounds, sf::FloatRect nextPosition, sf::Vector2f velocity);
};