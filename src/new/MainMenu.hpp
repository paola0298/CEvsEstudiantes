#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>

namespace godot {

    class MainMenu : public Node2D {
        GODOT_CLASS(MainMenu, Node2D);

        public:
            MainMenu();
            ~MainMenu();

            static void _register_mehthods();
            void _init();
            void _on_Individual_pressed();
            void _on_Collective_pressed();
            void _on_Exit_pressed();
    };

}

