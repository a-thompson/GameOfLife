#pragma once
#include "Map.h"
class Import :
	public Map {
public:
	Import();
	Import(int height, int length, int** map);

	void setMap(int** map);
	int** getMap();

	bool equals(Import* object);
};

