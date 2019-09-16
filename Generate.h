#pragma once
#include "Map.h"
#include <cstdlib>
#include <ctime>
class Generate : 
	public Map {
public:
	Generate();
	Generate(int height, int length, float population);

	void setHeight(int height);
	void setLength(int length);
	void setPopulation(double population);

	float getPopulation();

	int** create();
	int** roll();


	bool equals(Generate* object);

private:
	double population;

	void init();
};

