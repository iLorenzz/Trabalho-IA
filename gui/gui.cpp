#include <vector>

#include "gui.hpp"

#include <AStar.hpp>
#include <iterativeDepth.hpp>

#include "parser.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/event.hpp"

#include "ftxui/component/screen_interactive.hpp"

//
// Created by rzcgl on 06/11/24.
//
using namespace ftxui;
using namespace std;

constexpr int CANVAS_SIZE = 220;

Canvas maze_canvas;
string info1 = "Program by Alexandre Santato, Leonardo Rizzo, Lorenzo Dutra and Raphael Zoega";
string info2 = "Iterative search is quite slow starting at 50x50 labyrinths.";
string info3 = "Program might freeze for a couple of seconds; it's normal.";
int maze_size_selected;
int algorithm_selected;

void draw_maze() {
    for (int i = 0; i < maze_canvas.width(); i++) {
        for (int j = 0; j < maze_canvas.height(); j++) {
            maze_canvas.DrawBlock(i, j, false);
        }
    }
    int n;
    switch (maze_size_selected) {
        case 0:
            n = 10;
            break;
        case 1:
            n = 50;
            break;
        case 2:
            n = 100;
            break;
        case 3:
            n = 200;
            break;
        default:
            n = 10;
    }

    Pair start = {0, 0};
    Pair end = {0, 0};

    vector<vector<int>> maze_matrix = mazeToMatrix(start, end, n + 1);

    int position_correction = (CANVAS_SIZE / 2) - (n / 2);

    for (int i = 0; i < maze_matrix.size(); i++) {
        for (int j = 0; j < maze_matrix[i].size(); j++) {
            if (maze_matrix[i][j] == 0) {
                maze_canvas.DrawPoint(i + position_correction, j + position_correction, true, Color::Black);
            }
        }
    }

    vector<Pair> solution;
    int path_size;
    int expansions;
    double time_to_find;

    if (algorithm_selected == 0) {
        solution = AStar(maze_matrix, start, end, n+1, path_size, expansions, time_to_find);

        for (auto & i : solution) {
            maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, false, Color::Gold1);
            maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, true, Color::Gold1);
        }
    } else {
        solution = iterativeDepthSearch(maze_matrix, start, path_size, expansions, time_to_find);

        for (auto & i : solution) {
            maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, false, Color::Gold1);
            maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, true, Color::Gold1);
        }
    }

    info1 = "Pathfinding time: " + to_string(time_to_find) + "ms";
    info2 = "Path length: " + to_string(path_size);
    info3 = "Expansions: " + to_string(expansions);

    maze_canvas.DrawBlock(start.first + position_correction, start.second + position_correction, true, Color::Green);
    maze_canvas.DrawBlock(end.first + position_correction, end.second + position_correction, true, Color::Red);
}

void gui_init() {
    auto screen = ScreenInteractive::TerminalOutput();

    // ---- MAZE ----------------------------------------------------------
    maze_canvas = Canvas(CANVAS_SIZE, CANVAS_SIZE);

    // ---- MAIN MENU -----------------------------------------------------
    vector<string> maze_size_options {
        "10x10",
        "50x50",
        "100x100",
        "200x200",
    };
    maze_size_selected = 0;

    vector<string> algorithm_options {
        "A* Pathfinding",
        "Iterative Depth First Search",
    };
    algorithm_selected = 0;

    auto exit_button = Button("Exit", screen.ExitLoopClosure());

    function<void()> run_action = [&] {
        thread bt(draw_maze);
        bt.join();
    };
    auto run_button = Button("RUN", run_action);

    function<void()> clear_screen_action = [&] {
        for (int i = 0; i < maze_canvas.width(); i++) {
            for (int j = 0; j < maze_canvas.height(); j++) {
                maze_canvas.DrawBlock(i, j, false);
            }
        }

        info1 = "Program by Alexandre S., Leonardo R., Lorenzo D. e Raphael Z.";
        info2 = "Iterative search is quite slow starting at 50x50 labyrinths.";
        info3 = "Program might freeze for a couple of seconds; it's normal.";
    };
    auto clear_screen_button = Button("Clear", clear_screen_action);

    auto main_menu = Container::Vertical({
        Radiobox(&maze_size_options, &maze_size_selected) | border,
        Radiobox(&algorithm_options, &algorithm_selected) | border,
        run_button,
        clear_screen_button,
        exit_button,
    });

    // ---- RENDERER ------------------------------------------------------
    auto renderer = Renderer(main_menu, [&] {
        return hbox({
            main_menu->Render() | border,
            canvas(&maze_canvas) | border,
            vflow({
                paragraph(info1),
                paragraph(" "),
                paragraph(info2),
                paragraph(" "),
                paragraph(info3)
                }) | border,
        });
    });

    // ---- START SCREEN --------------------------------------------------
    screen.Loop(renderer);
}
