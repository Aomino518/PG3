#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/// <summary>
/// 遅延実行関数
/// </summary>
/// <param name="fn">呼び出す関数</param>
/// <param name="delayMs">待機時間</param>
/// <param name="roll">出目</param>
/// <param name="userGuess">ユーザーの答え</param>
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	// コールバック関数を呼び出す
	Sleep(delayMs);
	fn(roll, userGuess);
}

/// <summary>
/// 結果を判定表示する関数
/// </summary>
/// <param name="roll">出目</param>
/// <param name="userGuess">ユーザーの答え</param>
void ShowResult (int roll, int userGuess) {
	int num = roll % 2;

	// 同じであれば偶数、でなければ奇数
	if (userGuess == num) {
		printf("出目は%dでした\n", roll);
		printf("正解\n");
	} 
	else {
		printf("出目は%dでした\n", roll);
		printf("不正解\n");
	}

}

int main() {
	// 乱数初期化
	srand((unsigned)time(NULL));

	// ユーザー入力
	int userGuess = 0;
	printf("偶数:0 か奇数:1 か\n");
	scanf_s("%d", &userGuess);

	// 出目を生成
	int roll = rand() % 6 + 1;

	// 遅延実行関数を実行
	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}