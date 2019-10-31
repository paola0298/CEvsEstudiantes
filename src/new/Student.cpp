#include "Student.hpp"

Student::Student(int l, int s, int a_r, int m_r, int g_r, int fm_r, int t):
life(l), speed(s), archerResistance(a_r), resistanceToWizards(m_r), 
gunnerResistance(g_r), fireThrowingResistance(fm_r), type( t) { }

Student::~Student() {

}

int Student::getLife() {
    return life;
}

void Student::setLife(int newLife) {
    life = newLife;
}

void Student::decreaseLife(int toDecrease, int type) {
    if (life - toDecrease >= 0) {
        life -= toDecrease;
    } else {
        life = 0;
    }
}

int Student::getSpeed() {
    return speed;
}

int Student::getArcherResistance() {
    return archerResistance;
}

int Student::getResistanceToWizards() {
    return resistanceToWizards;
}

int Student::getGunnerResistance() {
    return gunnerResistance;
}

int Student::getFireThrowingResistance() {
    return fireThrowingResistance;
}

int Student::getType() {
    return type;
}