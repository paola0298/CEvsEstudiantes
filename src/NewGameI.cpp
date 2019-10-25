#include "NewGameI.hpp"

using namespace godot;

void NewGameI::_register_methods() {
    register_method("_ready", &NewGameI::_ready);
    register_method("_process", &NewGameI::_process);
    register_method("_on_Individual_pressed", &NewGameI::_on_Individual_pressed);
    register_method("_on_Collective_pressed", &NewGameI::_on_Collective_pressed);
    register_method("_on_Exit_pressed", &NewGameI::_on_Exit_pressed);
}

void NewGameI::_init() { }

NewGameI::NewGameI() { }

NewGameI::~NewGameI() { }

void NewGameI::_process(float delta) { }

void NewGameI::doAction() {
    Input *i = Input::get_singleton();
    get_tree()->change_scene(String("res//Scene.tscn"));
}

void NewGameI::_ready() {
    String message = "Getting node";

    Godot::print(message);
    get_node(NodePath("MarginContainer/VBoxContainer/HBoxContainer/VBoxContainer/MenuOptions/Individual"))->connect(String("pressed"), this, String("_on_Individual_pressed"));
    get_node(NodePath("MarginContainer/VBoxContainer/HBoxContainer/VBoxContainer/MenuOptions/Colectiva"))->connect(String("pressed"), this, String("_on_Collective_pressed"));
    get_node(NodePath("MarginContainer/VBoxContainer/HBoxContainer/VBoxContainer/MenuOptions/Salir"))->connect(String("pressed"), this, String("_on_Exit_pressed"));
    
}
 

void NewGameI::_on_Individual_pressed() {
    String message = "New individual game";
    Godot::print(message);
    get_tree()->change_scene(String("Scene.tscn"));
}

void NewGameI::_on_Collective_pressed() {
    String message = "New Collective game";
    Godot::print(message);
    get_tree()->change_scene(String("Scene.tscn"));
}


void NewGameI::_on_Exit_pressed() {
    String message = "Exit";
    Godot::print(message);
    get_tree()->quit();

} 


