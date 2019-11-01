#include <iostream>
#include "solveLabTest(copy).hpp"

#define SIZE 10

using namespace std;


void Laberinto::printLab(){
    std::cout <<"Valor " << laberinto[0][0] << "\n";
    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){

            // std::cout <<"Valor [i][j]" << i << j <<  "\n\n";
            std::cout << laberinto[i][j];
        }
        std::cout << endl;
    }
}

void Laberinto::printLabResuelto(){
    std::cout << "Printing\n";
    if(pathS > 0){
         //Añadir el camino al laberinto
        std::cout << "LABERINTO RESUELTO: "<< endl;
        printLab();
     }
     else
         std::cout << "El laberinto no tiene salida" << endl;
}


int* Laberinto::findEnter() {
    bool encontrada = false;
    int *pos;
    for(int i=0; i < SIZE && !encontrada; i++){
        for(int j=0; j < SIZE && !encontrada; j++){
            if(laberinto[i][j] == 2){
                pos[0] = i;
                pos[1] = j;
                encontrada = true;
            }
        }
    }
    return pos;
}

void Laberinto::addPathToLab(int i, int j){
    std::cout << "i " << i << ", j " << j << "\n";
    std::cout <<"Valor " << laberinto[i][j] << "\n";
    for (int k=0; k < pathS; k++){
        if(path[k][0] == i && path[k][1] == j && laberinto[i][j] != 2 && laberinto[i][j] != 3)
            laberinto[i][j] = 5;
    }

}

void Laberinto::resolverLaberinto() {
    std::cout << "Iniciando metodo.." << "\n";
    // vector<vector<bool> > recorrido((*this).laberinto.size(), vector<bool>((*this).laberinto[0].size(),false));

    bool recorrido[10][10];
    path[0][0] = findEnter()[0];
    path[0][1] = findEnter()[1];
    pathS++; 
    // (*this).path.push_back(findEnter());
    std::cout << "Entrada encontrada" << "\n";
    std::cout << " Entrada: " << path[0][0] << path[0][1] <<"\n";
    recorrido[path[0][0]][path[0][1]] = true;
    // std::cout << " " << "\n";

    // vector<int> ultimoPath;
    int ultimoPath[2];
    // while(pathS > 0 && laberinto[path[pathS-1][0]][path[pathS-1][1]] != 3){
    while (pathS > 0) {
        // std::cout << "In while.." << "\n";
        int punto = laberinto[path[pathS-1][0]][path[pathS-1][1]];
        std::cout << "En matriz "<< punto << "\n";
        if (punto == 3) {
            cout << "Breaking\n";
            break;
        }
        // ultimoPath.clear();
        // ultimoPath[0] = 0;
        // ultimoPath[1] = 0;
        ultimoPath[0] = path[pathS-1][0];
        ultimoPath[1] = path[pathS-1][1];
        // ultimoPath.push_back((*this).path[(*this).path.size()-1][0]);
        // ultimoPath.push_back((*this).path[(*this).path.size()-1][1]);

        // std::cout << "Utlimo path " <<laberinto[ultimoPath[0]][ultimoPath[1]-1] << "\n";
        
        //Elemento de abajo
        if (laberinto[ultimoPath[0]+1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]+1][ultimoPath[1]]){
            std::cout << "abajo " << "\n";
            ultimoPath[0] = ultimoPath[0]+1;
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            // path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la derecha
        else if ((*this).laberinto[ultimoPath[0]][ultimoPath[1]+1] != 0 && !recorrido[ultimoPath[0]][ultimoPath[1]+1]){
            std::cout << "derecha " << "\n";
            ultimoPath[1] = ultimoPath[1]+1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }

        //Elemento a la izquierda de la ultima posicion de (*this).path
        else if(((*this).laberinto[ultimoPath[0]][ultimoPath[1]-1] != 0) && (!recorrido[ultimoPath[0]][ultimoPath[1]-1])){
            std::cout << "izquierda " << "\n";
            ultimoPath[1] = ultimoPath[1]-1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }
        
        //Elemento de arriba
        else if ((*this).laberinto[ultimoPath[0]-1][ultimoPath[1]] != 0 && !recorrido[ultimoPath[0]-1][ultimoPath[1]]){
            std::cout << "arriba " << "\n";
            ultimoPath[0] = ultimoPath[0]-1;
            // (*this).path.push_back(ultimoPath);
            path[pathS][0] = ultimoPath[0];
            path[pathS][1] = ultimoPath[1];
            pathS++;
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
    
        }else
            // (*this).path.pop_back();
            pathS--;
    }

    // std::cout << "Laberinto " << "\n";

    if(pathS > 0){
        //Añadir el camino al laberinto
        for(int i=0; i < SIZE; i++)
            for(int j=0; j < SIZE; j++)
                addPathToLab(i,j);
    }

    std::cout << "Path created\n";
    // std::cout << laberinto[2][5] << "\n";
    printLab();

}

Laberinto::Laberinto() {}

int main()
{
    Laberinto *lab = new Laberinto();
    lab->printLab();
    std::cout << "Lab printed\n";
    lab->resolverLaberinto();
    std::cout << "Lab resolved\n";
    lab->printLabResuelto();
    return 0;
}