#include "GameVariables.hpp"

using namespace godot;

void GameVariables::_register_methods() {
    register_method("_init", &GameVariables::_init);
    register_method("_ready", &GameVariables::_ready);
    register_method("_setType", &GameVariables::_setType);
    register_method("_getType", &GameVariables::_getType);

    register_property<GameVariables, bool>("gameType", &GameVariables::gameType, "");
}

GameVariables::GameVariables() { }

GameVariables::~GameVariables() { }

void GameVariables::_init() { }

void GameVariables::_ready() { }

void GameVariables::_setType(bool type) {
    gameType = type;
} 

bool GameVariables::_getType() {
    Godot::print(String("Getting type"));
    return gameType;
}

