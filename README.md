# GameOfLife

### Overview
*For a class project in CPSC 350 Data Structures and Algorithms at Chapman University, I was told to program Conway's Game of Life with three modes.*
>The program will prompt the user to ask for either a file import or if it should randomly generate a puzzle.  If 'Random' is selected, the user will be asked for dimensions and population so the puzzle can be generated.

>The 'Start' class controls the rules for the game.

### Rules
1. Birth: Each dead cell with three live neighbors will be live in the next generation.
1. Death by Isolation: Each live cell with one or fewer live neighbors will die in the next generation.
1. Death by Overcrowding: Each live cell with four or more live neighbors will die in the next generation.
1. Survival: Each live cell with either two or three live neighbors will remain alive for the next generation.

### Modes
1. Classic
1. Donut
1. Mirror

#### Classes
* Interface.h
* Interface.cpp
* Start.h
* Start.cpp
* Map.h
* Map.cpp
* Generate.h
* Generate.cpp
* Import.h
* Import.cpp

#### Runner
* GameOfLife.cpp

#### Executable
* GameOfLife.exe

#### Test File
* map.txt

#### Test Result
* Result.out
