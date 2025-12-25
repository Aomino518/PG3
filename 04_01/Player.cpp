#include "Player.h"
#include <algorithm>

Player::Player()
{
	pos_ = { 640.0f, 690.0f };
	radius_ = 20.0f;
	moveSpeed_ = 5.0f;
	isAlive_ = true;
	bullet_ = std::make_unique<Bullet>();
}

void Player::Update()
{
	Move();
	Shot();
}

void Player::Draw()
{
	bullet_->Draw();
	if (isAlive_) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			0.0f,
			WHITE,
			kFillModeSolid);
	}
}

void Player::SetIsAlive(bool isAlive)
{
	this->isAlive_ = isAlive;
}

void Player::Move()
{
	if (isAlive_) {
		if (InputManager::GetInstance()->IsDown(DIK_A)) {
			pos_.x -= moveSpeed_;
		}

		if (InputManager::GetInstance()->IsDown(DIK_D)) {
			pos_.x += moveSpeed_;
		}

		pos_.x = std::clamp(pos_.x, 0.0f + radius_, 1280.0f - radius_);
	}
}

void Player::Shot()
{
	if (!bullet_->GetIsShot() && isAlive_) {
		if (InputManager::GetInstance()->IsPressed(DIK_SPACE)) {
			bullet_->SetPos(pos_);
			bullet_->SetIsShot(true);
		}
	}

	bullet_->Update();
}

void Player::Collision(PatrolEnemy* enemey)
{
	if (bullet_->GetIsShot() && IsCollision(bullet_->GetPos(), enemey->GetPos(), bullet_->GetRadius(), enemey->GetRadius())) {
		enemey->SetIsAlive(false);
		bullet_->SetIsShot(false);
	}
}

