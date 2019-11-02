#include "GuiManagement.hpp"

using namespace godot;

void GuiManagement::_register_methods() {
    register_method("_init", &GuiManagement::_init);
    register_method("_ready", &GuiManagement::_ready);
    register_method("_process", &GuiManagement::_process);
    register_method("_on_Archer_pressed", &GuiManagement::_on_Archer_pressed);
    register_method("_on_Fire_pressed", &GuiManagement::_on_Fire_pressed);
    register_method("_on_Gunner_pressed", &GuiManagement::_on_Gunner_pressed);
    register_method("_on_Mage_pressed", &GuiManagement::_on_Mage_pressed);
    register_method("_on_Upgrade_pressed", &GuiManagement::_on_Upgrade_pressed);
    register_method("_on_Remove_pressed", &GuiManagement::_on_Remove_pressed);
}

GuiManagement::GuiManagement() { }

GuiManagement::~GuiManagement() { }

void GuiManagement::_init() { }

void GuiManagement::_ready() { }

void GuiManagement::_process(float delta) { }

void GuiManagement::_on_Archer_pressed() { 
    Godot::print("Archer pressed");
    get_node("/root/GameVariables")->call("set_actual_defense", 1);
}
void GuiManagement::_on_Mage_pressed() { 
    Godot::print("Mage pressed");
    get_node("/root/GameVariables")->call("set_actual_defense", 2);
}
void GuiManagement::_on_Gunner_pressed() { 
    Godot::print("Gunner pressed");
    get_node("/root/GameVariables")->call("set_actual_defense", 3);
}
void GuiManagement::_on_Fire_pressed(){ 
    Godot::print("Fire pressed");
    get_node("/root/GameVariables")->call("set_actual_defense", 4);
}
void GuiManagement::_on_Upgrade_pressed(){
    Godot::print("Upgrade pressed");
 }
void GuiManagement::_on_Remove_pressed(){
    Godot::print("Remove pressed");
}