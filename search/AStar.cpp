#include "AStar.hpp"

#include <iostream>

int manhattanHeuristic(Pair currentPosition , Pair end){
    return abs((currentPosition.first - end.first)) + abs((currentPosition.second - end.second));
}

vector<Pair> reconstructPath(NodeAStar* endNode) {
    
    stack<Pair> inversePath;
    NodeAStar node = *endNode;

    while(node.parent != NULL) {
        inversePath.push(node.position);
        node = *node.parent;
    }

    inversePath.push(node.position);
    vector<Pair> path;
    while(!inversePath.empty()) {
        path.push_back(inversePath.top());
        inversePath.pop();
    }

    return path;
}

vector<Pair> AStar(vector<vector<int>> maze, Pair start, Pair end, int mazeSize){

    priority_queue<NodeAStar*, vector<NodeAStar*>, CompareF> aStarQueue;
    NodeAStar* currentNode;
    vector<vector<bool>> visitedSpaces(mazeSize, vector<bool>(mazeSize, false));

    NodeAStar* root = new NodeAStar(start, 0, manhattanHeuristic(start, end), NULL);
    aStarQueue.push(root);

    while(!aStarQueue.empty()) {
        currentNode = aStarQueue.top();
        aStarQueue.pop();

        if(end == currentNode->position) {
            return reconstructPath(currentNode);
        }

        visitedSpaces[currentNode->position.first][currentNode->position.second] = true;

        // Explore neighbours
        for(auto direction : MOVEMENTS) {

            Pair newPosition = {currentNode->position.first + direction.first, currentNode->position.second + direction.second};
            if(isStepValid(newPosition, maze, visitedSpaces)) {

                int newDistance = currentNode->currentDistance + 1;
                int newHeuristic = manhattanHeuristic(newPosition, end);

                NodeAStar* nextNode = new NodeAStar(newPosition, newDistance, newHeuristic, currentNode);

                aStarQueue.push(nextNode);
            }
        }
    }

    return {};
}
