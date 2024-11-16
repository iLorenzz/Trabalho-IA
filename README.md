# Pathfinding - AI Final Project 
## Installing
This project can simply be cloned with `git clone https://github.com/iLorenzz/Trabalho-IA.git`. No initial o special configuration is needed.

## Building
Building can be done manually with the following commands from the project's root directory:
```
mkdir build && cd build
cmake .. && make
./Trabalho-IA
```
Or using the included bash script `./build.sh`

Using a fullscreen terminal on a 1920x1080 screen is highly recommended for correct visualisation of larger mazes (100x100, 200x200).

## Features
- Full parsing of `.txt` maze description files (10x10, 50x50, 100x100, 200x200);
- A* Pathfinding with Manhattam heuristic;
- Iterative Depth First Search;
- Intuitive GUI built with [FTXUI](https://github.com/ArthurSonzogni/FTXUI);
- Logging of:
  - Found path size, 
  - Time for pathfinding,
  - Number of expansions;
- Visual representation of maze, found path, and beginning and end points;

## Motivation
The implemented algorithms were firstly chosen for their capacity to find the best path. The A* Pathfinding was specifically chosen as the informed algorithm because of its heuristics (making it reliable to the problem in question), while the Iterative DFS significantly reduces the memory problems the normal DFS might present on larger problems.