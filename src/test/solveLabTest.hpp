#include <vector>

class Laberinto {
    private:
        std::vector<std::vector<int> > path;
        // int path[10][10];
        std::vector<std::vector<int> > laberinto{ { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
                                                  { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
                                                  { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                                                  { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                                  { 0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
                                                  { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
                                                  { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                                                  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                                  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
                                                  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3} };

        // int laberinto[10][10] = { { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
        //                           { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
        //                           { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        //                           { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        //                           { 0, 1, 1, 0, 0, 1, 1, 0, 1, 0},
        //                           { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        //                           { 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
        //                           { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        //                           { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, 
        //                           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 3} };

        void addPathToLab(unsigned int,unsigned int);
        std::vector<int> findEnter() const;

    public:
        Laberinto();
        void resolverLaberinto();
        void printLab() const;
        void printLabResuelto() const;
};