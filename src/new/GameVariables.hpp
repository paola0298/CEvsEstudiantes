#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>

namespace godot {
    class GameVariables : public Node {
        GODOT_CLASS(GameVariables, Node);

        public:
            static void _register_methods();

            GameVariables();
            ~GameVariables();

            void _init();
            void _ready();

            void _setType(bool type);
            bool _getType();

        private:
            bool gameType;

    };

}