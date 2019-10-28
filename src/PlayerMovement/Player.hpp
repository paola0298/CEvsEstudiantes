#pragma once

#include <core/Godot.hpp>
#include <Input.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <KinematicBody2D.hpp>

namespace godot {

    class Player: public KinematicBody2D {
        GODOT_CLASS(Player, KinematicBody2D);

        private:
            Vector2 motion;
        public:
            Player();
            ~Player();
            int SPEED;
            void _init();
            void _process(float delta);
            static void _register_methods();
            void UpdateMotionFromInput(float delta);

            Vector2 cartesian_to_isometric(Vector2 cartesian);
            Vector2 isometric_to_cartesian(Vector2 isometric);
    };

}