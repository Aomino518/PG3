#include <stdlib.h>
#include <iostream>
#include <vector>

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

int main() {
	int hours = 9;
	int common = 1226;

	cout << "時間\t一般的\t再帰的" << endl;
	// 計算比較
	for (int h = 1; h <= hours; ++h) {
		int commonResult = common * h;
		int recursive = Recursive(h);
		cout << h << "h\t" << commonResult << "\t" << recursive << endl;
	}
}
