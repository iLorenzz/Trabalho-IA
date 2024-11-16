#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <vector>
#include "../search/search.hpp"

// Converte o labirinto do .txt para uma matriz e salva seu inicio e fim
vector<vector<int>> mazeToMatrix(Pair &start, Pair &end, int mazeSize);

#endif
