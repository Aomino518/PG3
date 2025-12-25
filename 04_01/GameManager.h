#pragma once
#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "InputManager.h"

class GameManager
{
private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_; // 現在のシーン
	int prevSceneNo_; // 前のシーン

public:
	GameManager();
	~GameManager();

	int Run();
};

