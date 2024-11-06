#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> Pair;

// Busca em Profundidade Iterativa
// Movimentos possíveis (+/- 1 em cada direção)
const vector<Pair> MOVEMENTS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isStepValid(Pair position, vector<vector<int>> maze, vector<vector<bool>> visited);
vector<Pair> iterativeDepthSearch(const vector<vector<int>> maze, Pair start);
bool depthLimitedSearch(const vector<vector<int>> maze, vector<vector<bool>> &visited,
    Pair position, int depth, int limit, vector<Pair> &path);

// ==============================

// Busca A*
int manhattanHeuristic(Pair currentPosition , Pair end);
vector<int> AStar(vector<vector<int>> maze, Pair start);
