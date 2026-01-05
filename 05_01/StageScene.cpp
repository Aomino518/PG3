#include "StageScene.h"

void StageScene::Init() {
	inputHandler_ = new InputHandler();

	// Assign command
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	// NewPlayer
	player_ = new Player();
}

void StageScene::Update() {
	// get Input
	iCommand_ = inputHandler_->HandleInput();

	// set command
	if (this->iCommand_) {
		iCommand_->Exec(*player_);
	}

	player_->Update();
}

void StageScene::Draw() {
	player_->Draw();
}