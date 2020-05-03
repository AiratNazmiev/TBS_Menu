cmake_minimum_required(VERSION 3.15)
project(TBS)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(TBS main.cpp game.h game.cpp Menu.cpp Menu.h Button.cpp Button.h textbox.cpp textbox.h Field.cpp Field.h hexagonal_tile.cpp hexagonal_tile.h)

target_link_libraries(TBS sfml-graphics
                          sfml-audio
                          sfml-window
                          sfml-system)
