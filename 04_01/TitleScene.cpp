#include "TitleScene.h"

void TitleScene::Init()
{

}

void TitleScene::Update()
{
	if (InputManager::GetInstance()->IsPressed(DIK_SPACE)) {
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "TITLESCENE");
	Novice::ScreenPrintf(550, 400, "Press SPACE to GAMESTART");
}
