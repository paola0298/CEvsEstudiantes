#include "PathGenerator.hpp"

using namespace godot;


PathGenerator::PathGenerator(){ }

PathGenerator::~PathGenerator() { }

void PathGenerator::_register_methods() {
    register_method("_init", &PathGenerator::_init);
    register_method("_ready", &PathGenerator::_ready);
    register_method("_process", &PathGenerator::_process);
    
    register_method("getRoute", &PathGenerator::getRoute);
    register_method("addPathToMatrix", &PathGenerator::addPathToMatrix);
    // register_method("findEnter", &PathGenerator::findEnter);
    register_method("setMatrix", &PathGenerator::setMatrix);
    register_method("_generate_path", &PathGenerator::_generate_path);
    register_method("printLab", &PathGenerator::printLab);
    register_method("printLabResuelto", &PathGenerator::printLabResuelto);
    register_method("vector_to_array", &PathGenerator::vector_to_array);
}


void PathGenerator::_init() { }

void PathGenerator::_ready() { }

void PathGenerator::_process(float delta) { }

Array PathGenerator::getRoute(Array row0,Array row1, Array row2,Array row3,Array row4,Array row5,Array row6,Array row7,Array row8,Array row9) {
    Godot::print("method getRoute");

    setMatrix(row0,row1, row2,row3,row4,row5,row6,row7,row8,row9);
    printLab();
    // _generate_path();
    // printLabResuelto();
    // return vector_to_array();
    return Array();
}

Array PathGenerator::vector_to_array() {
    Array matrixNew = Array();
    
    for (int i=0; i<matrix.size(); i++) {
        Array row = Array();
        matrixNew.append(row);
        for (int j=0; j< matrix[i].size(); j++) {
            row.append(matrix[i][j]);
        }
    }

    return matrixNew;
    
}
void PathGenerator::setMatrix(Array row0,Array row1, Array row2,Array row3,Array row4,Array row5,Array row6,Array row7,Array row8,Array row9) {
    Godot::print("method setMatrix()");
    
    Array actualRow;
    for (int i=0; i<10; i++) {
        switch (i) {
            case 0:
                actualRow = row0;
                break;
            case 1:
                actualRow = row1;
                break;
            case 2:
                actualRow = row2;
                break;
            case 3:
                actualRow = row3;
                break;
            case 4:
                actualRow = row4;
                break;
            case 5:
                actualRow = row5;
                break;
            case 6:
                actualRow = row6;
                break;
            case 7:
                actualRow = row7;
                break;
            case 8:
                actualRow = row8;
                break;
            case 9:
                actualRow = row9;
                break;
            default:
                break;
            }
        for (int j=0; j<actualRow.size(); j++) {
            matrix[i][j] = actualRow[j];
        }
    }

    // if (row1.size() > 0) {
    //     // Godot::print(String("Row Size > 0"));
    //     Godot::print(std::to_string((int)row0[0]).c_str());
    // } else  {
    //     Godot::print(String("Row Size <= 0"));
    // }

    // for (int i = 0; i < mat.size(); i++) {
    //     Array temp = mat[i];
    //     if (temp.size() > 0) {
    //        Godot::print(String("Temp Size > 0"));
    //     } else  {
    //         Godot::print(String("Temp Size <= 0"));
    //     }
    //     for (int j = 0; j < temp.size(); j++) {
    //         matrix[i][j] = temp[j];
    //         // matrix[i][j] = 1;
    //     }
    // }

    if (matrix.size() > 0) {
        Godot::print(String("Matriz Size > 0"));
    } else  {
        Godot::print(String("Matriz Size <= 0"));
    }

}
void PathGenerator::_generate_path() { 
    Godot::print("method _generate_path()");
    std::vector<std::vector<bool>> recorrido(matrix.size(), std::vector<bool>(matrix[0].size(),false));
    
    // bool recorrido[SIZE][SIZE];
    // path[0][0] = findEnter()[0];
    // path[0][1] = findEnter()[1];
    // pathS++; 
    path.push_back(findEnter());
    // std::cout << "Entrada encontrada" << "\n";
    // std::cout << " Entrada: " << path[0][0] << path[0][1] <<"\n";
    recorrido[path[0][0]][path[0][1]] = true;
    // std::cout << " " << "\n";

    std::vector<int> ultimoPath;
    // int ultimoPath[2];

    while(!path.empty() && matrix[path[path.size()-1][0]][path[path.size()-1][1]] != 3){
    // while(pathS > 0 && matrix[path[pathS-1][0]][path[pathS-1][1]] != 3){
        // std::cout << "In while.." << "\n";
        // std::cout << (*this).laberinto[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] << "\n";
    Godot::print("In while");
    //     ultimoPath.clear();
    //     ultimoPath.push_back(path[path.size()-1][0]);
    //     ultimoPath.push_back(path[path.size()-1][1]);

    //     // ultimoPath[0] = path[pathS-1][0];
    //     // ultimoPath[1] = path[pathS-1][1];
        
    //     // std::cout << "Utlimo path " <<laberinto[ultimoPath[0]][ultimoPath[1]-1] << "\n";
        
    //     //Elemento de abajo
    //     if (matrix[ultimoPath[0]+1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]+1][ultimoPath[1]]){
    //         // std::cout << "abajo " << "\n";
    //         ultimoPath[0] = ultimoPath[0]+1;
    //         path.push_back(ultimoPath);
    //         // path[pathS][0] = ultimoPath[0];
    //         // path[pathS][1] = ultimoPath[1];
    //         // pathS++;
    //         recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    //     }

    //     //Elemento a la derecha
    //     else if (matrix[ultimoPath[0]][ultimoPath[1]+1] != 0 && !recorrido[ultimoPath[0]][ultimoPath[1]+1]){
    //         // std::cout << "derecha " << "\n";
    //         ultimoPath[1] = ultimoPath[1]+1;
    //         path.push_back(ultimoPath);
    //         // path[pathS][0] = ultimoPath[0];
    //         // path[pathS][1] = ultimoPath[1];
    //         // pathS++;
    //         recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    //     }

    //     //Elemento a la izquierda de la ultima posicion de (*this).path
    //     else if((matrix[ultimoPath[0]][ultimoPath[1]-1] != 0) && (!recorrido[ultimoPath[0]][ultimoPath[1]-1])){
    //         // std::cout << "izquierda " << "\n";
    //         ultimoPath[1] = ultimoPath[1]-1;
    //         path.push_back(ultimoPath);
    //         // path[pathS][0] = ultimoPath[0];
    //         // path[pathS][1] = ultimoPath[1];
    //         // pathS++;
    //         recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    //     }
        
    //     //Elemento de arriba
    //     else if ((*this).matrix[ultimoPath[0]-1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]-1][ultimoPath[1]]){
    //         // std::cout << "arriba " << "\n";
    //         ultimoPath[0] = ultimoPath[0]-1;
    //         path.push_back(ultimoPath);
    //         // path[pathS][0] = ultimoPath[0];
    //         // path[pathS][1] = ultimoPath[1];
    //         // pathS++;
    //         recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    
    //     }else
    //         // pathS--;
    //         path.pop_back();
    // }

    // // std::cout << "Laberinto " << "\n";

    // // if(pathS > 0){
    // if(!path.empty()){
    //     //Añadir el camino al laberinto
    //     for(int i=0; i < matrix.size(); i++)
    //         for(int j=0; j < matrix[i].size(); j++)
    //             addPathToMatrix(i,j);
    }
}

void PathGenerator::addPathToMatrix(int i, int j) { 
    for (int k=0; k < path.size(); k++) {
        if(path[k][0] == i && path[k][1] == j && matrix[i][j] != 2 && matrix[i][j] != 3)
            matrix[i][j] = 5;
    }
}

std::vector<int> PathGenerator::findEnter() { 
    bool encontrada = false;
    std::vector<int> pos;
    for(int i=0; i < matrix.size() && !encontrada; i++)
        for(int j=0; j < matrix.size() && !encontrada; j++)
            if(matrix[i][j] == 2){
                pos.push_back(i);
                pos.push_back(j);
                // pos[0] = i;
                // pos[1] = j;
                encontrada = true;
            }
    return pos;
    // return std::vector<int>();

}

void PathGenerator::printLab(){
    Godot::print(String("Printing"));
    String row = "";
    Godot::print(String(matrix.size()));
    if (matrix.size() > 0) {
        Godot::print(String("Size > 0"));
    } else  {
        Godot::print(String("Size <= 0"));
    }
    for(int i=0; i < matrix.size(); i++){
        Godot::print("row");
        for(unsigned int j=0; j < matrix[i].size(); j++){
            
            row.insert(row.length(), String(matrix[i][j]));
            row.insert(row.length()," ");
            // cout << (*this).matrix[i][j];
        // cout << endl;
        }
        Godot::print(row);
    }
    Godot::print(String("Printed"));
}

void PathGenerator::printLabResuelto(){
    if(!path.empty()){
        //Añadir el camino al laberinto
        Godot::print(String("Path find"));
        // cout << "LABERINTO RESUELTO: "<< endl;
        printLab();
    }
    else
        Godot::print(String("No hay camino"));
        // cout << "El laberinto no tiene salida" << endl;
}
