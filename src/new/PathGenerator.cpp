#include "PathGenerator.hpp"

using namespace godot;

PathGenerator::PathGenerator(std::vector<std::vector<int>> matrixN):
    matrix(matrixN){ }

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
        std::vector<std::vector<bool> > recorrido((*this).matrix.size(), std::vector<bool>((*this).matrix[0].size(),false));
        (*this).path.push_back(findEnter());
    // std::cout << "Entrada encontrada" << "\n";
    // std::cout << " Entrada: " << path[0][0] << path[0][1] <<"\n";
    recorrido[path[0][0]][path[0][1]] = true;
    // std::cout << " " << "\n";

    std::vector<int> ultimoPath;
    while(!(*this).path.empty() && (*this).matrix[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] != 3){
        // std::cout << "In while.." << "\n";
        // std::cout << (*this).laberinto[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] << "\n";
        ultimoPath.clear();
        ultimoPath.push_back((*this).path[(*this).path.size()-1][0]);
        ultimoPath.push_back((*this).path[(*this).path.size()-1][1]);

        // std::cout << "Utlimo path " <<laberinto[ultimoPath[0]][ultimoPath[1]-1] << "\n";
        
        //Elemento de abajo
        if ((*this).matrix[ultimoPath[0]+1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]+1][ultimoPath[1]]){
            // std::cout << "abajo " << "\n";
            ultimoPath[0] = ultimoPath[0]+1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la derecha
        else if ((*this).matrix[ultimoPath[0]][ultimoPath[1]+1] != 0 && !recorrido[ultimoPath[0]][ultimoPath[1]+1]){
            // std::cout << "derecha " << "\n";
            ultimoPath[1] = ultimoPath[1]+1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la izquierda de la ultima posicion de (*this).path
        else if(((*this).matrix[ultimoPath[0]][ultimoPath[1]-1] != 0) && (!recorrido[ultimoPath[0]][ultimoPath[1]-1])){
            // std::cout << "izquierda " << "\n";
            ultimoPath[1] = ultimoPath[1]-1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }
        
        //Elemento de arriba
        else if ((*this).matrix[ultimoPath[0]-1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]-1][ultimoPath[1]]){
            // std::cout << "arriba " << "\n";
            ultimoPath[0] = ultimoPath[0]-1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    
        }else
            (*this).path.pop_back();
    }

    // std::cout << "Laberinto " << "\n";

    if(!(*this).path.empty()){
        //Añadir el camino al laberinto
        for(unsigned int i=0; i < (*this).matrix.size(); i++)
            for(unsigned int j=0; j < (*this).matrix[i].size(); j++)
                addPathToMatrix(i,j);
    }

}

std::vector<std::vector<int>> PathGenerator::_get_Path() { 
    return matrix;
}

void PathGenerator::addPathToMatrix(int i, int j) { 
    for (unsigned int k=0; k < (*this).path.size(); k++)
        if((*this).path[k][0] == i && (*this).path[k][1] == j
           && (*this).matrix[i][j] != 2 && (*this).matrix[i][j] != 3)
            (*this).matrix[i][j] = 5;
}

std::vector<int> PathGenerator::findEnter() const { 
    bool encontrada = false;
    std::vector<int> pos;
    for(unsigned int i=0; i < (*this).matrix.size() && !encontrada; i++)
        for(unsigned int j=0; j < (*this).matrix[i].size() && !encontrada; j++)
            if((*this).matrix[i][j] == 2){
                pos.push_back(i);
                pos.push_back(j);
                encontrada = true;
            }
    return pos;
}

void PathGenerator::printLab() const{
    for(unsigned int i=0; i < (*this).matrix.size(); i++){
        for(unsigned int j=0; j < (*this).matrix[i].size(); j++)
            Godot::print(String((*this).matrix[i][j]));
            // cout << (*this).matrix[i][j];
        // cout << endl;
    }
}

void PathGenerator::printLabResuelto() const{
    if(!(*this).path.empty()){
        //Añadir el camino al laberinto
        Godot::print(String("Path find"));
        // cout << "LABERINTO RESUELTO: "<< endl;
        printLab();
    }
    else
        Godot::print(String("No hay camino"));
        // cout << "El laberinto no tiene salida" << endl;
}
