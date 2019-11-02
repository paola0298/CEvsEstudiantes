#include "GameVariables.hpp"

using namespace godot;

void GameVariables::_register_methods() {
    register_method("_init", &GameVariables::_init);
    register_method("_ready", &GameVariables::_ready);
    register_method("_setType", &GameVariables::_setType);
    register_method("_getType", &GameVariables::_getType);
    register_method("get_actual_defense", &GameVariables::get_actual_defense);
    register_method("set_actual_defense", &GameVariables::set_actual_defense);
    register_method("get_actual_defense_quit", &GameVariables::get_actual_defense_quit);
    register_method("set_actual_defense_quit", &GameVariables::set_actual_defense_quit);
    register_method("defense_added", &GameVariables::defense_added);

    register_property<GameVariables, bool>("gameType", &GameVariables::gameType, "");
}

GameVariables::GameVariables() { }

GameVariables::~GameVariables() { }

void GameVariables::_init() { }

void GameVariables::_ready() { }

void GameVariables::defense_added(int defense_code, float x, float y) {
    std::vector<float> actual {float(defense_code), x, y};
    defenses_in_map.push_back(actual);
}

void GameVariables::_setType(bool type) {
    gameType = type;
} 

bool GameVariables::_getType() {
    Godot::print(String("Getting type"));
    return gameType;
}

void GameVariables::set_actual_defense(int defense) {
    Godot::print("Setting actual defense");
    actual_defense_to_put = defense;
}

int GameVariables::get_actual_defense() {
    return actual_defense_to_put;
}

void GameVariables::set_actual_defense_quit(int defense) {
    Godot::print("Setting actual defense");
    actual_defense_to_remove = defense;
}

int GameVariables::get_actual_defense_quit() {
    return actual_defense_to_remove;
}

