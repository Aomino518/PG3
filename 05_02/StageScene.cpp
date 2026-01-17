#include "StageScene.h"

void StageScene::Init() {

}

void StageScene::Update() {

}

void StageScene::Draw(){
	// 縦線
	for (int i = 0; i < 40; i++) {
		float width = 32.0f * i;
		Novice::DrawLine(
			static_cast<int>(width),
			0,
			static_cast<int>(width),
			640,
			WHITE
		);
	}

	// 横線
	for (int i = 0; i < 20; i++) {
		float height = 32.0f * i;
		Novice::DrawLine(
			0,
			static_cast<int>(height),
			1280,
			static_cast<int>(height),
			WHITE
		);
	}

	Novice::DrawBox(
		0,
		640,
		1280,
		80,
		0.0f,
		BLACK,
		kFillModeSolid
	);
}
