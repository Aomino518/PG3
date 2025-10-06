#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

/// <summary>
/// 文字列の中から数字だけを抜き出してint型に変換する関数
/// </summary>
/// <param name="s">学籍番号</param>
/// <returns></returns>
int StrangeNumber(const string& s) {
	string num;
	// 文字列sの中の1文字1文字cを順番にチェック
	for (char c : s) {
		// 数字かどうかチェック、数字ならnumに追加
		if (isdigit(c)) {
			num += c;
		}
	}
	
	// 数字が見つからなければ0を返す
	if (num.empty()) {
		return 0;
	}

	return stoi(num);
}

int main() {
	vector<string> studentNumber;
	ifstream file("PG3_2025_01_02.txt");
	string line;

	// ファイルを開く
	if (file.is_open()) {
		while (getline(file, line, ',')) {
			if (!line.empty()) {
				studentNumber.push_back(line);
			}
		}
		file.close();
	}
	else {
		cout << "ファイルを開けませんでした" << endl;
		return 1;
	}

	// 昇順に並べる
	sort(studentNumber.begin(), studentNumber.end(), [](const string& a, const string& b) {
		return StrangeNumber(a) < StrangeNumber(b);
		});

	// 学籍番号表示
	for (vector<string>::iterator it_s = studentNumber.begin(); 
		it_s != studentNumber.end();
		it_s++) {
		cout << *it_s << endl;
	}

	return 0;
}