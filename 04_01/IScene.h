#pragma once
#include <Novice.h>

enum Scene {
	TITLE,
	STAGE,
	CLEAR
};

class IScene
{
protected:
	// シーン番号の管理変数
	static int sceneNo;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual ~IScene();

	// シーン番号ゲッター
	int GetSceneNo();
};

