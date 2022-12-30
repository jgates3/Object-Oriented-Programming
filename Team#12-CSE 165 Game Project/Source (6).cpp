#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics/Text.hpp"
#include <string>
#include <windows.h>
#include <math.h>
#include "movement.h"
#include "Collusion.h"
#include "Global.h"
#include "object.h"
//#include "Wall.h"
 

int main() {
	bool paused = false;
	bool change = true;
	bool change2 = false;
	bool change3 = false;
	bool change4 = false;
	bool change5 = false;
	bool change6 = false;
	bool change7 = false;
	bool change8 = false;
	bool finished = false;
	bool finished2 = false;
	bool finished3 = false;
	int counter = 0;
	const float gridSize = 100.f;
	NormalizeClass obj1;
	PMovement pmoveobj;
	PlayerCol pcolobj;
	BotCol bcolobj;
	PlayerWC obj5;
	gameDisplay checksize;
	gameDisplay playerPos;
	gameDisplay countobj;
	gameDisplay botsize;
	O1 botobjchild;
	O2 object2;
	O3 object3;
	O4 object4;
	O5 object5;
	O6 object6;
	O7 object7;
	O8 object8;


	sf::RenderWindow window(sf::VideoMode(windowWidth, windowLength), "Testing");
	window.setFramerateLimit(120);
	//window.setMouseCursorVisible(false);
	sf::Music music;
	if (!music.openFromFile("amonga.wav")) { //if music doesnt work feel free to comment out
		std::cout << "error" << std::endl;
	}
	music.setLoop(true);
	music.play();

	sf::Texture texture;
	if (!texture.loadFromFile("tree.jpg")) {
	}
	sf::Sprite background(texture);
	float dt; //Delta time
	sf::Clock dt_clock;

	//Player Block
	const float moveSpeed = 100.f;
	sf::Vector2f velocity;
	sf::RectangleShape player;
	player.setPosition(playerPos.playerPosition());
	player.setFillColor(sf::Color::Yellow);
	player.setSize(sf::Vector2f(20, 20)); //Vector2f(X, Y)

	//Other object
	sf::RectangleShape goal;
	goal.setFillColor(sf::Color::Blue);
	goal.setSize(sf::Vector2f(30, 30)); //Vector2f(X, Y)
	goal.setPosition(sf::Vector2f(1070.f, 110.f));

	//bots
	float moveSpeed_bot = 10.f;
	sf::RectangleShape bot(sf::Vector2f(50.f, 100.f));
	bot.setFillColor(sf::Color::Green);
	bot.setSize(botsize.botSize()); //Vector2f(X, Y)
	object* botobj;
	botobj = &botobjchild;
	sf::Vector2f x = botobj->object::positionsender();
	bot.setPosition(x);

	sf::RectangleShape bot2;
	bot2.setFillColor(sf::Color::Green);
	bot2.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot2.setPosition(object2.positionsender());

	sf::RectangleShape bot3;
	bot3.setFillColor(sf::Color::Green);
	bot3.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot3.setPosition(object3.positionsender());

	sf::RectangleShape bot4;
	bot4.setFillColor(sf::Color::Green);
	bot4.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot4.setPosition(object4.positionsender());

	sf::RectangleShape bot5;
	bot5.setFillColor(sf::Color::Green);
	bot5.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot5.setPosition(object5.positionsender());

	sf::RectangleShape bot6;
	bot6.setFillColor(sf::Color::Green);
	bot6.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot6.setPosition(object6.positionsender());

	sf::RectangleShape bot7;
	bot7.setFillColor(sf::Color::Green);
	bot7.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot7.setPosition(object7.positionsender());

	sf::RectangleShape bot8;
	bot8.setFillColor(sf::Color::Green);
	bot8.setSize(botsize.botSize()); //Vector2f(X, Y)
	bot8.setPosition(object8.positionsender());
	//Walls
	std::vector<sf::RectangleShape> walls;

	sf::RectangleShape checkpoint1;
	checkpoint1.setFillColor(sf::Color::Cyan);
	checkpoint1.setSize(checksize.checkpointSize()); //Vector2f(X, Y)
	checkpoint1.setPosition(sf::Vector2f(850.f, 300.f));


	sf::RectangleShape checkpoint2;
	checkpoint2.setFillColor(sf::Color::Cyan);
	checkpoint2.setSize(checksize.checkpointSize()); //Vector2f(X, Y)
	checkpoint2.setPosition(sf::Vector2f(1080.f, 580.f));

	sf::RectangleShape checkpoint3;
	checkpoint3.setFillColor(sf::Color::Cyan);
	checkpoint3.setSize(checksize.checkpointSize()); //Vector2f(X, Y)
	checkpoint3.setPosition(sf::Vector2f(210.f, 110.f));



	sf::RectangleShape wallTop;
	sf::RectangleShape wallRight;
	sf::RectangleShape wallBottom;
	sf::RectangleShape wallLeft;
	//setposition(x, y)
	wallTop.setFillColor(sf::Color::Red);
	wallRight.setFillColor(sf::Color::Red);
	wallBottom.setFillColor(sf::Color::Red);
	wallLeft.setFillColor(sf::Color::Red);
	wallTop.setSize(sf::Vector2f(900.f, 10.f));
	wallTop.setPosition(gridSize * 2, gridSize);
	wallRight.setSize(sf::Vector2f(10.f, 500.f));
	wallRight.setPosition(gridSize * 2, gridSize);
	wallBottom.setSize(sf::Vector2f(900.f, 10.f));
	wallBottom.setPosition(gridSize * 2, gridSize * 6);
	wallLeft.setSize(sf::Vector2f(10.f, 510.f));
	wallLeft.setPosition(gridSize * 11, gridSize);


	while (window.isOpen()) {
		dt = dt_clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//Movement in move.h/cpp, also other keyboard funcs
		sf::Vector2f* pvelocity = &velocity;
		velocity = pmoveobj.playermovement(*pvelocity, moveSpeed, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {	//closing
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {	//Pausing
			sf::Font MyFont;
			if (!MyFont.loadFromFile("Roboto-Bold.ttf")) { //comment out if you dont have the font in your folder
				std::cout << "error" << std::endl;
			}
			sf::Text textP;
			textP.setFont(MyFont);
			textP.setPosition(sf::Vector2f(300.f, 380.f));
			const std::string win = "PAUSED! Resuming in 10 secs...";
			textP.setString(win);
			window.draw(textP);
			window.display();

			paused = true;
			if (paused) {
				Sleep(10000);
				paused = false;

			}

		}
		player.move(velocity);

		//Player-Window Collision in Collusion.h/cpp
		sf::RectangleShape* p = &player;
		player = pcolobj.collusion_player(*p);

		//Bot-window collision in Collusion.h/cpp
		sf::RectangleShape* pb = &bot;
		bot = bcolobj.collusion_bot(*pb);
		
		//Wall-Player Collusion
		sf::FloatRect playerbounds = player.getGlobalBounds();
		sf::FloatRect wallTopbounds = wallTop.getGlobalBounds();
		sf::FloatRect wallBottombounds = wallBottom.getGlobalBounds();
		sf::FloatRect wallLeftbounds = wallLeft.getGlobalBounds();
		sf::FloatRect wallRightbounds = wallRight.getGlobalBounds();
		sf::FloatRect nextPosition;

		nextPosition = playerbounds;
		nextPosition.top += velocity.y;
		nextPosition.left += velocity.x;

		sf::RectangleShape* pplayer = &player;  //usage of pointers 
		sf::FloatRect* pplayerbounds = &playerbounds;
		sf::FloatRect* pwallTopbounds = &wallTopbounds;
		sf::FloatRect* pwallBottombounds = &wallBottombounds;
		sf::FloatRect* pwallLeftbounds = &wallLeftbounds;
		sf::FloatRect* pwallRightbounds = &wallRightbounds;
		sf::FloatRect* pnextPosition = &nextPosition;
		player = obj5.playerWallCol(*pplayer, *pplayerbounds, *pwallTopbounds, *pwallBottombounds, *pwallLeftbounds, *pwallRightbounds, *pnextPosition,*pvelocity);

		

		//Player to bot collusion
		sf::FloatRect objectbounds = bot.getGlobalBounds();
		sf::FloatRect objectbounds2 = bot2.getGlobalBounds();
		sf::FloatRect objectbounds3 = bot3.getGlobalBounds();
		sf::FloatRect objectbounds4 = bot4.getGlobalBounds();
		sf::FloatRect objectbounds5 = bot5.getGlobalBounds();
		sf::FloatRect objectbounds6 = bot6.getGlobalBounds();
		sf::FloatRect objectbounds7 = bot7.getGlobalBounds();
		sf::FloatRect objectbounds8 = bot8.getGlobalBounds();
		sf::Vector2f direction;
		sf::Vector2f direction2;

			if (bot.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { 
				change = true;
			}
			if (bot.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { 
				change = false;
			}
			if (change == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 =obj1. normalization(direction);
				bot.move(direction2);
			}
			if (change == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot.move(direction2);
			}
			if (bot2.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) {
				change2 = true;
			}
			if (bot2.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { 
				change2 = false;
			}
			if (change2 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot2.move(direction2);
			}
			if (change2 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 =obj1. normalization(direction);
				bot2.move(direction2);
			}
			if (bot3.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { 
				change3 = true;
			}
			if (bot3.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { 
				change3 = false;
			}
			if (change3 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot3.move(direction2);
			}
			if (change3 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 =obj1.normalization(direction);
				bot3.move(direction2);
			}
			if (bot4.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { 
				change4 = true;
			}
			if (bot4.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { 
				change4 = false;
			}
			if (change4 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot4.move(direction2);
			}
			if (change4 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot4.move(direction2);
			}
			if (bot5.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { 
				change5 = true;
			}
			if (bot5.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { 
				change5 = false;
			}
			if (change5 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot5.move(direction2);
			}
			if (change5 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot5.move(direction2);
			}
			if (bot6.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { //touch bottom and head to top
				change6 = true;
			}
			if (bot6.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { // top to bottom
				change6 = false;
			}
			if (change6 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot6.move(direction2);
			}
			if (change6 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot6.move(direction2);
			}
			if (bot7.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { //touch bottom and head to top
				change7 = true;
			}
			if (bot7.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { // top to bottom
				change7 = false;
			}
			if (change7 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot7.move(direction2);
			}
			if (change7 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot7.move(direction2);
			}
			if (bot8.getGlobalBounds().intersects(wallBottom.getGlobalBounds())) { //touch bottom and head to top
				change8 = true;
			}
			if (bot8.getGlobalBounds().intersects(wallTop.getGlobalBounds())) { // top to bottom
				change8 = false;
			}
			if (change8 == true) {
				direction = -(wallBottom.getPosition() - wallRight.getPosition());
				direction2 =obj1. normalization(direction);
				bot8.move(direction2);
			}
			if (change8 == false) {
				direction = (wallBottom.getPosition() - wallRight.getPosition());
				direction2 = obj1.normalization(direction);
				bot8.move(direction2);
			}
			if (playerbounds.intersects(objectbounds)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds2)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds3)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds4)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds5)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds6)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds7)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}
			if (playerbounds.intersects(objectbounds8)) {
				player.setPosition(playerPos.playerPosition());
				counter = counter + 1;
			}

		//Death Counter
		sf::Font MyFont;
		if (!MyFont.loadFromFile("Roboto-Bold.ttf")) { //comment out if you dont have the font in your folder
			std::cout << "error" << std::endl;
		}
		 
		sf::Text text;
		text.setFont(MyFont);
		std::string death = "death counter: ";
		countobj.SetCounter(death, counter);
		text.setString(countobj.text + std::to_string(countobj.value));
		sf::FloatRect goalbounds = goal.getGlobalBounds();
		sf::Text text2;
		text2.setFont(MyFont);

		if (playerbounds.intersects(goalbounds)) { //end goal (player touches end point)
			if (finished == true && finished2 == true && finished3 == true) {
				text2.setPosition(sf::Vector2f(640.f, 360.f));
				music.stop();
				window.clear();
				const std::string win = "GAME OVER! You win." ;
				sf::Music music2;
				if (!music2.openFromFile("fanfare.wav")) {
					std::cout << "error" << std::endl;
				}
				music2.setLoop(true);
				music2.play();
				sf::Texture texture2;
				if (!texture2.loadFromFile("bg2.jpg")) {
				}
				sf::Sprite background(texture2);

				text2.setString(win);
				finished = false;
				finished2 = false;
				finished3 = false;
				
				
				window.draw(background);
				window.draw(text2);
	

				window.display();
				Sleep(10000);
				window.close();
			}
		}

		sf::Text text3;
		text3.setFont(MyFont);


		if (finished == true && finished2 == true && finished3 == true) {
			const std::string goalaval = "Goal Avaliable! ";
			text3.setPosition(sf::Vector2f(20.f, 30.f));
			text3.setString(goalaval);
		}


		if (player.getGlobalBounds().intersects(checkpoint1.getGlobalBounds())) {
			finished = true;
		}

		if (!player.getGlobalBounds().intersects(checkpoint2.getGlobalBounds())) {
			finished2 = true;
		}

		if (player.getGlobalBounds().intersects(checkpoint2.getGlobalBounds())) {
			finished3 = true;
		}
		
		//Rendering
		window.clear();
		window.draw(background);
		window.draw(wallTop);
		window.draw(wallRight);
		window.draw(wallLeft);
		window.draw(wallBottom);
		window.draw(player);
		window.draw(goal);
		window.draw(text);
		window.draw(bot);
		window.draw(bot2);
		window.draw(bot3);
		window.draw(bot4);
		window.draw(bot5);
		window.draw(bot6);
		window.draw(bot7);
		window.draw(bot8);
		window.draw(text2);
		window.draw(checkpoint1);
		window.draw(checkpoint2);
		window.draw(checkpoint3);
		window.draw(text3);
		window.display();
	}
}