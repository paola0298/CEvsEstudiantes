#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <KinematicBody2D.hpp>

#include <vector>
#include "Student.hpp"

namespace godot {
    class Game : public Node2D {
        GODOT_CLASS(Game, Node2D);

        private:
            bool gameType;
            int matrix[10][10];

            float time_var;
            int wave_enemies = 0;
            std::vector<KinematicBody2D *> enemies_nodes;
            std::vector<Student *> enemies_classes;

            //Scenes to instance
            Ref<PackedScene> enemy_ogre;
            Ref<PackedScene> enemy_mercenary;
            Ref<PackedScene> enemy_harpy;
            Ref<PackedScene> enemy_dark_elf;

        public:
            Game();
            ~Game();

            void _init();
            void _ready();
            void _process(float delta);
            static void _register_methods();
    };
}