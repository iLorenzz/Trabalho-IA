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

void gui_init() {
    auto screen = ScreenInteractive::TerminalOutput();

    // ---- MAZE ----------------------------------------------------------
    auto maze_canvas = Canvas(CANVAS_SIZE, CANVAS_SIZE);

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
        info = to_string(n);

        Pair start = {0, 0};
        Pair end = {0, 0};

        vector<vector<int>> maze_matrix = mazeToMatrix(start, end, n + 1);

        info.append(" | start: ");
        info.append(to_string(start.first));
        info.append(", ");
        info.append(to_string(start.second));
        info.append(" | end: ");
        info.append(to_string(end.first));
        info.append(", ");
        info.append(to_string(end.second));

        int position_correction = (CANVAS_SIZE / 2) - (n / 2);
        int scale_factor = 200 / n;

        for (int i = 0; i < maze_matrix.size(); i++) {
            for (int j = 0; j < maze_matrix[i].size(); j++) {
                if (maze_matrix[i][j] == 0) {
                    maze_canvas.DrawPoint(i + position_correction, j + position_correction, true, Color::Black);
                }
            }
        }

        vector<Pair> solution;

        if (algorithm_selected == 0) {
            solution = AStar(maze_matrix, start, end, n+1);

            for (auto & i : solution) {
                maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, false, Color::Gold1);
                maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, true, Color::Gold1);
            }
        } else {
            solution = iterativeDepthSearch(maze_matrix, start);

            for (auto & i : solution) {
                maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, false, Color::Gold1);
                maze_canvas.DrawPoint(i.first + position_correction, i.second + position_correction, true, Color::Gold1);
            }
        }

        maze_canvas.DrawBlock(start.first + position_correction, start.second + position_correction, true, Color::Green);
        maze_canvas.DrawBlock(end.first + position_correction, end.second + position_correction, true, Color::Red);
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
