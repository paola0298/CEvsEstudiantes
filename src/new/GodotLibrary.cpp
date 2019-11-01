#include "MainMenu.hpp"
#include "GameVariables.hpp"
#include "Game.hpp"
// #include "PathGenerator.hpp"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
    godot::register_class<godot::MainMenu>();
    godot::register_class<godot::GameVariables>();
    godot::register_class<godot::Game>();
    // godot::register_class<godot::PathGenerator>();
}