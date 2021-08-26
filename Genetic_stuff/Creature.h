#pragma once

#include <chrono>

class Creature
{
private:

	//Properties
	double fittness;
	int speed;
	int strength;
	int power;
	bool canHide;
	bool sex;

	struct Timer 
	{
		//std::chrono::time_point<std::chrono::steady_clock> start;
		//std::chrono::time_point<std::chrono::steady_clock> end;
		//std::chrono::time_point<std::chrono::steady_clock> start, end;
		//std::chrono::high_resolution_clock::time_point start, end;

		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;

		Timer();
		~Timer();
	};


public:
	Creature();
	~Creature();

	void getProperties();
	void getFittness();
	void recreate();
};

