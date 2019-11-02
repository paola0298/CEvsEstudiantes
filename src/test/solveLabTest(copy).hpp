#include <vector>
#include <random>
#include <iostream>

class Laberinto {
    private:
        // std::vector<std::vector<int> > path;
        int path[100][100];
        // std::vector<std::vector<int> > laberinto{ { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
                                                //   { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
                                                //   { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                                                //   { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                                //   { 0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
                                                //   { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                                                //   { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                                                //   { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                                //   { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
                                                //   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3} };

        // int laberinto[10][10] = { { 0, 2, 1, 1, 1, 1, 1, 0, 0, 0}, 
        //                           { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
        //                           { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        //                           { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        //                           { 0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
        //                           { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        //                           { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
        //                           { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        //                           { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
        //                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3} };

        int *laberinto[10];


        void addPathToLab(int, int);
        int* findEnter();
        int pathS = 0;

    public:
        Laberinto();
        void resolverLaberinto();
        void printLab();
        void printLabResuelto();
};