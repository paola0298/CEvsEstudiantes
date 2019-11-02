#include "Player.hpp"

using namespace godot;

Player::Player() {
    int speed = 40;
    motion = Vector2();
}

Player::~Player() {}

void Player::_init() {}

void Player::_register_methods() {
    register_method("_process", &Player::_process);
    register_method("cartesian_to_isometric", &Player::cartesian_to_isometric);
    register_method("isometric_to_cartesian", &Player::isometric_to_cartesian);
}

Vector2 Player::cartesian_to_isometric(Vector2 cartesian) {
    return Vector2(cartesian.x - cartesian.y, (cartesian.x + cartesian.y) / 2);
}

Vector2 Player::isometric_to_cartesian(Vector2 isometric) {
    Vector2 pos = Vector2();
    pos.x = (isometric.x + isometric.y * 2) / 2;
    pos.y = -isometric.x + pos.x;
    return pos;
}

void Player::_process(float delta) {
    UpdateMotionFromInput(delta);
	move_and_slide(motion);
    
}

void Player::UpdateMotionFromInput(float delta) {
	motion = Vector2();
	Input* i = Input::get_singleton();

	// if (i->is_action_pressed("ui_up")) {
	// 	motion.y -= SPEED;
	// }
	// if (i->is_action_pressed("ui_down")) {
	// 	motion.y += SPEED;
	// }
	// if (i->is_action_pressed("ui_left")) {
	// 	motion.x -= SPEED;
	// }
	// if (i->is_action_pressed("ui_right")) {
	// 	motion.x += SPEED;
	// }
    if (i->is_action_pressed("ui_up")) {
        motion += Vector2(0, -1);
    }
    if (i->is_action_pressed("ui_down")) {
        motion += Vector2(0, 1);
    }
    if (i->is_action_pressed("ui_left")) {
        motion += Vector2(-1, 0);
    }
    if (i->is_action_pressed("ui_right")) {
        motion += Vector2(1, 0);
    }
	motion = motion.normalized() * SPEED;
    motion = cartesian_to_isometric(motion);
	move_and_slide(motion);
}
