#ifndef ASTAR_HPP
#define ASTAR_HPP

#include "search.hpp"

using namespace std;

// Estrutura de um elemento da fila do A*
// Armazena parent para resgatarmos o tamanho da distancia
struct NodeAStar {
    Pair position;
    int currentDistance, heuristic;
    NodeAStar* parent;

    NodeAStar(Pair position, int currentDistance, int heuristic, NodeAStar* parent):
        position(position), currentDistance(currentDistance), heuristic(heuristic), parent(parent) {}
};

// Comparador da fila do A* (com prioridade)
struct CompareF {
    bool operator()(NodeAStar *a, NodeAStar* b) {
        return (a->currentDistance + a->heuristic) > (b->currentDistance + b->heuristic);
    }
};

// Calcula a heuristica pela distancia de Manhattan
int manhattanHeuristic(Pair currentPosition , Pair end);

// Calcula o caminho reconstruindo-o de trás para frente
vector<Pair> reconstructPath(NodeAStar* endNode);

// Algoritmo A*
vector<Pair> AStar(vector<vector<int>> maze, Pair start, Pair end, int mazeSize, int &size, int &expansions, double &time);

#endif