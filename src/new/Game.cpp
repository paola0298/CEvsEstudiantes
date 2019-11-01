#include "Game.hpp"

using namespace godot;

void Game::_register_methods() {
    register_method("_init", &Game::_init);
    register_method("_ready", &Game::_ready);
    register_method("_process", &Game::_process);

    register_property<Game, bool>("gameType", &Game::gameType, "");
}

Game::Game() { }

Game::~Game() { }

void Game::_init() { }

void Game::_ready() { 
    gameType = get_node("/root/GameVariables")->call("_getType");
    if (gameType) 
        Godot::print(String("Individual game"));
    else 
        Godot::print(String("Collective game"));

    //test path generator

    std::vector<std::vector<int> > matrix{{ 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
                                          { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
                                          { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                                          { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                          { 0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
                                          { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                                          { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                                          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
                                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3} };
    PathGenerator path(matrix);
    path.printLab();
    Godot::print("Matrix printed");
    path._generate_path();
    // path.printLabResuelto();
}

void Game::_process(float delta) { }
