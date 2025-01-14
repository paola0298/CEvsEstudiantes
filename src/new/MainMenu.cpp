#include "MainMenu.hpp"

using namespace godot;

void MainMenu::_register_methods() {
    register_method("_init", &MainMenu::_init);
    register_method("_on_Individual_pressed", &MainMenu::_on_Individual_pressed);
    register_method("_on_Collective_pressed", &MainMenu::_on_Collective_pressed);
    register_method("_on_Exit_pressed", &MainMenu::_on_Exit_pressed);
}

MainMenu::MainMenu() { }

MainMenu::~MainMenu() { }

void MainMenu::_init() { }

void MainMenu::_on_Individual_pressed() {
    get_tree()->change_scene(String("scenes/Game.tscn"));
    get_node("/root/GameVariables")->call("_setType", true);
    //  bool responde = get_node("/root/GameVariables")->call("_getType");
    
    // if (responde) 
    //     Godot::print(String("responde"));
}

void MainMenu::_on_Collective_pressed() {
    get_tree()->change_scene(String("scenes/Game.tscn"));
    get_node("/root/GameVariables")->call("_setType", false);
    // bool responde = get_node("/root/GameVariables")->call("_getType");
    
    // if (!responde) 
    //     Godot::print(String("responde"));
}

void MainMenu::_on_Exit_pressed() {
    get_tree()->quit();
}