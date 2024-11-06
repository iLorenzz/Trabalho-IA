#ifndef ITERATIVEDEPTH_HPP
#define ITERATIVEDEPTH_HPP

#include <vector>
#include <utility>
#include "search.hpp"

vector<Pair> iterativeDepthSearch(const vector<vector<int>> maze, Pair start);

bool depthLimitedSearch(const vector<vector<int>> maze, vector<vector<bool>> &visited,
    Pair position, int depth, int limit, vector<Pair> &path);

#endif