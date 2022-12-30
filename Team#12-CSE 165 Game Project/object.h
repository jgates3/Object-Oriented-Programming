#pragma once
 
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace std;
using namespace sf;
//simple polymorphism 
class object {
public:
	virtual sf:: Vector2f positionsender(){
		return sf::Vector2f(800.f, 580.f);
	}
};
class O1 : public object {
public:
	sf:: Vector2f positionsender() {

		return sf::Vector2f(50.f, 100.f);
	}
};

class O2 :public object {
public:
	sf::Vector2f positionsender() {
		return sf::Vector2f(430.f, 580.f);

	}
};


class O3 :public object {
public:
	sf::Vector2f positionsender() {
		return sf::Vector2f(300.f, 100.f);

	}
};

class O4: public object {
public:
	sf::Vector2f positionsender() {
		return sf::Vector2f(1020.f, 580.f);

	}
}; 



class O5 : public object {
public:
	sf::Vector2f positionsender() {
		return (sf::Vector2f(530.f, 110.f));

	}
};


class O6 : public object {
public:
	sf::Vector2f positionsender() {
		return sf::Vector2f(630.f, 580.f);

	}
};

class O7 : public object {
public:
	sf::Vector2f positionsender() {
		return sf::Vector2f(730.f, 110.f);

	}
};

class O8 : public object {
public:
	sf::Vector2f positionsender() {
		return sf::Vector2f(930.f, 110.f);

	}
};


class gameDisplay { 
public:
	string text;
	int value;
	void SetCounter(string x, int y);
	Vector2f checkpointSize();
	Vector2f playerPosition();
	Vector2f botSize();
 
	gameDisplay();
	~gameDisplay();
};

gameDisplay::gameDisplay() {

	std::cout << " " << std::endl;
}
gameDisplay::~gameDisplay() {
	std::cout << " " << std::endl;
}

void gameDisplay::SetCounter(string x, int y) {
	text = x;
	value = y;

}

Vector2f gameDisplay::checkpointSize(){
		return sf::Vector2f(15.f, 15.f);

	}

Vector2f gameDisplay::playerPosition() {
	return sf::Vector2f(210.f, 580.f);

}

Vector2f gameDisplay::botSize() {
	return sf::Vector2f(30.f, 30.f);
}
 


 