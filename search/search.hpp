#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> Pair;

// Movimentos possíveis (+/- 1 em cada direção)
const vector<Pair> MOVEMENTS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isStepValid(Pair position, vector<vector<int>> maze, vector<vector<bool>> visited);

vector<Pair> iterativeDepthSearch(const vector<vector<int>> maze, Pair start);

bool depthLimitedSearch(const vector<vector<int>> maze, vector<vector<bool>> &visited,
    Pair position, int depth, int limit, vector<Pair> &path);

// ==============================

// Busca A*
int manhattanHeuristic(Pair currentPosition , Pair end);
vector<Pair> AStar(vector<vector<int>> maze, Pair start, Pair end, int mazeSize);

#endif
