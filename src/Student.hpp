#ifndef _STUDENT_H
#define _STUDENT_H

enum StudentType {
    Ogro,
    ElfoOscuro,
    Harpia,
    Mercenarios
};

class Student {
    private:
        int life;
        int speed;
        int archerResistance;
        int resistanceToWizards;
        int gunnerResistance;
        int fireThrowingResistance;
        StudentType type;

    public: 
        Student(int life, int speed, int archerResistance, int resistanceToWizards, int gunnerResistance, int fireThrowingResistance,StudentType type);
        ~Student();

        int getLife();
        void setLife(int newLife);
        void decreaseLife(int toDecrease);
        int getSpeed();
        int getArcherResistance();
        int getResistanceToWizards();
        int getGunnerResistance();
        int getFireThrowingResistance();
        StudentType getType();
};

#endif