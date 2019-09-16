#include "Map.h"

Map::Map() 
{
	this->height = 5;
	this->length = 5;

	init();
}
Map::Map(int height, int length)
{
	this->height = height;
	this->length = length;
	init();
}

void Map::init()
{
	map = new int* [length];
	for (int k = 0; k < length; k++)
	{
		map[k] = new int[height];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			map[i][j] = 0;
		}
	}
}

void Map::setHeight(int height)
{
	this->height = height;
}
void Map::setLength(int length)
{
	this->length = length;
}
void Map::setMap(int** map)
{
	this->map = map;
}

int Map::getHeight()
{
	return height;
}
int Map::getLength()
{
	return length;
}
int** Map::getMap()
{
	return map;
}

string Map::toString()
{
	string out = "";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if ((map[i][j] == NULL)||(map[i][j] == DEAD))
				out += '-';
			else
				out += 'X';
		}
		out += "\n";
	}
	return out;
}
bool Map::equals(Map* object)
{
	return ((height == object->getHeight()) && length == object->getLength()) && (map == object->getMap());
}