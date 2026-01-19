#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

/// <summary>
/// 文字列中の数字だけを取り出してintに変換する関数
/// </summary>
/// <param name="s">文字列</param>
/// <returns>数字</returns>
int ExtractNumber(const string& s) {
    string num;
    int result = 0;

    // 文字か数字かチェック
    for (char c : s) {
        if (isdigit(c)) {
            num += c;
        }
    }

    // 数字がなければ0そうでなければintに変換
    if (num.empty()) {
        return result;
    } else {
        result = stoi(num);
    }

    return result;
}

int main() {
    vector<string> studentNumber;
    ifstream file("PG3_2025_01_02.txt");
    string line;

    // ファイルオープン
    if (file.is_open()) {
        while (getline(file, line, ',')) {
            if (!line.empty()) {
                studentNumber.push_back(line);
            }
        }
        file.close();
    } else {
        cout << "ファイルを開けませんでした" << endl;
        return 1;
    }

    // ソートで学籍番号順に入れ替え
    sort(studentNumber.begin(), studentNumber.end());

    // 学籍番号を表示
    for (const string& s : studentNumber) {
        cout << s << endl;
    }

    return 0;
}
