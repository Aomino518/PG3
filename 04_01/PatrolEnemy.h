#pragma once
#include <Novice.h>
#include "MathUtils.h"

class PatrolEnemy
{
public:
	PatrolEnemy();
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

private:
	Vector2 pos_;
	float radius_;
	float moveSpeed_;
	bool isAlive_;
};

