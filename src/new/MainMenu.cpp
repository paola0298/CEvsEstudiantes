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
    get_node("/root/GameVariables")->call("_setType", true);

    // get genetics node & generate population
    get_node("/root/StudentGenetics")->call("set_population_size", 5);
    get_node("/root/StudentGenetics")->call("generate_population");
    get_node("/root/StudentGenetics")->call("print_students");
    
    get_tree()->change_scene(String("scenes/Game.tscn"));
    
    //  bool responde = get_node("/root/GameVariables")->call("_getType");
    // if (responde) 
    //     Godot::print(String("responde"));
}

void MainMenu::_on_Collective_pressed() {
    get_node("/root/GameVariables")->call("_setType", false);

    // get genetics node & generate population
    get_node("/root/StudentGenetics")->call("generate_population");
    get_node("/root/StudentGenetics")->call("print_students");
    get_node("/root/StudentGenetics")->call("calculate_fitness");
    

    get_tree()->change_scene(String("scenes/Game.tscn"));
     
    // bool responde = get_node("/root/GameVariables")->call("_getType");
    // if (!responde) 
    //     Godot::print(String("responde"));
}

void MainMenu::_on_Exit_pressed() {
    get_tree()->quit();
}