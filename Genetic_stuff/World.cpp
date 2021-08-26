#include "World.h"
#include <iostream>
#include <fstream>
#include <chrono>

World::World(int populationNumber)
{
	Timer timer;

	GOD = Creature(1);
	firstLine = 0;

#define TEST 0
#if TEST
	do {
		Creature one;
		population.push_back(one);
	} while (population.back().getFittness() > 90);

#else
	for (int i = 0; i < populationNumber; i++) {
		Creature one;
		population.push_back(one);
		log(population.back().getPropertiesFile());
	}
#endif

	fight();

}

World::~World() 
{

}

void World::reproduction()
{
	//making better creatures...
}

void World::fight()
{
	srand(time(NULL));
	std::string result;

	for (int i = 0; i < population.size(); i++) {
		if (population[i].getFittness() > GOD.getFittness()) {
			population[i].killedAGod();
			result = std::to_string(i + 1) + ". creature killed the God Pog\n" + std::to_string(population[i].getFittness());
			std::cout << result << "\n";
			log(result);
		}
		else {
			population[i].died();
			result = std::to_string(i + 1) + ". creature died";
			std::cout << result << "\n";
			log(result);
		}
	}
}

void World::log(std::string text)
{
	std::ofstream outFile;
	outFile.open("log.txt", std::ios::app);
	if (!firstLine) {
		std::string firstline = "Speed;Strength;Power;Canhide;Sex;Dead;Godkiller;Fittness\n";
		outFile.write(firstline.c_str(), firstline.length());
		firstLine = 1;
	}	

	outFile.write(text.c_str(), text.length());
	outFile.write("\n", 1);

	outFile.close();

}

World::Timer::Timer()
{
	Timer::start = std::chrono::high_resolution_clock::now();
}

World::Timer::~Timer()
{
	Timer::end = std::chrono::high_resolution_clock::now();
	Timer::duration = Timer::end - Timer::start;
	float ms = duration.count() * 1000.0f;
	std::cout << "Timer took " << ms << "ms\n";
}