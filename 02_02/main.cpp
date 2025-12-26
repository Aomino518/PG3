#include <iostream>

using namespace std;

/// <summary>
/// 再帰的関数
/// </summary>
/// <param name="hours">働いた時間</param>
/// <returns>賃金の額</returns>
int Recursive(int hours) {
	if (hours <= 1) {
		return (100);
	}

	return Recursive(hours - 1) * 2 - 50;
}

/// <summary>
/// 再帰的賃金体系の累計額を返す関数
/// </summary>
/// <param name="hours">働いた時間</param>
/// <returns>賃金の合計額</returns>
int RecursiveSum(int hours) {
	if (hours <= 1) {
		return (100);
	}

	return RecursiveSum(hours - 1) + Recursive(hours);
}

int main() {
	int hours = 8;
	int common = 1226;

	cout << "時間\t一般的\t再帰的" << endl;
	// 計算比較
	for (int h = 1; h <= hours; ++h) {
		int commonResult = common * h;
		int recursive = RecursiveSum(h);
		cout << h << "h\t" << commonResult << "\t" << recursive << endl;
	}
}
