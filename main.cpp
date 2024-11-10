//#include "cmake-build-debug/_deps/ftxui-src/include/ftxui/component/component.hpp"
#include <iostream>
#include <vector>
#include <tuple>
#include "search/iterativeDepth.hpp"
#include "search/AStar.hpp"
#include "parser/parser.hpp"
#include "gui/gui.hpp"

int main() {

	gui_init();

	// Pair start, end;
	// int mazeSize = 201;
	//
	// vector<vector<int>> maze = mazeToMatrix(start, end, mazeSize);
	//
	// vector<Pair> solution = AStar(maze, start, end, mazeSize);
	//
	// cout << start.first << " " << start.second << endl;
	//
	// if(solution.empty()) {
	// 	cout << "Solução não encontrada!" << endl;
	// } else {
	// 	for(int i = 0; i < solution.size(); i++) {cout << "(" << solution[i].first << ", " << solution[i].second << ")" << endl;}
	// }

	return 0;
}
