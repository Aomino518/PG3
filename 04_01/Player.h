#pragma once
#include <Novice.h>
#include "MathUtils.h"
#include "InputManager.h"
#include "Bullet.h"
#include "PatrolEnemy.h"
#include <memory>

class Player
{
public:
	Player();
	// 更新処理
	void Update();
	// 描画処理
	void Draw();

	// Getter関数
	Vector2 GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }
	bool GetIsAlive() const { return isAlive_; }

	// Setter関数
	void SetIsAlive(bool isAlive);

	// 弾と敵の判定
	void Collision(PatrolEnemy* enemey);

private:
	Vector2 pos_;
	float radius_;
	float moveSpeed_;
	bool isAlive_;

	std::unique_ptr<Bullet> bullet_;

	// 移動処理
	void Move();
	// 発射処理
	void Shot();
};

