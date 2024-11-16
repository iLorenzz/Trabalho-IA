#include "AStar.hpp"

// Calcula a heuristica pela distancia de Manhattan
int manhattanHeuristic(Pair currentPosition , Pair end){
    return abs((currentPosition.first - end.first)) + abs((currentPosition.second - end.second));
}

// Calcula o caminho reconstruindo-o de trás para frente
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

// Algoritmo A*
vector<Pair> AStar(vector<vector<int>> maze, Pair start, Pair end, int mazeSize, int &size, int &expansions, double &time){

    clock_t timeStart = clock();
    //time_t timeStart = std::time(nullptr);
    expansions = 0;

    priority_queue<NodeAStar*, vector<NodeAStar*>, CompareF> aStarQueue;
    NodeAStar* currentNode;
    vector<vector<bool>> visitedSpaces(mazeSize, vector<bool>(mazeSize, false));

    // Primeiro no da fila -> start
    NodeAStar* root = new NodeAStar(start, 0, manhattanHeuristic(start, end), NULL);
    aStarQueue.push(root);

    // Enquanto a fila estiver com elementos
    while(!aStarQueue.empty()) {
        currentNode = aStarQueue.top();
        aStarQueue.pop();

        // Se o no da fila for o fim
        if(end == currentNode->position) {
            //time_t timeEnd = std::time(nullptr);
            clock_t timeEnd = clock();
            time = difftime(timeEnd, timeStart)/CLOCKS_PER_SEC;
            size = currentNode->currentDistance;
            return reconstructPath(currentNode);
        }

        // No ja foi visitado (nao fazer expansoes futuras nele)
        visitedSpaces[currentNode->position.first][currentNode->position.second] = true;

        // Explore os vizinhos
        for(auto direction : MOVEMENTS) {

            // Nova posicao -> possivel expansao do A*
            Pair newPosition = {currentNode->position.first + direction.first, currentNode->position.second + direction.second};
            if(isStepValid(newPosition, maze, visitedSpaces)) {
            //Se a expansao for valida
                expansions++;
                int newDistance = currentNode->currentDistance + 1;
                int newHeuristic = manhattanHeuristic(newPosition, end);


                NodeAStar* nextNode = new NodeAStar(newPosition, newDistance, newHeuristic, currentNode);
                // Adicionar o no na fila
                aStarQueue.push(nextNode);
            }
        }
    }

    // Nao existem caminhos ate o final do labirinto
    clock_t timeEnd = clock();
    time =  difftime(timeEnd, timeStart)/CLOCKS_PER_SEC;
    return {};
}
