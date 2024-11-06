#include "search.hpp"

int manhattanHeuristic(Pair currentPosition , Pair end){
    return abs((currentPosition.first - end.first)) + abs((currentPosition.second - end.second));
}

vector<int> AStar(vector<vector<int>> maze, Pair start){
    priority_queue<Pair> AStarQueue;
}
