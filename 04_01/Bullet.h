#pragma once
#include <Novice.h>
#include "MathUtils.h"

class Bullet
{
public:
	Bullet();
	// 更新処理
	void Update();
	// 描画処理
	void Draw();

	// Getter関数
	Vector2 GetPos() const { return pos_; }
	float GetRadius() const { return radius_; }
	bool GetIsShot() const { return isShot_; }

	// Setter関数
	void SetPos(Vector2 pos);
	void SetIsShot(bool isShot);

private:
	Vector2 pos_;
	float radius_;
	float moveSpeed_;
	bool isShot_;
};

