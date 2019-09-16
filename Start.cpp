#include "Start.h"

Start::Start()
{
	this->world = new Generate();
	mode = 1;
	init();
}
Start::Start(Map* world, int mode)
{
	
	this->world = world;
	this->mode = mode;
	init();
}
Start::~Start()
{
	delete[] map;
}

void Start::init()
{
	output = run();
}

//begin
string Start::run()
{
	generation = 0;
	string out = "Generation " + to_string(generation) + "\n";
	height = world->getHeight();
	length = world->getLength();
	map = new int* [length];
	for (int k = 0; k < length; k++)
	{
		map[k] = new int[height];
	}
	result = new int* [length];
	for (int k = 0; k < length; k++)
	{
		result[k] = new int[height];
	}
	map = world->getMap();
	result = world->getMap();

	bool loop = true;
	string prev, current;

	out += toString() + "\n";
	while (loop)
	{
		prev = toString();
		result = newValue();
		current = toString();
		generation++;

		if (prev == current)
		{
			out += "Stable\n";
			cin.ignore();
			loop = false;
		}
		else
			out += "Generation " + to_string(generation) + "\n" + toString() + "\n";
	}
	return out;
}

int** Start::newValue()
{
	int** numbers;
	numbers = new int* [length];
	for (int k = 0; k < length; k++)
	{
		numbers[k] = new int[height];
	}

	int j, k;
	//count neighbors
	int counter;
	for (j = 0; j < length; j++)
	{
		for (k = 0; k < height; k++)
		{
			counter = checkNeighbor(j, k);
			
			//game rules
			if ((counter <= 1) || (counter >= 4))
				numbers[j][k] = DEAD;
			else if (counter == 2)
				numbers[j][k] = result[j][k];
			else if (counter == 3)
				numbers[j][k] = LIVE;

		}
	}
	

	return numbers;
}

int Start::checkNeighbor(int j, int k)
{
	int counter = 0;
	int h, i, x, y;
	for (h = (-1); h <= 1; h++)
	{
		for (i = (-1); i <= 1; i++)
		{
			x = j + h;
			y = k + i;
			if ((x != j) | (y != k)) //don't check self
			{

				if (mode == 2)
				{
					//Donut
					if (x < 0)
					{
						x += length;
					}
					else if (x >= length)
					{
						x -= length;
					}
					if (y < 0)
					{
						y += height;
					}
					else if (y >= height)
					{
						y -= height;
					}

				}
				else if (mode == 3)
				{
					//Mirror
					if ((x < 0) || (x >= length))
					{
						x = j;
					}
					if ((y < 0) || (y >= height))
					{
						y = k;
					}
				}
				
				if (checkDirection(x, y))
				{
					counter++;
				}

			}
		}
	}

	return counter;
}

bool Start::checkDirection(int row, int column)
{
	if (((row >= 0) && (row < length)) && ((column >= 0) && (column < height)))
	{
		if (result[row][column] == LIVE)
		{
			return true;
		}
	}
	return false;
}


//accessors
void Start::setMode(int mode)
{
	this->mode = mode;
}
int Start::getMode()
{
	return this->mode;
}
int** Start::getMap()
{
	return this->map;
}
int** Start::getResult()
{
	return this->result;
}
string Start::getOutput()
{
	return this->output;
}


string Start::toString()
{
	Import* newest = new Import(height, length, result);
	return newest->toString();
}

bool Start::equals(Start* object)
{
	return ((map == object->getMap()) && (mode == object->getMode()) && (result == object->getResult()));
}