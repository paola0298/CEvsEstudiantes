#pragma once

#include <core/Godot.hpp>
#include <Button.hpp>

namespace godot {
    class Defense : public Button {
        GODOT_CLASS(Defense, Button);

        public:
            static void _register_methods();
            Defense();
            Defense(int damage);
            ~Defense();

            void _init();
            void _ready();
            void set_damage(int damage);
            int get_damage();
            int get_level();
            void upgrade();

        private:
            int level = 1;
            int credits;
            int hours;
            int requirement_level;
            int evaluation_speed;
            int evaluation_scope;
            int regeneration_time_special;
            int recharge_time_evaluation;

    };
}