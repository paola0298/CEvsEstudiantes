#pragma once

#include <core/Godot.hpp>
#include <KinematicBody2D.hpp>
#include <string>
#include <PoolArrays.hpp>

namespace godot {

    /*
    ogro:           0
    mercenario:     1
    arpía:          2
    elfo oscuro:    3
    */
    class Student: public KinematicBody2D{
        GODOT_CLASS(Student, KinematicBody2D);

        private:
            float life;
            float base_life;
        
            float archerResistance;
            float resistanceToWizards;
            float gunnerResistance;
            float fireThrowingResistance;
            int type;
            //Genetics related variables
            double fitness_score;
            float chromosome[6] = {0.0};


        public: 
            Student();
            Student(float life, float speed, float a_r, float m_r, float g_r, float fm_r, int type);
            ~Student();

            PoolVector2Array path;

            void set_path(PoolVector2Array path);
            void move_along_path(float distance);

            //Godot methods
            void _init();
            void _ready();
            void _process(float delta);
            static void _register_methods();

            float getLife();
            float get_base_life();
            void setLife(float newLife);
            void decreaseLife(float toDecrease, int defense_type);
            void setSpeed(float newSpeed);
            float getSpeed();
            float getArcherResistance();
            void setArcherResistance(float resistance);
            float getResistanceToWizards();
            void setMageResistance(float resistance);
            float getGunnerResistance();
            void setGunnerResistance(float resistance);
            float getFireThrowingResistance();
            void setFireMageResistance(float resistance);
            int getType();
            //Genetics related methods
            void set_fitness_score(float score);
            float get_fitness_score();
            float * get_chromosome();
            int speed = 400;
    };
}
