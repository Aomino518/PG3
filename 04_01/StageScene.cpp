#include "StageScene.h"

void StageScene::Init()
{
	player_ = std::make_unique<Player>();
	enemy_ = std::make_unique<PatrolEnemy>();
	isClear = false;
}

void StageScene::Update()
{
	// 弾と敵の衝突判定
	player_->Collision(enemy_.get());

	// クリアしたかの判定
	if (!enemy_->GetIsAlive()) {
		isClear = true;
	}

	// シーン遷移する条件の判定
	if (isClear) {
		sceneNo = CLEAR;
	}

	player_->Update();
	enemy_->Update();
}

void StageScene::Draw()
{
	player_->Draw();
	enemy_->Draw();
	Novice::ScreenPrintf(0, 0, "STAGESCENE");
	Novice::ScreenPrintf(0, 25, "Press SPACE to Shot");
	Novice::ScreenPrintf(0, 50, "Move: WS");
}
