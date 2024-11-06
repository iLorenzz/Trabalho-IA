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

// Busca em profundidade iterativa (repetidas buscas em profundidade limitadas)
// Retorna um vector com a solução encontrada
vector<Pair> iterativeDepthSearch(const vector<vector<int>> maze, Pair start) {
    int mazeSize = maze.size();

    // Buscas em profundidades com limites crescentes
    for(int limit = 0; limit < pow(mazeSize, 2); limit++) {
        // Inicializa todos os pontos como não visitados
        vector<vector<bool>> visited(mazeSize, vector<bool>(mazeSize, false));
        vector<Pair> solutionPath;

        if(depthLimitedSearch(maze, visited, start, 0, limit, solutionPath))
            return solutionPath;
    }

    // Nenhum caminho encontrado
    return {};
}

// Busca em profundidade limitada
bool depthLimitedSearch(const vector<vector<int>> maze, vector<vector<bool>> &visited,
    Pair position, int depth, int limit, vector<Pair> &path) {

    if(depth > limit) return false;
    
    int x = position.first;
    int y = position.second;

    if(maze[x][y] == 3) {
        path.push_back(position);
        return true;
    }

    visited[x][y] = true;
    path.push_back(position);

    for(int i = 0; i < MOVEMENTS.size(); i++) {
        Pair newPosition = {
            x + MOVEMENTS[i].first,
            y + MOVEMENTS[i].second
        };

        if(isStepValid(newPosition, maze, visited)) {
            if(depthLimitedSearch(maze, visited, newPosition, depth + 1, limit, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    visited[x][y] = false;
    return false;
}
