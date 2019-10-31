#include "genetic.hpp"

using namespace godot;

StudentGenetics::StudentGenetics() {

}

StudentGenetics::~StudentGenetics() {

}

void StudentGenetics::_init() {

}

void StudentGenetics::_ready() {

}

void StudentGenetics::_register_methods() {
    register_method("_process", &StudentGenetics::_process);
    register_method("generate_population", &StudentGenetics::generate_population);
    register_method("calculate_fitness", &StudentGenetics::calculate_fitness);
    register_method("select_from_population", &StudentGenetics::select_from_population);
    register_method("crossover", &StudentGenetics::crossover);
    register_method("mutate_and_invert", &StudentGenetics::mutate_and_invert);
    register_method("random_int", &StudentGenetics::random_int);

}

void StudentGenetics::_process(float delta) {

}

void StudentGenetics::generate_population(int size) {
    for (int i=0; i<population_size; i++) {
        // Student *a = new Student();
    }
}

void StudentGenetics::calculate_fitness() {

}

void StudentGenetics::select_from_population() {

}

void StudentGenetics::crossover(Student *i1, Student *i2) {

}

void StudentGenetics::mutate_and_invert(Student *i) {

}

int StudentGenetics::random_int(int min, int max) {
    std::srand(std::time(0));
    return min + (std::rand() % (max - min +1));
}