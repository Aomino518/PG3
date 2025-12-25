#include "ClearScene.h"

void ClearScene::Init()
{
}

void ClearScene::Update()
{
	if (InputManager::GetInstance()->IsPressed(DIK_SPACE)) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "CLEARSCENE");
	Novice::ScreenPrintf(600, 360, "GAMECLEAR");
	Novice::ScreenPrintf(550, 400, "Press SPACE to TITLE");
}
