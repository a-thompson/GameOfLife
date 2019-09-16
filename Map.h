#pragma once
#include <iostream>
using namespace std;

class Map {
public:
	Map();
	Map(int height, int length);

	void setHeight(int height);
	void setLength(int length);
	void setMap(int** map);

	int getHeight();
	int getLength();
	int** getMap();

	string toString();
	bool equals(Map* object);

protected:
	int height;
	int length;
	int** map;

	const int LIVE = 1;
	const int DEAD = 0;

	void init();

};
