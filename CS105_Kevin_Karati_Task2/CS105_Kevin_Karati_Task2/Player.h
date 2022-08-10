#pragma once


//enums declared for class and race selections
enum Class { WARRIOR = 1, PRIEST, MAGE };
enum Race { HUMAN = 1, ELF, DWARF, ORC, TROLL };

class Player {
public:
	std::string name;
	Race race;
	int hitPoints;
	int magicPoints;

	Player();
	Player(std::string name, Race race, int hitPoints, int magicPoints);
	std::string getName();
	Race getRace();
	std::string whatRace();
	int getHitPoints();
	int getMagicPoints();
	void setName(std::string name);
	void setRace(Race race);
	void setHitpoints(int hitpoints);
	void setMagicPoints(int magicpoints);
	std::string attack();
};

//Derived classes
class Warrior : public Player {
public:
	std::string attack();
};

class Priest : public Player {
public:
	std::string attack();
};

class Mage : public Player {
public:
	std::string attack();
};