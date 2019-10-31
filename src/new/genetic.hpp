#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>
#include <vector>
#include <random>
#include <ctime>
#include "Student.hpp"

namespace godot {
    class StudentGenetics {
        public:
            StudentGenetics();
            ~StudentGenetics();

            // Godot functions            
            void _init();
            void _ready();
            void _register_methods();
            void _process(float delta);

            //Algorithm functions
            void generate_population(int size);
            void calculate_fitness();
            void select_from_population();
            void crossover(Student *i1, Student *i2);
            void mutate_and_invert(Student *i);
        private:
            int population_size;
            int prom;
            int selected;
            std::vector<Student *> population;
            //Random generator
            int random_int(int min, int max);
    };
}
