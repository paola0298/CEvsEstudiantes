#include "Defense.hpp"

using namespace godot;

void Defense::_register_methods() {

}

Defense::Defense() { }

Defense::Defense(int damageN) : credits(damageN) { }

Defense::~Defense() { }

void Defense::_init() { }

void Defense::_ready() { }

void Defense::set_damage(int damage) { 
    credits = damage;
}

int Defense::get_damage() {
    return credits;
}

int Defense::get_level() {
    return level;
}

void Defense::upgrade() {
    if (level < 5) {
        level++;
        credits *= 1.20;
    }
}
