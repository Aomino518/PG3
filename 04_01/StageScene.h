#pragma once
#include "IScene.h"
#include "InputManager.h"
#include "Player.h"
#include "PatrolEnemy.h"
#include <memory>

class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	std::unique_ptr<Player> player_;
	std::unique_ptr<PatrolEnemy> enemy_;
	bool isClear;
};