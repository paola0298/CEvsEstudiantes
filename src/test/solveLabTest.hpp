#include <vector>

class Laberinto {
    private:
        std::vector<std::vector<int> > path;
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

        void addPathToLab(unsigned int,unsigned int);
        std::vector<int> findEnter() const;
        void cargarLaberinto(int, int, int);

    public:
        Laberinto();
        void resolverLaberinto();
        void printLab() const;
        void printLabResuelto() const;
};