#pragma once

#include <core/Godot.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <ResourceLoader.hpp>
#include <Array.hpp>
#include <Variant.hpp>

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "Student.hpp"

namespace godot {
    class StudentGenetics: public Node {
        GODOT_CLASS(StudentGenetics, Node);

        public:
            StudentGenetics();
            ~StudentGenetics();

            // Godot functions
            void _init();
            void _ready();
            void _process(float delta);
            static void _register_methods();

            //Genetic functions
            void generate_population();
            void calculate_fitness();
            void select_from_population();
            void crossover();

            Student *generate_student();
            void print_students();
            int get_generations();

            int get_student_type_at(int index);

        private:
            int population_size = 10;
            int generations = 0;
            int idle_generations = 0;
            int max_idle_generations = 10;

            float probabilities[10] = {0.0};

            std::vector<Student *> population;
            std::vector<Student *> selected_population;
            //Random generator
            int random_int(int min, int max);
            float random_float();

            void mutate_and_invert(Student *i);

            void print_student(Student *s);
            float get_total_fitness();
            void calculate_fitness_of(Student *s);
            bool replace(Student *new_child);
            int find_least_fittest();
            bool inc_dec_prob();

    };
}
