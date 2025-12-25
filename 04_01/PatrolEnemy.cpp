#include "PatrolEnemy.h"

PatrolEnemy::PatrolEnemy()
{
	pos_ = { 640.0f, 25.0f };
	radius_ = 20.0f;
	moveSpeed_ = 2.0f;
	isAlive_ = true;
}

void PatrolEnemy::Update()
{
	if (isAlive_) {
		pos_.x += moveSpeed_;

		if (pos_.x <= 0.0f + radius_ || pos_.x >= 1280.0f - radius_) {
			moveSpeed_ *= -1;
		}
	}
}

void PatrolEnemy::Draw()
{
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			BLACK,
			kFillModeSolid);
	}
}

void PatrolEnemy::SetIsAlive(bool isAlive)
{
	this->isAlive_ = isAlive;
}
