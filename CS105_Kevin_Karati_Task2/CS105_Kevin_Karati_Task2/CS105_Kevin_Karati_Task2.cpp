// CS105_Kevin_Karati_Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "player.h"


void charPrint(); //prints created characters

std::vector<Warrior> warrior;
std::vector<Priest> priest;
std::vector<Mage> mage;


Race raceSel() { //uses enum values from player.h
	int raceSelect;

	std::cout << "Please select a race\n";
	std::cout << "	1. Human\n";
	std::cout << "	2. Elf\n";
	std::cout << "	3. Dwarf\n";
	std::cout << "	4. Orc\n";
	std::cout << "	5. Troll\n";
	std::cin >> raceSelect;

	switch (raceSelect) {
	case HUMAN:
		return HUMAN;
		break;
	case ELF:
		return ELF;
		break;
	case DWARF:
		return DWARF;
		break;
	case ORC:
		return ORC;
		break;
	case TROLL:
		return TROLL;
		break;
	default:
		std::cout << "Selection not available, please try again.\n";
		raceSel();
		break;
	}
}

std::string nameSel() {
	std::string name;
	std::cout << "Enter a name for your character.\n";
	std::cin >> name;
	return name;
}

bool charCreate() { //loops function until finish char creation is selected
	Warrior tempWarrior; 
	Priest tempPriest;
	Mage tempMage;
	int classSelect;

	std::cout << "	CHARACTER CREATION\n";
	std::cout << "Please select a class\n";
	std::cout << "	1. Warrior\n";
	std::cout << "	2. Priest\n";
	std::cout << "	3. Mage\n";
	std::cout << "	4. Finish character creation.\n";
	std::cin >> classSelect;

	switch (classSelect) {
	case WARRIOR:
		tempWarrior.setHitpoints(200); 
		tempWarrior.setMagicPoints(0);
		tempWarrior.setRace(raceSel());
		tempWarrior.setName(nameSel());
		warrior.push_back(tempWarrior); //appends to vector
		return true;
		break;
	case PRIEST:
		tempPriest.setHitpoints(100);
		tempPriest.setMagicPoints(200);
		tempPriest.setRace(raceSel());
		tempPriest.setName(nameSel());
		priest.push_back(tempPriest);
		return true;
		break;
	case MAGE:
		tempMage.setHitpoints(200);
		tempMage.setMagicPoints(0);
		tempMage.setRace(raceSel());
		tempMage.setName(nameSel());
		mage.push_back(tempMage);
		return true;
		break;
	case 4:
		charPrint();
		return false;
		break;
	default:
		std::cout << "Selection not available, please try again.\n";
		charCreate();
		break;
	}
}



void charPrint() { //iterates through vectors and prints each player's stats
	std::cout << "-----------------\n";
	std::cout << "WARRIOR LIST:\n";
	std::cout << "-----------------\n";
	for (int i = 0; i < warrior.size(); i++) {
		std::cout << "My name is " << warrior[i].getName() << ", my race is " << warrior[i].whatRace() << ", I am a warrior and " << warrior[i].attack();
	}
	std::cout << "-----------------\n";
	std::cout << "PRIEST LIST:\n";
	std::cout << "-----------------\n";
	for (int i = 0; i < priest.size(); i++) {
		std::cout << "My name is " << priest[i].getName() << ", my race is " << priest[i].whatRace() << ", I am a priest and " << priest[i].attack();
	}
	std::cout << "-----------------\n";
	std::cout << "MAGE LIST:\n";
	std::cout << "-----------------\n";
	for (int i = 0; i < mage.size(); i++) {
		std::cout << "My name is " << mage[i].getName() << ", my race is " << mage[i].whatRace() << ", I am a mage and " << mage[i].attack();
	}
}

int main() {
	int sel;
	bool loop = true;

	while (loop) {
		loop = charCreate();
	}

	std::cout << "\nCharacter creation done!.......\n" <<
		"You can now move to the next level!\n";

	system("pause");
	return 0;
}

