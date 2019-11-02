#include "Game.hpp"


using namespace godot;

void Game::_register_methods() {
    register_method("_init", &Game::_init);
    register_method("_ready", &Game::_ready);
    register_method("_process", &Game::_process);
    // register_method("_unhandled_input", &Game::_unhandled_input);

    register_property<Game, bool>("gameType", &Game::gameType, "");
}

Game::Game() { }

Game::~Game() { }

void Game::_init() { }

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
   
}

void Game::_process(float delta) { 
    Input *i = Input::get_singleton();
    if (i->is_action_just_pressed("mouse_clicked")) {
        Godot::print("Pressed");
        Vector2 vec = mage->get_global_position();
        float x = vec.x;
        float y = vec.y;
        Godot::print(std::to_string(x).c_str());
        Godot::print(std::to_string(y).c_str());
        // x 1125.410034
        // y 446.295990

        // f x 538.106995
        // f y 345.984009
        PoolVector2Array vector = navigation->get_simple_path(mage->get_global_position(), Vector2(538.106995, 345.984009));
        line->set_points(vector);
        
    }
}



 //test path generator

    // int matrixVector[10][10] = { { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
    //                             { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
    //                             { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    //                             { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    //                             { 0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
    //                             { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
    //                             { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
    //                             { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    //                             { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
    //                             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3} };
    // Array matrix = Array();
    
    // Array row0 = Array();
    // Array row1 = Array();
    // Array row2 = Array();
    // Array row3 = Array();
    // Array row4 = Array();
    // Array row5 = Array();
    // Array row6 = Array();
    // Array row7 = Array();
    // Array row8 = Array();
    // Array row9 = Array();
    // for (int i=0; i<10; i++) {
    //     for (int j=0; j< 10; j++) {
    //         // row.append(matrixVector[i][j]);
    //         switch (i) {
    //         case 0:
    //             row0.append(matrixVector[i][j]);
    //             break;
    //         case 1:
    //             row1.append(matrixVector[i][j]);
    //             break;
            
    //         case 2:
    //             row2.append(matrixVector[i][j]);
    //             break;
    //         case 3:
    //             /* code */
    //             row3.append(matrixVector[i][j]);
    //             break;
    //         case 4:
    //             row4.append(matrixVector[i][j]);
    //             break;
            
    //         case 5:
    //             row5.append(matrixVector[i][j]);
    //             break;
    //         case 6:
    //             row6.append(matrixVector[i][j]);
    //             /* code */
    //             break;
    //         case 7:
    //             row7.append(matrixVector[i][j]);
    //             break;
            
    //         case 8:
    //             row8.append(matrixVector[i][j]);
    //             break;
    //         case 9:
    //             row9.append(matrixVector[i][j]);
    //             break;
    //         default:
    //             break;
    //         }
    //         // row.push_back(matrixVector[i][j]);
    //         // row[j] = matrixVector[i][j];
    //     }
    // }

    // matrix.append(row0);
    // matrix.append(row1);
    // matrix.append(row2);
    // matrix.append(row3);
    // matrix.append(row4);
    // matrix.append(row5);
    // matrix.append(row6);
    // matrix.append(row7);
    // matrix.append(row8);
    // matrix.append(row9);

    // Array temp = matrix[0];
    // if (temp.size() > 0) {
    //     Godot::print(String("Temp Size > 0"));
    // } else  {
    //     Godot::print(String("Temp Size <= 0"));
    // }

    // Godot::print("Getting node");
    // get_node("/root/PathGenerator")->call("getRoute", row0, row1, row2, row3,row4, row5, row6, row7,row8, row9);
    // Godot::print("..done");