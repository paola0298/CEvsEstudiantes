#include <vector>
#include <iostream>
#include <core/Godot.hpp>
#include <Node.hpp>

namespace godot {
    class PathGenerator : Node {
        GODOT_CLASS(PathGenerator, Node);

        public:
            PathGenerator(std::vector<std::vector<int>> matrix);
            ~PathGenerator();

            static void _register_methods();
            void _init();
            void _generate_path();
            std::vector<std::vector<int>> _get_Path();
            void printLab() const;
            void printLabResuelto() const;
        
        private:
            std::vector<std::vector<int>> path;
            std::vector<std::vector<int>> matrix;
            void addPathToMatrix(int, int);
            std::vector<int> findEnter() const;
    };
}