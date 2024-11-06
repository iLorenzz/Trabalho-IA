#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>
#include <utility>
#include "search.hpp"

struct NodeAStar {
    Pair position;
    int currentDistance, heuristic;
    NodeAStar* parent;

    NodeAStar(Pair position, int currentDistance, int heuristic, NodeAStar* parent):
        position(position), currentDistance(currentDistance), heuristic(heuristic), parent(parent) {}
};

struct CompareF {
    bool operator()(NodeAStar *a, NodeAStar* b) {
        return (a->currentDistance + a->heuristic) > (b->currentDistance + b->heuristic);
    }
};

int manhattanHeuristic(Pair currentPosition , Pair end);

vector<Pair> reconstructPath(NodeAStar* endNode);

vector<Pair> AStar(vector<vector<int>> maze, Pair start, Pair end, int mazeSize);

#endif