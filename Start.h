#pragma once
#include <iostream>
#include "Generate.h"
#include "Import.h"
#include <chrono>
#include <string>
#include <thread>
class Start
{
public:
	Start();
	Start(Map* world,int mode);
	~Start();

	void setMode(int mode);

	int getMode();
	int** getMap();
	int** getResult();
	string getOutput();
	string toString();
	bool equals(Start* object);

private:
	const int LIVE = 1;
	const int DEAD = 0;
	
	Map* world;
	int mode;
	string output;
	int** map;
	int** result;
	int generation;
	int height;
	int length;
	
	void init();
	string run();
	int** newValue();
	int checkNeighbor(int j, int k);
	bool checkDirection(int row, int column);
};

