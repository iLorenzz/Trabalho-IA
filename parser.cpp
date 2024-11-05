#include <vector>
#include <fstream>

using namespace std;

vector<vector<int>> mazeToMatrix(vector<int> start, vector<int> end, int n) {

    vector<vector<int>> matrix;
    ifstream file("mazes/" + to_string(n) + "x" + to_string(n) + "/exemplo_labirinto.txt");
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
        }
        
        if(character == '2') {
            start[0] = line;
            start[1] = column;
        } else if(character == '3') {
            end[0] = line;
            end[1] = column;
        }
    }

    return matrix;
}
