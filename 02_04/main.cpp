#include <stdio.h>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main(int argc, const char* argv[]) {
	// 乱数初期化
	srand((unsigned)time(NULL));

	// ユーザー入力
	int userGuess = 0;
	printf("偶数:0 か奇数:1 か\n");
	scanf_s("%d", &userGuess);

	// 出目を生成
	int roll = rand() % 6 + 1;

	std::function<void()> showResult = [=]() {
		int num = roll % 2;

		// 同じであれば偶数、でなければ奇数
		if (userGuess == num) {
			printf("出目は%dでした\n", roll);
			printf("正解\n");
		} else {
			printf("出目は%dでした\n", roll);
			printf("不正解\n");
		}

		};

	std::function<void(unsigned int)> delayReveal = [=](unsigned int delayMs) {
		// コールバック関数を呼び出す
		Sleep(delayMs);
		showResult();
		};

	// 遅延実行
	delayReveal(3000);

	return 0;
}