#ifndef MOVEMENT_H
#define MOVEMENT_H
#endif // !MOVEMENT_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
using namespace sf;
class NormalizeClass {
public:
	Vector2f normalization(Vector2f vec);
};

class PMovement {
public:
	Vector2f playermovement(Vector2f velocity, float moveSpeed, float dt);
};