#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pair;

int manhattanHeuristic(Pair currentPosition , Pair end);
vector<int> AStar(vector<vector<int>> maze, Pair start);
