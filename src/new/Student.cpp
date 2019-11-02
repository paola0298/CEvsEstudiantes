#include "Student.hpp"

using namespace godot;

void Student::_register_methods() {
    register_method("_init", &Student::_init);
    register_method("_ready", &Student::_ready);
    register_method("_process", &Student::_process);
    register_method("getLife", &Student::getLife);
    register_method("setLife", &Student::setLife);
    register_method("decreaseLife", &Student::decreaseLife);
    register_method("getSpeed", &Student::getSpeed);
    register_method("getArcherResistance", &Student::getArcherResistance);
    register_method("getResistanceToWizards", &Student::getResistanceToWizards);
    register_method("getGunnerResistance", &Student::getGunnerResistance);
    register_method("getFireThrowingResistance", &Student::getFireThrowingResistance);
    register_method("getType", &Student::getType);
}

void Student::_init() {}

void Student::_ready() {}

void Student::_process(float delta) {

}

Student::Student() {
    
}

Student::~ Student() {

}

Student::Student(float l, float s, float a_r, float m_r, float g_r, float fm_r, int t):
life(l), speed(s), archerResistance(a_r), resistanceToWizards(m_r), 
gunnerResistance(g_r), fireThrowingResistance(fm_r), type( t), base_life(l) {
    chromosome[0] = life;
    chromosome[1] = speed;
    chromosome[2] = archerResistance;
    chromosome[3] = resistanceToWizards;
    chromosome[4] = gunnerResistance;
    chromosome[5] = fireThrowingResistance;
}


float Student::getLife() {
    return life;
}

void Student::setLife(float newLife) {
    life = newLife;
    base_life = newLife;
}

void Student::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void Student::decreaseLife(float toDecrease, int defense_type) {
    if (life - toDecrease >= 0) {
        life -= toDecrease;
    } else {
        life = 0;
    }
}

float Student::getSpeed() {
    return speed;
}

float Student::getArcherResistance() {
    return archerResistance;
}

float Student::getResistanceToWizards() {
    return resistanceToWizards;
}

float Student::getGunnerResistance() {
    return gunnerResistance;
}

float Student::getFireThrowingResistance() {
    return fireThrowingResistance;
}

int Student::getType() {
    return type;
}

void Student::set_fitness_score(float score) {
    fitness_score = score;
}

float Student::get_fitness_score() {
    return fitness_score;
}

float Student::get_base_life() {
    return base_life;
}

float * Student::get_chromosome() {
    return chromosome;
}

void Student::setArcherResistance(float resistance) {
    archerResistance = resistance;
}

void Student::setMageResistance(float res) {
    resistanceToWizards = res;
}

void Student::setGunnerResistance(float res) {
    gunnerResistance = res;
}

void Student::setFireMageResistance(float res) {
    fireThrowingResistance = res;
}