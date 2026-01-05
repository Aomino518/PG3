#include "Player.h"

Player::Player() {
	pos_ = { 640.0f, 360.0f };
	radius_ = 20.0f;
	speed_ = 5.0f;
}

void Player::Init() {

}

void Player::Update() {

}

void Player::Draw() {
	Novice::DrawEllipse(
		static_cast<int>(pos_.x), 
		static_cast<int>(pos_.y), 
		static_cast<int>(radius_),
		static_cast<int>(radius_),
		0.0f,
		WHITE, 
		kFillModeSolid);
}

void Player::MoveRight() {
	this->pos_.x += this->speed_;
}

void Player::MoveLeft() {
	this->pos_.x -= this->speed_;
}
