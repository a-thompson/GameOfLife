#pragma once
#include <fstream>
#include <string>
#include "Start.h"

class Interface
{
public:
	Interface();
	~Interface();

	string toString();
private:
	int mode;
	Map* world;
	Start* start;
	string file;

	const char DEAD_CHAR = '-';
	const char LIVE_CHAR = 'X';
	const int DEAD_INT = 0;
	const int LIVE_INT = 1;

	void init();
	bool openWorld();
	bool checkFile(ifstream& reader);
	void chooseMap(ifstream& reader);

	void exitSequence();

};

