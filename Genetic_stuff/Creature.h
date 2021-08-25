#pragma once
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



public:
	Creature();
	~Creature();

	void getProperties();
	void getFittness();
	void recreate();
};

