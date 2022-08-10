#include <iostream>
#include <string>
#include "player.h"


Player::Player() { //default constructor
	name = "";
	race = HUMAN;
	hitPoints = 0;
	magicPoints = 0;
}

Player::Player(std::string name, Race race, int hitPoints, int magicPoints) {

}

std::string Player::getName() {
	return name;
}

Race Player::getRace() { //returns player race as enum
	return race;
}

std::string Player::whatRace() { //returns player race as string
	Race temp;
	temp = getRace();

	switch (temp) {
	case HUMAN:
		return "Human";
		break;
	case ELF:
		return "Elf";
		break;
	case DWARF:
		return "Dwarf";
		break;
	case ORC:
		return "Orc";
		break;
	case TROLL:
		return "Troll";
		break;
	}
}

int Player::getHitPoints() {
	return hitPoints;
}

int Player::getMagicPoints() {
	return magicPoints;
}

void Player::setName(std::string userInput) {
	name = userInput;
}

void Player::setRace(Race userInput) {
	race = userInput;
}

void Player::setHitpoints(int userInput) {
	hitPoints = userInput;
}

void Player::setMagicPoints(int userInput) {
	magicPoints = userInput;
}

std::string Player::attack() { //default attack
	return "No attack method defined yet!\n"; 
}



std::string Warrior::attack() { //Derived attack
	return "I will destroy you with my sword!\n";
}
std::string Priest::attack() {
	return "I will assault you with my holy wrath!\n";
}
std::string Mage::attack() {
	return "I will crush you with my arcane missiles!\n";
}