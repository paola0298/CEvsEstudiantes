#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>

namespace godot {
    class Game : public Node2D {
        GODOT_CLASS(Game, Node2D);

        public:
            static void _register_methods();

            Game();
            ~Game();

            void _init();
            void _ready();

            void _process(float delta);

        private:
            bool gameType;
            int matrix[10][10];
             

    };

}