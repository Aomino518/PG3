#include <stdlib.h>
#include <iostream>
#include <list>

using namespace std;

/// <summary>
/// リストを表示する関数
/// </summary>
/// <param name="year">年</param>
/// <param name="lst">リスト</param>
void PrintList(const char* year, list<const char*> lst) {
	int index = 1;

	cout << year << endl;
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << "JY" << index << ":" << *itr << endl;
		index++;
	}
	cout << "\n";
}

/// <summary>
/// リストに挿入する関数
/// </summary>
/// <param name="lst">リスト</param>
/// <param name="insertTarget">挿入先</param>
/// <param name="insertText">挿入名</param>
void Insert(list<const char*>& lst, const char* insertTarget, const char* insertText) {
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == insertTarget) {
			itr = lst.insert(itr, insertText);
			++itr;
		}
	}
}

int main() {
	list<const char*> lst{ "Tokyo", "Kanda", "Akihabara", "Okatimachi", "Ueno", "Uguisudani", 
	"Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro",
	"Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Shibuya", "Ebisu", "Meguro", "Gotanda", 
	"Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"};

	PrintList("1970年", lst);
	Insert(lst, "Tabata", "Nishi-Nippori");

	PrintList("2019年", lst);
	Insert(lst, "Tamachi", "Takanawa Gateway");

	PrintList("2022年", lst);

	return 0;
}