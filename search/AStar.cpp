#include "search.hpp"
using namespace std;

int manhattanHeuristic(int currentPosition[2] , int end[2]) {
    return abs(currentPosition[0] - end[0]) + abs(currentPosition[1] - end[1]);
}
