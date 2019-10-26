#pragma once

#include <core/Godot.hpp>
#include <Input.hpp>
#include <TextureRect.hpp>
#include <InputEventMouse.hpp>
#include <SceneTree.hpp>
#include <Button.hpp>
#include <Node.hpp>
#include <String.hpp>
#include <Node2D.hpp>


namespace godot {
    class NewGameI:  public Node2D {
        GODOT_CLASS(NewGameI, Node2D);

        public: 
            static void _register_methods();
            void _init();
            void _process(float delta);

            NewGameI();
            ~NewGameI();

            void doAction();
            void _ready();
            void _on_Individual_pressed();
            void _on_Collective_pressed();
            void _on_Exit_pressed();
    };
}