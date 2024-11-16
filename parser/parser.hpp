#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <fstream>
#include "parser.hpp"
#include "../search/search.hpp"

using namespace std;

// Converte o labirinto do .txt para uma matriz e salva seu inicio e fim
vector<vector<int>> mazeToMatrix(Pair &start, Pair &end, int mazeSize);

#endif
