cmake_minimum_required(VERSION 3.29)
include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main # Important: Specify a version or a commit hash here.
)
FetchContent_MakeAvailable(ftxui)

project(Trabalho_IA)
add_executable(Trabalho_IA
    parser/parser.cpp
    parser/parser.hpp
    search/AStar.cpp
    search/iterativeDepth.cpp
    search/search.hpp
    main.cpp)
target_link_libraries(Trabalho_IA
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)


set(CMAKE_CXX_STANDARD 14)

include_directories(parser)
include_directories(search)

