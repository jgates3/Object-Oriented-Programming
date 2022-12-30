#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "Collusion.h"
#include "Global.h"
using namespace sf;

sf::RectangleShape PlayerCol:: collusion_player(sf::RectangleShape player) {	//player to window
	//Left collision
	if (player.getPosition().x < 0.f) {
		player.setPosition(0.f, player.getPosition().y);
	}
	//Top collision
	if (player.getPosition().y < 0.f) {
		player.setPosition(player.getPosition().x, 0.f);
	}
	//Right Collision
	if (player.getPosition().x + player.getGlobalBounds().width > windowWidth) {
		player.setPosition(windowWidth - player.getGlobalBounds().width, player.getPosition().y);
	}
	//Bottom Collision
	if (player.getPosition().y + player.getGlobalBounds().height > windowLength) {
		player.setPosition(player.getPosition().x, windowLength - player.getGlobalBounds().height);
	}

	return player;
}

sf::RectangleShape BotCol:: collusion_bot(sf::RectangleShape bot) {
	//Left collision
	//Left collision
	if (bot.getPosition().x < 0.f) {
		bot.setPosition(0.f, bot.getPosition().y);
	}
	//Top collision
	if (bot.getPosition().y < 0.f) {
		bot.setPosition(bot.getPosition().x, 0.f);
	}
	//Right Collision
	if (bot.getPosition().x + bot.getGlobalBounds().width > windowWidth) {
		bot.setPosition(windowWidth - bot.getGlobalBounds().width, bot.getPosition().y);
	}
	//Bottom Collision
	if (bot.getPosition().y + bot.getGlobalBounds().height > windowLength) {
		bot.setPosition(bot.getPosition().x, windowLength - bot.getGlobalBounds().height);
	}

	return bot;
}

sf:: RectangleShape PlayerWC::playerWallCol(sf::RectangleShape player, sf::FloatRect playerbounds, sf::FloatRect wallTopbounds, sf::FloatRect wallBottombounds, sf::FloatRect wallLeftbounds, sf::FloatRect wallRightbounds, sf::FloatRect nextPosition, sf::Vector2f velocity) {
	//Top
	if (wallTopbounds.intersects(nextPosition)) {
		if (playerbounds.top > wallTopbounds.top
			&& playerbounds.top + playerbounds.height > wallTopbounds.top + wallTopbounds.height
			&& playerbounds.left < wallTopbounds.left + wallTopbounds.width
			&& playerbounds.left + playerbounds.width > wallTopbounds.left) {
			velocity.y = 0.f;
			player.setPosition(playerbounds.left, wallTopbounds.top + wallTopbounds.height);
		}
	}
	//Bottom
	if (wallBottombounds.intersects(nextPosition)) {
		if (playerbounds.top < wallBottombounds.top
			&& playerbounds.top + playerbounds.height < wallBottombounds.top + wallBottombounds.height
			&& playerbounds.left < wallBottombounds.left + wallBottombounds.width
			&& playerbounds.left + playerbounds.width > wallBottombounds.left) {
			velocity.y = 0.f;
			player.setPosition(playerbounds.left, wallBottombounds.top - playerbounds.height);
		}

	}
	//Left
	if (wallRightbounds.intersects(nextPosition)) {
		if (playerbounds.left > wallRightbounds.left
			&& playerbounds.left + playerbounds.width > wallRightbounds.left + wallRightbounds.width
			&& playerbounds.top < wallRightbounds.top + wallRightbounds.height
			&& playerbounds.top + playerbounds.height > wallRightbounds.top) {
			velocity.x = 0.f;
			player.setPosition(wallRightbounds.left + wallRightbounds.width, playerbounds.top);
		}
	}
	//Right
	if (wallLeftbounds.intersects(nextPosition)) {
		if (playerbounds.left < wallLeftbounds.left
			&& playerbounds.left + playerbounds.width < wallLeftbounds.left + wallLeftbounds.width
			&& playerbounds.top < wallLeftbounds.top + wallLeftbounds.height
			&& playerbounds.top + playerbounds.height > wallLeftbounds.top) {
			velocity.x = 0.f;
			player.setPosition(wallLeftbounds.left - playerbounds.width, playerbounds.top);
		}
	}
	return player;

}
