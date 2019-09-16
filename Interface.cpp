#include "Interface.h"

Interface::Interface()
{
	init();
}
Interface::~Interface()
{
	delete world;
	delete start;
}

void Interface::init()
{
	//bools to ask again if input fails
	bool inputAgain = true;
	bool fileAgain = true;
	bool dimAgain = true;

	int input;
	int height, length;
	float pop; //population density

	cout << "\nWelcome to the Game of Life!" << endl;
	while (inputAgain)
	{
		// prompt user how to start
		cout << "What map do you want to use?" << endl;
		cout << "1) File Input\n2) Random" << endl;
		cin >> input;
		if (input == 1) //File Input
		{
			while (fileAgain)
			{
				cout << "Enter the file path: " << endl;
				cin >> file;
				//call files.map to validate file
				fileAgain = openWorld();
			}
			inputAgain = false;
		}
		else if (input == 2) //random
		{
			while (dimAgain)
			{
				cout << "Enter the number of rows: " << endl;
				cin >> height;
				if (height > 0)
				{
					dimAgain = false;
				}
				else if (cin.fail())
				{
					cout << "Invalid input, try again." << endl;
					cin.clear();
					cin.ignore();
				}
			}
			dimAgain = true;
			while (dimAgain)
			{
				cout << "Enter the number of columns: " << endl;
				cin >> length;
				if (length > 0)
				{
					dimAgain = false;
				}
				else if (cin.fail())
				{
					cout << "Invalid input, try again." << endl;
					cin.clear();
					cin.ignore();
				}
			}
			dimAgain = true;
			while (dimAgain)
			{
				cout << "Enter a decimal value (from 0 to 1) for the initial population density: " << endl;
				cin >> pop;
				if ((pop > 0) && (pop <= 1))
				{
					dimAgain = false;
				}
				else if (cin.fail())
				{
					cout << "Invalid input, try again." << endl;
					cin.clear();
					cin.ignore();
				}
			}
		
			world = new Generate(height, length, pop);
			inputAgain = false;
		}
		else
		{
			cout << "Invalid input, try again." << endl;
			cin.clear();
			cin.ignore();
		}
	}
	// prompt user to choose mode and how to print generations
	string modeString;
	int mode;
	bool modeAgain = true;
	while (modeAgain)
	{
		cout << "Which mode would you like to play?" << endl;
		cout << "1) Classic\n2) Donut\n3) Mirror" << endl;
		cin >> modeString;
		mode = atoi(modeString.c_str());
		if ((mode == 1) | (mode == 2) | (mode == 3))
		{
			modeAgain = false;
		}
		else
		{
			cout << "Invalid input, try again." << endl;
			cin.clear();
			cin.ignore();
		}
	}
	
	//call rules to get game started
	start = new Start(world, mode);
	ofstream writer;
	string fileOut = "Result.out";
	writer.open(fileOut);
	writer << start->getOutput() << endl;
	writer.close();
	cout << fileOut << " has been created." << endl;
	cin.ignore();
}

bool Interface::openWorld()
{
	ifstream reader;
	bool check = false;

	reader.open(file);
	check = checkFile(reader);
	if (check == true)
	{
		//commit map info to class
		chooseMap(reader);
		reader.close();
		return false;
	}
	reader.close();

	return true;
}

//functions
bool Interface::checkFile(ifstream& reader)
{
	bool isValid = false;
	if (reader)
	{
		//read map file
		isValid = true;
	}
	else
	{
		//file does not exist
		cout << "Your file " << file << " does not exist." << endl;
		exit(0);
	}
	return isValid;
}

void Interface::chooseMap(ifstream& reader)
{
	//read map files
	string nextLine;
	int counter = 0;
	int h = 0;
	int i;
	int** map;
	int height = 1;
	int length = 1;
	//allocate space for array
	map = new int* [height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new int[length];
	}
	while (getline(reader, nextLine))
	{
		//read each lines
		if (counter == 0)
		{
			//convert string to int
			//error check
			if (isdigit(nextLine[0]))
			{
				height = stoi(nextLine);
				if (height < 1)
				{
					exitSequence();
				}
			}
			else
			{
				exitSequence();
			}
		}
		else if (counter == 1)
		{
			if (isdigit(nextLine[0]))
			{
				length = stoi(nextLine);
				if (length < 1)
				{
					exitSequence();
				}
			}
			else
			{
				exitSequence();
			}
		}
		else if (counter > 1)
		{
			if (counter == 2)
			{
				
				//allocate space for array
				map = new int* [height];
				for (int i = 0; i < height; i++)
				{
					map[i] = new int[length];
				}
			}


			if ((nextLine.size() != length) && (counter > 1))
			{
				//error
				exitSequence();
			}
			else
			{
				//assign array
				for (i = 0; i < length; i++)
				{
					if (nextLine[i] == DEAD_CHAR)
					{
						map[h][i] = DEAD_INT;
					}
					else if (nextLine[i] == LIVE_CHAR)
					{
						map[h][i] = LIVE_INT;
					}
					else
					{
						exitSequence();
					}

				}
				h++;
			}
		}
		counter++;
	}
	//error check, see if array size is equal to height
	if (h != height)
	{
		exitSequence();
	}
	world = new Import(height, length, map);
}

void Interface::exitSequence()
{
	cout << "ERROR: The file " << file << " is invalid." << endl;
	exit(0);
}

string Interface::toString()
{
	return start->getOutput();
}
