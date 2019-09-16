#include "Import.h"

Import::Import() : Map()
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			map[i][j] = DEAD;
		}
	}
}
Import::Import(int height, int length, int** map) : Map(height, length)
{
	this->map = map;
}

void Import::setMap(int** map)
{
	this->map = map;
}
int** Import::getMap()
{
	return map;
}


bool Import::equals(Import* object)
{
	return ((Map::equals(object)) && (map == object->getMap()));
}