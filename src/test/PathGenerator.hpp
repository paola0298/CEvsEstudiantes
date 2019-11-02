#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>
#include <Array.hpp>
#include <Variant.hpp>

#include <vector>

namespace godot {
    class PathGenerator : public Node {
        GODOT_CLASS(PathGenerator, Node);

        public:
            PathGenerator();
            ~PathGenerator();

            void _init();
            void _ready();
            void _process(float delta);
            static void _register_methods();
            
            
            Array getRoute(Array row0,Array row1, Array row2,Array row3,Array row4,Array row5,Array row6,Array row7,Array row8,Array row9);

        
            void addPathToMatrix(int i, int j);
            std::vector<int> findEnter();
            int pathS = 0;
            void setMatrix(Array row0,Array row1, Array row2,Array row3,Array row4,Array row5,Array row6,Array row7,Array row8,Array row9);

            void _generate_path();
            void printLab();
            void printLabResuelto();
            Array vector_to_array();
            std::vector<std::vector<int>> path;
            // int path[100][100];
            std::vector<std::vector<int>> matrix;
            
        private:
            // int *matrix[10];
    };
}