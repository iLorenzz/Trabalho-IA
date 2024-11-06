//#include "cmake-build-debug/_deps/ftxui-src/include/ftxui/component/component.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include "search/iterativeDepth.hpp"
#include "search/AStar.hpp"
#include "parser/parser.hpp"

int main() {
    Pair start, end;
    int mazeSize = 11;
    vector<vector<int>> maze = mazeToMatrix(start, end, mazeSize);
    
    vector<Pair> solution = iterativeDepthSearch(maze, start);
    
    cout << start.first << " " << start.second << endl;
    
    if(solution.empty()) {
      cout << "Solução não encontrada!" << endl;
    }
    else {
      for(int i = 0; i < solution.size(); i++) {
        cout << "(" << solution[i].first << ", " << solution[i].second << ")" << endl;
      }
    }
    
    return 0;
}
