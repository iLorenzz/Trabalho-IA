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

bool isValid(Pair direction, Pair position, vector<vector<int>> maze, vector<vector<bool>> visitedSpaces, int mazeSize) {

    int newX, newY;
    newX = position.first + direction.first;
    newY = position.second + direction.second;

    if(newX >= 0 && newX < mazeSize && newY >= 0 && newY < mazeSize &&
       maze[newX][newY] != 1 && !visitedSpaces[newX][newY]) {
        return true;
    }

    return false;
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
             if(isValid(direction, currentNode->position, maze, visitedSpaces, mazeSize)) {

                Pair newPosition = {currentNode->position.first + direction.first, currentNode->position.second + direction.second};
                int newDistance = currentNode->currentDistance + 1;
                int newHeuristic = manhattanHeuristic(newPosition, end);

                NodeAStar* nextNode = new NodeAStar(newPosition, newDistance, newHeuristic, currentNode);

                aStarQueue.push(nextNode);
             }
        }
    }

    return {};
}
