#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <future>
#include <vector>
#include </dev/Genetic_stuff/Genetic_stuff/Creature.h>
#include </dev/Genetic_stuff/Genetic_stuff/World.h>

/*
Population class - GOD will be in it with exact no. of creatures, creatures reproduction

In the future: add HP to the creatures and they can fight against each other or the main boss, need of WORLD class to involve gods and
different populations

*/

std::vector<std::future<void>> threads;
static std::mutex s_CreatureMutex;
//Not doing sh@t, push_back to the vector does not work
static void loadCreatures(std::vector<Creature>* vecCreatures)
{
	Creature one;

	std::lock_guard<std::mutex> lock(s_CreatureMutex);
	vecCreatures->push_back(one);
}

int main()
{
	World first = World(150);
}