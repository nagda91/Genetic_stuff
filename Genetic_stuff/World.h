#pragma once
#include <\dev\Genetic_stuff\Genetic_stuff\Creature.h>
#include <vector>

class World
{
private:
	std::vector<Creature> population;
	Creature GOD;
	bool firstLine;

	struct Timer
	{

		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;

		Timer();
		~Timer();
	};

public:
	World(int);
	~World();

	void reproduction();
	void fight();
	void log(std::string);

};

