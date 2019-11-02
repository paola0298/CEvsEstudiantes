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
    register_method("_init", &StudentGenetics::_init);
    register_method("_ready", &StudentGenetics::_ready);
    register_method("_process", &StudentGenetics::_process);
    // register_method("generate_student", &StudentGenetics::generate_student);
    register_method("generate_population", &StudentGenetics::generate_population);
    register_method("calculate_fitness", &StudentGenetics::calculate_fitness);
    register_method("select_from_population", &StudentGenetics::select_from_population);
    // register_method("crossover", &StudentGenetics::crossover);
    // register_method("mutate_and_invert", &StudentGenetics::mutate_and_invert);
    // register_method("random_int", &StudentGenetics::random_int);
    register_method("print_students", &StudentGenetics::print_students);
    register_method("print_student", &StudentGenetics::print_student);
    register_method("get_student_type_at", &StudentGenetics::get_student_type_at);
}

int StudentGenetics::get_student_type_at(int index) {
    if (index < population.size()) {
        return population[index]->getType();
    } else {
        return -1;
    }
}

void StudentGenetics::_process(float delta) {

}

Student *StudentGenetics::generate_student() {
    int type = random_int(0, 3);
    Student *s = nullptr;
    switch (type) {
    case 0: //ogro
        s = new Student(80, 0.3, 0.2, 1.1, 1.2, 1.3, 0);
        break;
    case 1: //mercenario
        s = new Student(40, 1.5, 0.2, 0.3, 0.4, 1.2, 1);
        break;
    case 2: // arpía
        s = new Student(50, 1.0, 0.0, 0.0, 1.0, 1.0, 2);
        break;
    case 3: // elfo oscuro
        s = new Student(50, 1.0, 0.2, 0.3, 1.2, 1.3, 3);
        break;
    }
    return s;
}

void StudentGenetics::generate_population() {
    Godot::print("Generating population..");
    //Randomize population type
    std::srand(std::time(0));
    for (int i=0; i<population_size; i++) {
        Student *s = generate_student();
        population.push_back(s);
    }
    Godot::print("..done");
}

void StudentGenetics::print_students() {
    Godot::print("Students");
    for (Student *s: population) {
        print_student(s);
    }
}

void StudentGenetics::print_student(Student *s) {
    std::string info = "{";
    info += "type: " + std::to_string(s->getType());
    info += ", life: " + std::to_string(s->getLife());
    info += ", speed: " + std::to_string(s->getSpeed());
    info += ", archer_r: " + std::to_string(s->getArcherResistance());
    info += ", mage_r: " + std::to_string(s->getResistanceToWizards());
    info += ", gunner_r: " + std::to_string(s->getGunnerResistance());
    info += ", firemage_r: " + std::to_string(s->getFireThrowingResistance());
    info += "}\n";
    String str(info.c_str());
    Godot::print(str);
}

void StudentGenetics::calculate_fitness() {
    Godot::print("Calculating population fitness..");
    for (Student *s : population) {
        float base_life = s->get_base_life();
        float speed = s->getSpeed();
        float endurance = 
        s->getArcherResistance() + 
        s->getResistanceToWizards() + 
        s->getGunnerResistance() +  
        s->getFireThrowingResistance();
        s->set_fitness_score((base_life+speed*150)/endurance);
    }
    Godot::print("..done");
}

void StudentGenetics::select_from_population() {
    float total_fitness = get_total_fitness();

    for (int c=0; c<population_size; c++) {
        float prev_probability = 0.0;
        //Calculate probabilities
        for (int i=0; i<population_size; i++) {
            Student *current = population[i];
            probabilities[i] = prev_probability + (current->get_fitness_score()/total_fitness);
            prev_probability = probabilities[i];
        }
        //Display probabilities
        for (float f: probabilities) {
            Godot::print(std::to_string(f).c_str());
        }
        //Select random number between 0 and 1
        float random = random_float();
        Student *selected = nullptr;
        std::string s = "Float selected: " + std::to_string(random);
        Godot::print(s.c_str());
        //Choose student based on selected number
        for (int i=0; i<population_size; i++) {
            if (random < probabilities[i]) {
                selected = population[i];
                break;
            }
        }
        selected_population.push_back(selected);
    }
    std::string s = "Selected students: " + std::to_string(selected_population.size());
    Godot::print(s.c_str());
}

void StudentGenetics::crossover() {
    // int index = (population_size % 2) == 0 ? population_size : population_size -1;
    bool population_replaced = false;

    for (int i=0; i<population_size; i+=2) {
        Student *s1 = selected_population[i];
        float *chromosomes1 = s1->get_chromosome();
        Student *s2 = selected_population[i+1];
        float *chromosomes2 = s2->get_chromosome();

        int crossover_point = random_int(0, 5);

        float chromosomes3[6];
        float chromosomes4[6];

        for (int i=0; i<crossover_point; i++) {
            chromosomes3[i] = chromosomes1[i];
            chromosomes4[i] = chromosomes2[i];
        }
        for (int i=crossover_point; i<6; i++) {
            chromosomes3[i] = chromosomes2[i];
            chromosomes4[i] = chromosomes1[i];
        }
        Student *c1 = new Student(chromosomes3[0], chromosomes3[1], chromosomes3[2], chromosomes3[3], chromosomes3[4], chromosomes3[5], s1->getType());
        Student *c2 = new Student(chromosomes4[0], chromosomes4[1], chromosomes4[2], chromosomes4[3], chromosomes4[4] ,chromosomes4[5], s2->getType());

        mutate_and_invert(c1);
        mutate_and_invert(c2);
        calculate_fitness_of(c1);
        calculate_fitness_of(c2);

        bool r1 = replace(c1);
        bool r2 = replace(c2);

        if (r1 || r2) {
            population_replaced = true;
        }
    }
    if (!population_replaced) {
        idle_generations++;
    }
    generations++;
    selected_population.clear();
}

int StudentGenetics::get_generations() {
    return generations;
}

bool StudentGenetics::replace(Student *s) {
    int index = find_least_fittest();
    Student *tmp = population[index];

    if (tmp->get_fitness_score() < s->get_fitness_score()) {
        population.erase(population.begin() + index);
        population.push_back(s);
        delete tmp;
        return true;
    } else {
        delete s;
        return false;
    }
}

int StudentGenetics::find_least_fittest() {
    Student *least = population[0];
    int index = 0;

    for (int i=1; i<population_size; i++) {
        if (population[i]->get_fitness_score() < least->get_fitness_score()) {
            least = population[i];
            index = i;
        }
    }
    return index;
}

void StudentGenetics::mutate_and_invert(Student *s) {
    float mutation_chance = random_float();

    if (mutation_chance <= 0.15) {
        Godot::print("Mutating student..");
        if (inc_dec_prob()) {
            int life_change = random_int(-5, 5);
            s->setLife(s->getLife() + life_change);
        }
        if (inc_dec_prob()) {
            int speed_change = random_int(-10, 10);
            s->setSpeed(s->getSpeed() + speed_change);
        }
        if (inc_dec_prob()) {
            s->setArcherResistance(s->getArcherResistance() + (random_int(-15, 15)/100));
        }
        if (inc_dec_prob()) {
            s->setMageResistance(s->getResistanceToWizards() + (random_int(-15, 15)/100));
        }
        if (inc_dec_prob()) {
            s->setGunnerResistance(s->getGunnerResistance() + (random_int(-15, 15)/100));
        }
        if (inc_dec_prob()) {
            s->setFireMageResistance(s->getFireThrowingResistance() + (random_int(-15, 15)/100));
        }
    }
}

bool StudentGenetics::inc_dec_prob() {
    float chance = random_float();
    return (chance <= 0.5);
}

void StudentGenetics::calculate_fitness_of(Student *s) {
    float base_life = s->get_base_life();
    float speed = s->getSpeed();
    float endurance = 
    s->getArcherResistance() + 
    s->getResistanceToWizards() + 
    s->getGunnerResistance() +  
    s->getFireThrowingResistance();
    s->set_fitness_score((base_life+speed*150)/endurance);
}

float StudentGenetics::get_total_fitness() {
    float total = 0.0;
    for (Student *s : population) {
        total += s->get_fitness_score();
    }
    return total;
}

float StudentGenetics::random_float() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

int StudentGenetics::random_int(int min, int max) {
    return min + (std::rand() % (max - min +1));
}
