#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LE2B_27_モリ_アオト";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();

	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
