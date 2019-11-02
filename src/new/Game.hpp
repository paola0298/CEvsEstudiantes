#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <PackedScene.hpp>
#include <Variant.hpp>
#include <Array.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <Navigation2D.hpp>
#include <Line2D.hpp>
#include <KinematicBody2D.hpp>
#include <Input.hpp>
#include <InputEvent.hpp>
#include <PoolArrays.hpp>
#include <InputEventMouseButton.hpp>
#include <Sprite.hpp>

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

            Navigation2D *navigation;
            Line2D *line;
            KinematicBody2D *mage;
            void _unhandled_input(InputEvent *event);

        private:
            bool gameType;
            
    };

}