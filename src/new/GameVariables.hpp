#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>

#include <vector>

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
            void set_actual_defense(int defense);
            int get_actual_defense();
            void set_actual_defense_quit(int defense);
            int get_actual_defense_quit();
            void defense_added(int defense_code, float x, float y);

        private:
            bool gameType;
            int actual_defense_to_put = 1;
            int actual_defense_to_remove = 1;
            int archer_added = 0;
            int mage_added = 0;
            int fire_added = 0;
            int gunner_added = 0;
            
            std::vector<std::vector<float>> defenses_in_map;

    };

}