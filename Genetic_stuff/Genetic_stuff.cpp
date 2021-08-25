#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>


#include </dev/Genetic_stuff/Genetic_stuff/Creature.h>

/*
GOD = Main boss 90-100 get every preporties

Population class - GOD will be in it with exact no. of creatures, creatures reproduction

In the future: add HP to the creatures and they can fight against each other or the main boss, need of WORLD class to involve gods and
different populations

*/



int main()
{

	std::vector<Creature> vector;

	for (int i = 0; i < 10; i++) {

		vector.push_back(Creature());

	}

	for (int i = 0; i < 10; i++) {

		std::cout << i + 1 << ". ";
		vector[i].getFittness();
		//vector[i].getProperties();

	}
}