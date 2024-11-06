#include "search.hpp"

// Verifica se um passo é válido (está dentro do labirinto, não foi visitado e não é uma parede)
bool isStepValid(Pair position, vector<vector<int>> maze, vector<vector<bool>> visited) {
    int x = position.first;
    int y = position.second;
    int mazeSize = maze.size();

    return (
        x >= 0 &&
        x < mazeSize &&
        y >= 0 &&
        y < mazeSize &&
        maze[x][y] != 1 &&
        !visited[x][y]
    );
}

