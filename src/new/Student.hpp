#pragma once

// #include <core/Godot.hpp>
// #include <Node.hpp>
// #include <string>

// namespace godot {
//     class Student: public Node {
//         GODOT_CLASS(Student, Node);

//         public:
//             Student();
//             ~Student();

//             void _init();
//             void _ready();
        
//         private:
//             int life;
//             int speed;
//             int archer_r;
//             int mage_r;
//             int firemage_r;
//             int gunner_r;
//             std::string type;
//     };
// }

class Student {
    private:
        int life;
        int speed;
        int archerResistance;
        int resistanceToWizards;
        int gunnerResistance;
        int fireThrowingResistance;
        int type;

    public: 
        Student(int life, int speed, int a_r, int m_r, int g_r, int fm_r, int type);
        ~Student();

        int getLife();
        void setLife(int newLife);
        void decreaseLife(int toDecrease, int type);
        int getSpeed();
        int getArcherResistance();
        int getResistanceToWizards();
        int getGunnerResistance();
        int getFireThrowingResistance();
        int getType();
};
