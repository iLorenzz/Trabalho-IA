#include <vector>

#include "gui.hpp"

#include "parser.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/event.hpp"

#include "ftxui/component/screen_interactive.hpp"

//
// Created by rzcgl on 06/11/24.
//
using namespace ftxui;
using namespace std;

void clean_canvas(Canvas c) {
    for (int i = 0; i < c.width(); i++) {
        for (int j = 0; j < c.height(); j++) {
            c.DrawPoint(i, j, false);
        }
    }
}

void gui_init() {
    auto screen = ScreenInteractive::TerminalOutput();

    // ---- MAZE ----------------------------------------------------------
    auto maze_canvas = Canvas(250, 250);

    // ---- INFO SCREEN ---------------------------------------------------
    string info = "TEST test teeeeeeeest";

    // ---- MAIN MENU -----------------------------------------------------
    vector<string> maze_size_options {
        "10x10",
        "50x50",
        "100x100",
        "200x200",
    };
    int maze_size_selected = 0;

    vector<string> algorithm_options {
        "A* Pathfinding",
        "Iterative Depth First Search",
    };
    int algorithm_selected = 0;

    auto exit_button = Button("Exit", screen.ExitLoopClosure());
    function<void()> run_action = [&] {
        clean_canvas(maze_canvas);
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
        info = to_string(n);

        Pair a = {0, 0};
        Pair b = {0, 0};

        vector<vector<int>> maze_matrix = mazeToMatrix(a, b, n + 1);

        for (int i = 0; i < maze_matrix.size(); i++) {
            for (int j = 0; j < maze_matrix[i].size(); j++) {
                if (maze_matrix[i][j] == 1) {
                    maze_canvas.DrawPoint(i + 5, j + 5, true, Color::Red);
                }
            }
        }
    };
    auto run_button = Button("RUN", run_action);

    auto main_menu = Container::Vertical({
        Radiobox(&maze_size_options, &maze_size_selected) | border,
        Radiobox(&algorithm_options, &algorithm_selected) | border,
        run_button,
        exit_button,
    });

    // ---- RENDERER ------------------------------------------------------
    auto renderer = Renderer(main_menu, [&] {
        return hbox({
            main_menu->Render() | border,
            canvas(&maze_canvas) | border,
            hflow(paragraph(info)) | border,
        });
    });

    // ---- START SCREEN --------------------------------------------------
    screen.Loop(renderer);
}
