#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <queue>
#include <utility>
#include <stack>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

typedef pair<int, int> Pair;

// Direcoes validas a partir de uma determinada posicao (variacoes)
const vector<Pair> MOVEMENTS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Verifica se um passo é válido (está dentro do labirinto, não foi visitado e não é uma parede)
bool isStepValid(Pair position, vector<vector<int>> maze, vector<vector<bool>> visited);

#endif
