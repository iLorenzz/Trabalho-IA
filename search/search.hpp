#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> Pair;

const vector<Pair> MOVEMENTS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isStepValid(Pair position, vector<vector<int>> maze, vector<vector<bool>> visited);


#endif
