#include <iostream>
#include "solveLabTest.hpp"

using namespace std;


void Laberinto::printLab() const{
    for(unsigned int i=0; i < (*this).laberinto.size(); i++){
        for(unsigned int j=0; j < (*this).laberinto[i].size(); j++)
            cout << (*this).laberinto[i][j];
        cout << endl;
    }
}

void Laberinto::printLabResuelto() const{
    if(!(*this).path.empty()){
        //Añadir el camino al laberinto
        cout << "LABERINTO RESUELTO: "<< endl;
        printLab();
    }
    else
        cout << "El laberinto no tiene salida" << endl;
}


vector<int> Laberinto::findEnter() const{
    bool encontrada = false;
    vector<int> pos;
    for(unsigned int i=0; i < (*this).laberinto.size() && !encontrada; i++)
        for(unsigned int j=0; j < (*this).laberinto[i].size() && !encontrada; j++)
            if((*this).laberinto[i][j] == 2){
                pos.push_back(i);
                pos.push_back(j);
                encontrada = true;
            }
    return pos;
}

void Laberinto::addPathToLab(unsigned int i, unsigned int j){
    for (unsigned int k=0; k < (*this).path.size(); k++)
        if((*this).path[k][0] == i && (*this).path[k][1] == j
           && (*this).laberinto[i][j] != 2 && (*this).laberinto[i][j] != 3)
            (*this).laberinto[i][j] = 5;
}

void Laberinto::resolverLaberinto() {
    // std::cout << "Iniciando metodo.." << "\n";
    vector<vector<bool> > recorrido((*this).laberinto.size(), vector<bool>((*this).laberinto[0].size(),false));

    (*this).path.push_back(findEnter());
    // std::cout << "Entrada encontrada" << "\n";
    // std::cout << " Entrada: " << path[0][0] << path[0][1] <<"\n";
    recorrido[path[0][0]][path[0][1]] = true;
    // std::cout << " " << "\n";

    vector<int> ultimoPath;
    while(!(*this).path.empty() && (*this).laberinto[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] != 3){
        std::cout << "In while.." << "\n";
        // std::cout << (*this).laberinto[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] << "\n";
        ultimoPath.clear();
        ultimoPath.push_back((*this).path[(*this).path.size()-1][0]);
        ultimoPath.push_back((*this).path[(*this).path.size()-1][1]);

        // std::cout << "Utlimo path " <<laberinto[ultimoPath[0]][ultimoPath[1]-1] << "\n";
        
        //Elemento de abajo
        if ((*this).laberinto[ultimoPath[0]+1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]+1][ultimoPath[1]]){
            // std::cout << "abajo " << "\n";
            ultimoPath[0] = ultimoPath[0]+1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la derecha
        else if ((*this).laberinto[ultimoPath[0]][ultimoPath[1]+1] != 0 && !recorrido[ultimoPath[0]][ultimoPath[1]+1]){
            // std::cout << "derecha " << "\n";
            ultimoPath[1] = ultimoPath[1]+1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la izquierda de la ultima posicion de (*this).path
        else if(((*this).laberinto[ultimoPath[0]][ultimoPath[1]-1] != 0) && (!recorrido[ultimoPath[0]][ultimoPath[1]-1])){
            // std::cout << "izquierda " << "\n";
            ultimoPath[1] = ultimoPath[1]-1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }
        
        //Elemento de arriba
        else if ((*this).laberinto[ultimoPath[0]-1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]-1][ultimoPath[1]]){
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
        for(unsigned int i=0; i < (*this).laberinto.size(); i++)
            for(unsigned int j=0; j < (*this).laberinto[i].size(); j++)
                addPathToLab(i,j);
    }

}

Laberinto::Laberinto() {}

int main()
{
    // Laberinto *lab = new Laberinto();
    // lab->printLab();
    // // std::cout << "Lab printed\n";
    // lab->resolverLaberinto();
    // // std::cout << "Lab resolved\n";
    // lab->printLabResuelto();
    std::vector<std::vector<int> > path;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    std::cout << vec[1] << "\n";

    std::cout << vec.size() << "\n";
    vec.pop_back();
    vec.size();
    std::cout << vec.size() << "\n";
    std::cout << path.size() << "\n";
    path.push_back(vec);
    std::cout << path.size() << "\n";
    return 0;
}