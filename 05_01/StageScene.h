#pragma once
#include "IScene.h"
#include "Player.h"
#include "InputHandler.h"

class StageScene : public IScene
{
private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_;

public:
	void Init() override;
	void Update() override;
	void Draw() override;
};