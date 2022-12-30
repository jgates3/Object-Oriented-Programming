#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "movement.h"
#include "Global.h"
#include "SFML/Graphics/Text.hpp"
#include <string>
#include <windows.h>
#include <math.h>
using namespace sf;

		
	sf::Vector2f NormalizeClass:: normalization(sf::Vector2f inputvec) { //vector calculus stuff for movement (unit direction)
		float magnitude = sqrtf(inputvec.x * inputvec.x + 0.1f * (inputvec.y * inputvec.y));
		if (magnitude != 0) {
			inputvec.x /= magnitude;
			inputvec.y /= magnitude;

		}
		return inputvec;
	}

sf::Vector2f PMovement:: playermovement(sf::Vector2f velocity, float moveSpeed, float dt) {
	velocity.y = 0.f;
	velocity.x = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		velocity.y += -moveSpeed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocity.x += -moveSpeed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocity.y += moveSpeed * dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocity.x += moveSpeed * dt;
	}

	return velocity;
}


