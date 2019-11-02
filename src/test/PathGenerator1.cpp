#include "PathGenerator.hpp"

using namespace godot;
#define SIZE 10

PathGenerator::PathGenerator(){ }

PathGenerator::~PathGenerator() { }

void PathGenerator::_register_methods() {
    register_method("_init", &PathGenerator::_init);
    register_method("_generate_path", &PathGenerator::_generate_path);
    register_method("_get_Path", &PathGenerator::_get_Path);
    register_method("addPathToMatrix", &PathGenerator::addPathToMatrix);
    register_method("findEnter", &PathGenerator::findEnter);
}


void PathGenerator::_init() { }

void PathGenerator::_generate_path() { 
        // std::vector<std::vector<bool> > recorrido((*this).matrix.size(), std::vector<bool>((*this).matrix[0].size(),false));
    
    bool recorrido[SIZE][SIZE];
    path[0][0] = findEnter()[0];
    path[0][1] = findEnter()[1];
    pathS++; 
    // (*this).path.push_back(findEnter());
    // std::cout << "Entrada encontrada" << "\n";
    // std::cout << " Entrada: " << path[0][0] << path[0][1] <<"\n";
    recorrido[path[0][0]][path[0][1]] = true;
    // std::cout << " " << "\n";

    // std::vector<int> ultimoPath;
    int ultimoPath[2];
    while(pathS > 0 && matrix[path[pathS-1][0]][path[pathS-1][1]] != 3){
        // std::cout << "In while.." << "\n";
        // std::cout << (*this).laberinto[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] << "\n";
        // ultimoPath.clear();
        // ultimoPath.push_back((*this).path[(*this).path.size()-1][0]);
        // ultimoPath.push_back((*this).path[(*this).path.size()-1][1]);

        ultimoPath[0] = path[pathS-1][0];
        ultimoPath[1] = path[pathS-1][1];
        
        // std::cout << "Utlimo path " <<laberinto[ultimoPath[0]][ultimoPath[1]-1] << "\n";
        
        //Elemento de abajo
        if ((*this).matrix[ultimoPath[0]+1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]+1][ultimoPath[1]]){
            // std::cout << "abajo " << "\n";
            ultimoPath[0] = ultimoPath[0]+1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la derecha
        else if ((*this).matrix[ultimoPath[0]][ultimoPath[1]+1] != 0 && !recorrido[ultimoPath[0]][ultimoPath[1]+1]){
            // std::cout << "derecha " << "\n";
            ultimoPath[1] = ultimoPath[1]+1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la izquierda de la ultima posicion de (*this).path
        else if(((*this).matrix[ultimoPath[0]][ultimoPath[1]-1] != 0) && (!recorrido[ultimoPath[0]][ultimoPath[1]-1])){
            // std::cout << "izquierda " << "\n";
            ultimoPath[1] = ultimoPath[1]-1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }
        
        //Elemento de arriba
        else if ((*this).matrix[ultimoPath[0]-1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]-1][ultimoPath[1]]){
            // std::cout << "arriba " << "\n";
            ultimoPath[0] = ultimoPath[0]-1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    
        }else
            pathS--;
            // (*this).path.pop_back();
    }

    // std::cout << "Laberinto " << "\n";

    if(pathS > 0){
        //Añadir el camino al laberinto
        for(unsigned int i=0; i < SIZE; i++)
            for(unsigned int j=0; j < SIZE; j++)
                addPathToMatrix(i,j);
    }

}

int* PathGenerator::_get_Path() { 
    return matrix[SIZE];
}

void PathGenerator::addPathToMatrix(int i, int j) { 
    for (int k=0; k < pathS; k++) {
        if(path[k][0] == i && path[k][1] == j && matrix[i][j] != 2 && matrix[i][j] != 3)
            matrix[i][j] = 5;
    }
}

int* PathGenerator::findEnter() { 
    bool encontrada = false;
    int *pos;
    for(int i=0; i < SIZE && !encontrada; i++)
        for(int j=0; j < SIZE && !encontrada; j++)
            if(matrix[i][j] == 2){
                // pos.push_back(i);
                // pos.push_back(j);
                pos[0] = i;
                pos[1] = j;
                encontrada = true;
            }
    return pos;
}

void PathGenerator::printLab(){
    for(unsigned int i=0; i < SIZE; i++){
        for(unsigned int j=0; j < SIZE; j++)
            Godot::print(String((*this).matrix[i][j]));
            // cout << (*this).matrix[i][j];
        // cout << endl;
    }
}

void PathGenerator::printLabResuelto(){
    if(pathS > 0){
        //Añadir el camino al laberinto
        Godot::print(String("Path find"));
        // cout << "LABERINTO RESUELTO: "<< endl;
        printLab();
    }
    else
        Godot::print(String("No hay camino"));
        // cout << "El laberinto no tiene salida" << endl;
}
