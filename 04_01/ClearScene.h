#pragma once
#include "IScene.h"
#include "InputManager.h"

class ClearScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;
};

