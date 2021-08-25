#include "Creature.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

Creature::Creature() {

	srand(time(NULL));

	int to = rand() % 100000000 + 10000000;

	for (int i = 0; i < to; i++) {
		srand(time(NULL) + rand() % 10000 + 10e3);
	}

	speed = rand() % 100 + 1;
	strength = rand() % 100 + 1;
	power = rand() % 100 + 1;
	canHide = rand() % 1 + 0;
	sex = rand() % 1 + 0;

	fittness = (speed + strength + power) / (3);

}

Creature::~Creature() {

}

void Creature::getProperties() {

	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	std::cout << "Power: " << power << std::endl;
	std::cout << "Can hide?(0-No, 1-Yes): " << canHide << std::endl;
	std::cout << "Sex(0-Female, 1-Male): " << sex << std::endl;
	std::cout << "Fittness: " << fittness<< std::endl;

}

void Creature::recreate() {

	srand(time(NULL));

	speed = rand() % 100 + 1;
	strength = rand() % 100 + 1;
	power = rand() % 100 + 1;
	canHide = rand() % 1 + 0;
	sex = rand() % 100 + 1;

	fittness = (speed + strength + power) / (3);

}

void Creature::getFittness() {

	std::cout << "Fittness: " << fittness << std::endl;
}