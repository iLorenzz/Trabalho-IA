#include "parser.hpp"

// Converte o labirinto do .txt para uma matriz e salva seu inicio e fim
vector<vector<int>> mazeToMatrix(Pair &start, Pair &end, int mazeSize) {

    vector<vector<int>> matrix(mazeSize, vector<int>(mazeSize, 0));
    ifstream file("../mazes/" + to_string(mazeSize - 1) + "x" + to_string(mazeSize - 1) + "/exemplo_labirinto.txt");
    char character;
    int line, column;
    line = column = 0;

    while(file.get(character)) {

        // Se pulou linha, nova linha e coluna volta a 0
        if(character == '\n') {
            line++;
            column = 0;
            continue;
        } else {
            // Se nao, soma 1 na coluna
            matrix[line][column] = character - '0'; 
            column++;
        }
        
        // Verifica se e inicio ou final
        if(character == '2') {
            start.first = line;
            start.second = column - 1;
        } else if(character == '3') {
            end.first = line;
            end.second = column - 1;
        }
    }

    return matrix;
}
