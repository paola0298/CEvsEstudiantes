#include "Game.hpp"


using namespace godot;

void Game::_register_methods() {
    register_method("_init", &Game::_init);
    register_method("_ready", &Game::_ready);
    register_method("_process", &Game::_process);
    // register_method("_unhandled_input", &Game::_unhandled_input);
    register_method("_input", &Game::HandleInputEvent);
    register_method("on_defense_pressed", &Game::HandleInputEvent);

    register_property<Game, bool>("gameType", &Game::gameType, "");
}

Game::Game() { }

Game::~Game() { }

void Game::_init() { }

void Game::on_defense_pressed() {
    get_node("/root/GameVariables")->call("set_actual_defense_quit");

}

void Game::HandleInputEvent(InputEvent* event) {
    const godot::String gsIEMB = "InputEventMouseButton";
    godot::String gsClass = event->get_class();
    if (gsClass == gsIEMB) {
        ProcessClick((InputEventMouseButton*)event);
    }

}

void Game::ProcessClick(InputEventMouseButton* e) {
    int64_t buttonIndex = e->get_button_index();
    if (e->is_pressed()) {
        if (buttonIndex == GlobalConstants::BUTTON_RIGHT) {
            Godot::print("Button left pressed");
            Vector2 vector = e->get_global_position();
            Godot::print("Click at");
            Godot::print(std::to_string(vector.x).c_str());
            Godot::print(std::to_string(vector.y).c_str());
            // vector = vector + Vector2(600, 0);
            // vector = c_to_i(vector);
            // Vector2 position = e->get_position();
            // Godot::print(std::to_string(vector.x).c_str());
            // Godot::print(std::to_string(vector.y).c_str());
            int defense = get_node("/root/GameVariables")->call("get_actual_defense");
            Godot::print(std::to_string(defense).c_str());

            Ref<PackedScene> defenser;

            switch (defense) {
            case 1: //Archer
                defenser = ResourceLoader::get_singleton()->load("res://scenes/defenses/Archer.tscn");
                break;
            case 2: //Mage
                defenser = ResourceLoader::get_singleton()->load("res://scenes/defenses/Mage.tscn");
                break;
            case 3: // Gunner
                defenser = ResourceLoader::get_singleton()->load("res://scenes/defenses/Gunner.tscn");
                break;
            case 4: // Fire
                defenser = ResourceLoader::get_singleton()->load("res://scenes/defenses/FireMage.tscn");
                break;
            }

            Godot::print("Defenser set");

            KinematicBody2D *defenseBody = (KinematicBody2D*)defenser->instance();
            // defenseBody->set_position(position);
            defenseBody->set_global_position(vector);
            defenseBody->set_z_index(5);
            add_child(defenseBody);

        }

        // if (buttonIndex == GlobalConstants::BUTTON_LEFT) {
        //     Godot::print("Left pressed");
        
        // }
    }

}

Vector2 Game::c_to_i(Vector2 cartesian) {
    return Vector2(cartesian.x-cartesian.y, (cartesian.x+cartesian.y)/2);
}
Vector2 Game::i_to_c(Vector2 isometric) {
    Vector2 pos = Vector2();
    pos.x = (isometric.x+isometric.y*2)/2;
    pos.y = -isometric.x + pos.x;

    return pos;
}

// void Game::_unhandled_input(InputEvent *event) {
//     // if (event->is_action_pressed("mouse_clicked")) {

//     // }
//     Godot::print("Pressed");
//     // if (event->is_action_pressed("mouse_clicked")) {
//     //     event->get_global_position();
//     // }
// }

void Game::_ready() { 
    gameType = get_node("/root/GameVariables")->call("_getType");
    if (gameType) 
        Godot::print(String("Individual game"));
    else 
        Godot::print(String("Collective game"));

    navigation = (Navigation2D*)get_node("Navigation2D");
    line = (Line2D*)get_node("Line2D");
    mage = (KinematicBody2D*)get_node("Mage");
   
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
