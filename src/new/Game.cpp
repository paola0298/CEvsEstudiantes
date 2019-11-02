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

    //Load scenes to memory
    enemy_ogre = ResourceLoader::get_singleton()->load("res://scenes/characters/Ogre.tscn");
    enemy_mercenary = ResourceLoader::get_singleton()->load("res://scenes/characters/Mercenary.tscn");
    enemy_harpy = ResourceLoader::get_singleton()->load("res://scenes/characters/Harpy.tscn");
    enemy_dark_elf = ResourceLoader::get_singleton()->load("res://scenes/characters/Elf.tscn");
}

void Game::_process(float delta) {
    time_var += delta;
    if (time_var >= 4) {
        std::string str = "Wave counter: " + std::to_string(wave_enemies);
        Godot::print(str.c_str());
        time_var = 0;

        if (wave_enemies < 10) {
            int type = get_node("/root/StudentGenetics")->call("get_student_type_at", wave_enemies);
            KinematicBody2D *enemy_node;
            switch (type) {
                case 0:
                    enemy_node = (KinematicBody2D *) enemy_ogre->instance();
                    break;
                case 1:
                    enemy_node = (KinematicBody2D *) enemy_mercenary->instance();
                    break;
                case 2:
                    enemy_node = (KinematicBody2D *) enemy_harpy->instance();
                    break;
                case 3:
                    enemy_node = (KinematicBody2D *) enemy_dark_elf->instance();
                    break;
                default:
                    enemy_node = (KinematicBody2D *) enemy_ogre->instance();
                    break;
            }
            enemy_node->set_z_index(5);
            enemy_node->set_global_position(Vector2(1026, 606));
            add_child(enemy_node);
            enemies_nodes.push_back(enemy_node);
            // enemies_classes.push_back(enemy);
            wave_enemies++;
        } else {
            wave_enemies = 0;
            for (int i=0; i<10; i++) {
                KinematicBody2D *tmp = enemies_nodes[i];
                remove_child(tmp);
                // tmp->free();
                // godot_free(tmp);
                // enemies_classes.clear();
            }
            enemies_nodes.clear();
            get_node("/root/StudentGenetics")->call("select_from_population");
            get_node("/root/StudentGenetics")->call("crossover");
            
        }
    }
}
