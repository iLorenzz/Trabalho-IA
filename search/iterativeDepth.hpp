#ifndef ITERATIVEDEPTH_HPP
#define ITERATIVEDEPTH_HPP

#include <vector>
#include <utility>
#include "search.hpp"

// Busca em profundidade iterativa (repetidas buscas em profundidade limitadas)
// Retorna um vector com a solução encontrada
vector<Pair> iterativeDepthSearch(const vector<vector<int>> maze, Pair start, int &size, int &expansions, double &time);

// Busca em profundidade limitada
bool depthLimitedSearch(const vector<vector<int>> maze, vector<vector<bool>> &visited,
    Pair position, int depth, int limit, vector<Pair> &path, int &expansions);

#endif