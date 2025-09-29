#include <stdlib.h>
#include <iostream>
#include <list>
using namespace std;

int main() {
	list<const char*> lst{ "Tokyo", "Kanda", "Akihabara", "Okatimachi", "Ueno", "Uguisudani", 
	"Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro",
	"Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Shibuya", "Ebisu", "Meguro", "Gotanda", 
	"Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"};

	int index = 1;

	cout << "1970年" << endl;
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << "JY" << index << ":" << *itr << endl;
		index++;
	}
	index = 1;

	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Tabata") {
			itr = lst.insert(itr, "Nishi-Nippori");
			++itr;
		}
	}

	cout << "\n2019年" << endl;
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << "JY" << index << ":" << *itr << endl;
		index++;
	}
	index = 1;

	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		if (*itr == "Tamachi") {
			itr = lst.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}

	cout << "\n2022年" << endl;
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << "JY" << index << ":" << *itr << endl;
		index++;
	}
	index = 1;

	return 0;
}