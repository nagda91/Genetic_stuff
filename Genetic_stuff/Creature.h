#pragma once

#include <chrono>
#include <string>

class Creature
{
private:

	//Properties
	double fittness;
	int speed;
	int strength;
	int power;
	bool canHide;
	bool godKiller;
	bool dead;

	struct Timer 
	{

		std::chrono::time_point<std::chrono::steady_clock> start, end;
		std::chrono::duration<float> duration;

		Timer();
		~Timer();
	};


public:
	Creature();
	Creature(bool);
	~Creature();

	void getProperties();
	std::string getPropertiesFile();
	int getFittness();
	void recreate();
	void killedAGod();
	bool getGodKiller();
	void died();
	bool isAlive();
};

