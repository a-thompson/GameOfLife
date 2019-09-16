#include "Generate.h"

Generate::Generate() : Map()
{
	this->population = 0.5;
	init();
}
Generate::Generate(int height, int length, float population) : Map(height, length)
{
	this->population = population;
	init();
}

void Generate::init()
{
	create();
	roll();
}

int** Generate::create()
{

	int total = height * length;
	int occupied = total - ((int) round(total * population));
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (count > occupied)
				map[i][j] = LIVE;
			else
				map[i][j] = DEAD;
			count++;
		}
	}
	return map;
}

int** Generate::roll()
{
	srand(time(NULL));
	int temp;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			
			int randHeight = rand() % height;
			int randLength = rand() % length;

			temp = map[i][j];
			map[i][j] = map[randLength][randHeight];
			map[randLength][randHeight] = temp;
		}
	}
	return map;
}

void Generate::setHeight(int height)
{
	Map::setHeight(height);
	init();
}
void Generate::setLength(int length)
{
	Map::setLength(length);
	init();
}
void Generate::setPopulation(double population)
{
	this->population = population;
	init();
}

float Generate::getPopulation()
{
	return population;
}




bool Generate::equals(Generate* object)
{
	return (Map::equals(object) && (population == object->getPopulation()));
}