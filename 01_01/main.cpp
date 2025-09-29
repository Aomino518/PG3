#include <stdlib.h>
#include <vector>
#include <iostream>
#include <list>
using namespace std;

int main() {
	list<const char*> lst{ "Tokyo", "Kanda", "Akihabara", "Okatimachi", "Ueno", "Uguisudani", 
	"Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro",
	"Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Shibuya", "Ebisu", "Meguro", "Gotanda", 
	"Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"};

	list<const char*>::iterator itr;
	itr = lst.begin();
	
	for (auto itr = lst.begin(); itr != lst.end(); ++itr) {
		cout << *itr << endl;
	}
	return 0;
}