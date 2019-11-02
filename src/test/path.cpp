#include "path.hpp"

using namespace godot;


void PathGenerator::_register_methods() {
    register_method("_init", &PathGenerator::_init);
    register_method("_ready", &PathGenerator::_ready);
    register_method("_process", &PathGenerator::_process);
    register_method("get_path", &PathGenerator::get_path);
}

PathGenerator::PathGenerator() {

}

PathGenerator::~PathGenerator() {

}

void PathGenerator::_init() {

}

void PathGenerator::_ready() {

}

void PathGenerator::_process(float delta) {
    
}

// void PathGenerator::get_path(int (&matrix)[10][10]) {
void PathGenerator::get_path(std::vector<std::vector<int>>) {
    print_maze(matrix);
    generate_path(matrix);
    print_maze(matrix);
}


// void PathGenerator::generate_path(int (&matrix)[10][10]) {
void PathGenerator::generate_path(std::vector<std::vector<int>>) {
    bool route[10][10];
    int *entrance = find_enter(matrix);
    path[0][0] = entrance[0];
    path[0][1] = entrance[1];

    // mark entrance as walkable
    path_s++;
    route[path[0][0]][route[0][1]] = true;

    int last_path[2];

    matrix[0][1] = 2;
    while (path_s > 0 && matrix[path[path_s - 1][0]][path[path_s - 1][1]] != 3) {
        last_path[0] = path[path_s-1][0];
        last_path[1] = path[path_s-1][1];

        //Elemento de abajo
        if (matrix[last_path[0]+1][last_path[1]] != 0 && !route[last_path[0]+1][last_path[1]]) {
            last_path[0] = last_path[0]+1;
            path[path_s][0] = last_path[0];
            path[path_s][1] = last_path[1];
            path_s++;

            route[last_path[0]][last_path[1]] = true;
        }

        //Elemento a la derecha
        else if (matrix[last_path[0]][last_path[1]+1] != 0 && !route[last_path[0]][last_path[1]+1]) {
            last_path[1] = last_path[1]+1;
            path[path_s][0] = last_path[0];
            path[path_s][1] = last_path[1];
            path_s++;

            route[last_path[0]][last_path[1]] = true;
        }

        //Elemento a la izquierda
        else if ( matrix[last_path[0]][last_path[1]-1] != 0 && !route[last_path[0]][last_path[1]-1]) {
            last_path[1] = last_path[1]-1;
            path[path_s][0] = last_path[0];
            path[path_s][1] = last_path[1];
            path_s++;

            route[last_path[0]][last_path[1]] = true; 
        }

        //Elemento de arriba
        else if (matrix[last_path[0]-1][last_path[1]] != 0 && !route[last_path[0]-1][last_path[1]]) {
            last_path[0] = last_path[0]-1;
            path[path_s][0] = last_path[0];
            path[path_s][1] = last_path[1];
            path_s++;

            route[last_path[0]][last_path[1]] = true;
        } else {
            path_s--;
        }
    }

    if (path_s > 0) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                add_path(matrix, i, j);
            }
        }
    }

}

// int * PathGenerator::find_enter(int (&matrix)[10][10]) {
int * PathGenerator::find_enter(std::vector<std::vector<int>>) {
    bool found = false;
    int *point = (int *) malloc(sizeof(int)*2);
    
    for (int i=0; (i<10 && !found); i++) {
        for (int j=0; (j<10 && !found); j++) {
            if (matrix[i][j] == 2) {
                point[0] = i;
                point[1] = j;
                found = true;
            }
        }
    }
    return point;
}

// void PathGenerator::add_path(int i, int j, int (&matrix)[10][10]) {
void PathGenerator::add_path(std::vector<std::vector<int>> matrix, int i, int j) {
    for (int k = 0; k < path_s; k++) {
        if (path[k][0] == i && path[k][1] == j && matrix[i][j] != 2 && matrix[i][j] != 3){
            matrix[i][j] = 5;
        }
    }

}

// void PathGenerator::print_maze(int (&matrix)[10][10]) {
void PathGenerator::print_maze(std::vector<std::vector<int>> matrix) {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {

            Godot::print(matrix[i][j]);
        }
    }
}

void PathGenerator::print_maze_solution() {

}