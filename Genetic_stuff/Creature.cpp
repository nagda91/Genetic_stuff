#include "Creature.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <string.h>

Creature::Creature()
{
	Timer timer;
	srand(time(NULL));

	int to = rand() % 100000000 + 10000000;

	for (int i = 0; i < to; i++)
	{
		srand(time(NULL) + rand() % 2000 + 10e3);
	}

	speed = rand() % 100 + 1;
	strength = rand() % 100 + 1;
	power = rand() % 100 + 1;
	canHide = rand() % 1 + 0;
	godKiller = 0;
	dead = 0;

	fittness = (speed + strength + power) / (3);
	if (speed >= 90) fittness = fittness + (100 - fittness) / 2;
	if (strength >= 90) fittness = fittness + (100 - fittness) / 2;
	if (power >= 90) fittness = fittness + (100 - fittness) / 2;
	if (fittness > 90) {
		std::cout << "Godkiller - Pogchamp:\n";
		getProperties();
	}
	
}

Creature::Creature(bool god)
{
	Timer timer;
	srand(time(NULL));

	if (god)
	{
		int to = rand() % 100000000 + 10000000;

		for (int i = 0; i < to; i++) {
			srand(time(NULL) + rand() % 2000 + 10e3);
		}

		speed = (rand() % 10 + 1) + 90;
		strength = (rand() % 10 + 1) + 90;
		power = (rand() % 10 + 1) + 90;
		canHide = rand() % 1 + 0;
		godKiller = 0;
		dead = 0;

		fittness = (speed + strength + power) / (3);
		std::cout << "GOD, Fittness: " << fittness << "\n";
	}
	else 
	{
		int to = rand() % 100000000 + 10000000;

		for (int i = 0; i < to; i++) {
			srand(time(NULL) + rand() % 2000 + 10e3);
		}

		speed = rand() % 100 + 1;
		strength = rand() % 100 + 1;
		power = rand() % 100 + 1;
		canHide = rand() % 1 + 0;
		godKiller = 0;
		dead = 0;

		fittness = (speed + strength + power) / (3);
		if (speed >= 90) fittness = fittness + (100 - fittness) / 2;
		if (strength >= 90) fittness = fittness + (100 - fittness) / 2;
		if (power >= 90) fittness = fittness + (100 - fittness) / 2;
		std::cout << "Fittness: " << fittness << "\n";
	}

	
}

Creature::~Creature() 
{

}

void Creature::getProperties()
{
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	std::cout << "Power: " << power << std::endl;
	std::cout << "Can hide?(0-No, 1-Yes): " << canHide << std::endl;
	std::cout << "Dead: " << dead << std::endl;
	std::cout << "God killer: " << godKiller << std::endl;
	std::cout << "Fittness: " << fittness<< std::endl;
}

std::string Creature::getPropertiesFile() {
	return (std::to_string(speed) + ";" + std::to_string(strength) + ";" + std::to_string(power) + ";" + std::to_string(canHide) + ";" + std::to_string(dead) + ";" + std::to_string(godKiller) + ";" + std::to_string(fittness));
}

void Creature::recreate() 
{
	srand(time(NULL));

	speed = rand() % 100 + 1;
	strength = rand() % 100 + 1;
	power = rand() % 100 + 1;
	canHide = rand() % 1 + 0;

	fittness = (speed + strength + power) / (3);
}

void Creature::killedAGod()
{
	godKiller = 1;
}

bool Creature::getGodKiller()
{
	return godKiller;
}

void Creature::died()
{
	dead = 1;
}

bool Creature::isAlive()
{
	return dead;
}

int Creature::getFittness() 
{
	return fittness;
}

Creature::Timer::Timer() 
{
	Timer::start = std::chrono::high_resolution_clock::now();
}

Creature::Timer::~Timer() 
{
	Timer::end = std::chrono::high_resolution_clock::now();
	Timer::duration = Timer::end - Timer::start;
	float ms = duration.count() * 1000.0f;
	std::cout << "Timer took " << ms << "ms\n";
}