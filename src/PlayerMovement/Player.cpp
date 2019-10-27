#include "Player.hpp"

using namespace godot;

void Player::_register_methods() {
    register_method("_process", &Player::_process);
}

Player::Player() {
    int speed = 0;
    motion = Vector2(0, 0);
}

Player::~Player() {}

void Player::_init() {}

void Player::_process() {
    motion = Vector2(0, 0);
	Input* i = Input::get_singleton();
	if (i->is_action_pressed("ui_up")) {
		motion.y -= SPEED;
	}
	if (i->is_action_pressed("ui_down")) {
		motion.y += SPEED;
	}
	if (i->is_action_pressed("ui_left")) {
		motion.x -= SPEED;
	}
	if (i->is_action_pressed("ui_right")) {
		motion.x += SPEED;
	}
    move_and_slide(motion);
}