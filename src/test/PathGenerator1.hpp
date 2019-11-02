#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>

#include <vector>
#include <iostream>

namespace godot {
    class PathGenerator : Node {
        GODOT_CLASS(PathGenerator, Node);

        public:
            PathGenerator();
            PathGenerator(int *matrix);
            ~PathGenerator();

            void _init();
            void _ready();
            void _process(float delta);
            static void _register_methods();

            void _generate_path();
            int* _get_Path();
            void printLab();
            void printLabResuelto();
        
        private:
            // std::vector<std::vector<int>> path;
            int path[100][100];
            // std::vector<std::vector<int>> matrix;
            int *matrix[10];
            void addPathToMatrix(int i, int j);
            int* findEnter();
            int pathS = 0;
    };
}