#include "iterativeDepth.hpp"

#include <ctime>
#include <iostream>
#include <ostream>

// Busca em profundidade iterativa (repetidas buscas em profundidade limitadas)
// Retorna um vector com a solução encontrada
vector<Pair> iterativeDepthSearch(const vector<vector<int>> maze, Pair start, int &size, int &expansions, double &time) {
    
    clock_t timeStart = clock();
    //time_t timeStart = std::time(nullptr);
    int mazeSize = maze.size();
    expansions = 0;

    // Buscas em profundidades com limites crescentes
    for(int limit = 0; limit < pow(mazeSize, 2); limit++) {
        // Inicializa todos os pontos como não visitados
        vector<vector<bool>> visited(mazeSize, vector<bool>(mazeSize, false));
        vector<Pair> solutionPath;

        if(depthLimitedSearch(maze, visited, start, 0, limit, solutionPath, expansions)) {
            //time_t timeEnd = std::time(nullptr);
            clock_t timeEnd = clock();
            time = difftime(timeEnd, timeStart)/CLOCKS_PER_SEC;
            size = solutionPath.size();
            return solutionPath;
        }
    }

    // Nenhum caminho encontrado
    //time_t timeEnd = std::time(nullptr);
    clock_t timeEnd = clock();
    time = std::difftime(timeEnd, timeStart)/CLOCKS_PER_SEC;
    size = -1;
    return {};
}

// Busca em profundidade limitada
bool depthLimitedSearch(const vector<vector<int>> maze, vector<vector<bool>> &visited,
    Pair position, int depth, int limit, vector<Pair> &path, int &expansions) {

    // Se profundidadede maior que o limite, retorna falso
    if(depth > limit) return false;
    
    // Posicao atual
    int x = position.first;
    int y = position.second;

    // Se posicao atual e o final, retorna true
    if(maze[x][y] == 3) {
        path.push_back(position);
        return true;
    }

    // Vertice foi visitado
    visited[x][y] = true;
    path.push_back(position);

    for(int i = 0; i < MOVEMENTS.size(); i++) {
        Pair newPosition = {
            x + MOVEMENTS[i].first,
            y + MOVEMENTS[i].second
        };

        // Para cada posicao de um vizinho, verificar se o passo eh valido
        if(isStepValid(newPosition, maze, visited)) {
            expansions++;
            if(depthLimitedSearch(maze, visited, newPosition, depth + 1, limit, path, expansions)) {
                return true;
            }
        }
    }

    path.pop_back();
    visited[x][y] = false;
    return false;
}
