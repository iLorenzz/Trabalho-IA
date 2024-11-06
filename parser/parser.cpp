#include <vector>
#include <fstream>
#include "parser.hpp"
#include "../search/search.hpp"

using namespace std;

vector<vector<int>> mazeToMatrix(Pair start, Pair end, int n) {

    vector<vector<int>> matrix(n, vector<int>(n, 0));;
    ifstream file("../mazes/" + to_string(n) + "x" + to_string(n) + "/exemplo_labirinto.txt");
    char character;
    int line, column;
    line = column = 0;

    while(file.get(character)) {

        if(character == '\n') {
            line++;
            column = 0;
            continue;
        } else {
            matrix[line][column] = character - '0'; 
            column++;
        }
        
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
