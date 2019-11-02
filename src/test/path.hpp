#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>
#include <Array.hpp>

#include <vector>
#include <iostream>

namespace godot {
    class PathGenerator: public Node {
        GODOT_CLASS(PathGenerator, Node);

        public:
            PathGenerator();
            ~PathGenerator();

            void get_path(Array matrix);
                // void get_path(int (&matrix)[10][10]);

            void _init();
            void _ready();
            void _process(float delta);
            static void _register_methods();

        private:
            int path_s;
            int path[100][100];

            void generate_path(Array matrix);
            int * find_enter(Array matrix);
            void add_path(Array matrix, int i, int j);
            void print_maze(Array matrix);

            int get_data(Array matrix, int i, int j);


            // void generate_path(int (&matrix)[10][10]);
            // int * find_enter(int (&matrix)[10][10]);
            // void add_path(int i, int j, int (&matrix)[10][10]);
            // void print_maze(int (&matrix)[10][10]);
            void print_maze_solution();
    };
}
