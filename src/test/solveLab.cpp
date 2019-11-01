
#include <iostream>

#include "solveLab.hpp"

using namespace std;

void Laberinto::cargarLaberinto(unsigned int FIL,unsigned int COL){
    (*this).laberinto.assign(FIL,vector<char>(COL));
        for(unsigned int i=0; i < FIL; i++)
            for(unsigned int j=0; j < COL; j++){
                char car;
                cin >> car;
                if (car != 'e' && car != 's')
                   (*this).laberinto[i][j] = (car == 'p' ? getShapeP() : getShapeL());
                else
                    (*this).laberinto[i][j] = car;
            }
}

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


void Laberinto::resolverLaberinto(){

    vector<vector<bool> > recorrido((*this).laberinto.size(), vector<bool>((*this).laberinto[0].size(),false));


    (*this).path.push_back(findEnter());
    recorrido[path[0][0]][path[0][1]] = true;

    vector<int> ultimoPath;
    while(!(*this).path.empty() &&
          (*this).laberinto[(*this).path[(*this).path.size()-1][0]][(*this).path[(*this).path.size()-1][1]] != 's'){
        ultimoPath.clear();
        ultimoPath.push_back((*this).path[(*this).path.size()-1][0]);
        ultimoPath.push_back((*this).path[(*this).path.size()-1][1]);

        //Elemento a la izquierda de la ultima posicion de (*this).path
        if(((*this).laberinto[ultimoPath[0]][ultimoPath[1]-1] != getShapeP())
           && (!recorrido[ultimoPath[0]][ultimoPath[1]-1])){
            ultimoPath[1] = ultimoPath[1]-1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }
        //Elemento a la derecha
        else if ((*this).laberinto[ultimoPath[0]][ultimoPath[1]+1] != getShapeP()
           && !recorrido[ultimoPath[0]][ultimoPath[1]+1]){
            ultimoPath[1] = ultimoPath[1]+1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }
        //Elemento de arriba
        else if ((*this).laberinto[ultimoPath[0]-1][ultimoPath[1]] != getShapeP()
           && !recorrido[ultimoPath[0]-1][ultimoPath[1]]){
            ultimoPath[0] = ultimoPath[0]-1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }//Elemento de abajo
        else if ((*this).laberinto[ultimoPath[0]+1][ultimoPath[1]] != getShapeP()
           && !recorrido[ultimoPath[0]+1][ultimoPath[1]]){
            ultimoPath[0] = ultimoPath[0]+1;
            (*this).path.push_back(ultimoPath);
            recorrido[ultimoPath[0]][ultimoPath[1]] = true;
        }else
            (*this).path.pop_back();
    }

    if(!(*this).path.empty()){
        //Añadir el camino al laberinto
        for(unsigned int i=0; i < (*this).laberinto.size(); i++)
            for(unsigned int j=0; j < (*this).laberinto[i].size(); j++)
                addPathToLab(i,j);
    }
}

vector<int> Laberinto::findEnter() const{
    //Buscamos la entrada
    bool encontrada = false;
    vector<int> pos;
    for(unsigned int i=0; i < (*this).laberinto.size() && !encontrada; i++)
        for(unsigned int j=0; j < (*this).laberinto[i].size() && !encontrada; j++)
            if((*this).laberinto[i][j] == 'e'){
                pos.push_back(i);
                pos.push_back(j);
                encontrada = true;
            }
    return pos;
}

void Laberinto::addPathToLab(unsigned int i, unsigned int j){
    for (unsigned int k=0; k < (*this).path.size(); k++)
        if((*this).path[k][0] == i && (*this).path[k][1] == j
           && (*this).laberinto[i][j] != 'e' && (*this).laberinto[i][j] != 's')
            (*this).laberinto[i][j] = getShapeC();
}

int main()
{
    unsigned int FIL, COL;
    cin >> FIL >> COL;

    Laberinto lab('+',' ','#',FIL,COL);
    lab.printLab();
    lab.resolverLaberinto();
    lab.printLabResuelto();
    return 0;
}