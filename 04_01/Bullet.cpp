#include "Bullet.h"

Bullet::Bullet()
{
	pos_ = { 0.0f, 0.0f };
	radius_ = 10.0f;
	moveSpeed_ = 15.0f;
	isShot_ = false;
}

void Bullet::Update()
{
	if (isShot_) {
		pos_.y -= moveSpeed_;

		if (pos_.y < 0.0f) {
			isShot_ = false;
		}
	}
}

void Bullet::Draw()
{
	if (isShot_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			RED,
			kFillModeSolid);
	}
}

void Bullet::SetPos(Vector2 pos)
{
	this->pos_ = pos;
}

void Bullet::SetIsShot(bool isShot)
{
	this->isShot_ = isShot;
}
