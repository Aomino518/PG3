#pragma once
#include "MathUtils.h"
#include <Novice.h>

class Player
{
public:
	Player();		
	
	void Init();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:
	Vector2 pos_;
	float speed_;
	float radius_;
};

