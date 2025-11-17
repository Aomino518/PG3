#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T Min(T a, T b) {
	return (a < b) ? a : b;
}

int main() {
	cout << Min(6, 5) << endl;
	cout << Min(5.0f, 7.2f) << endl;
	cout << Min(7.29, 3.14) << endl;
	return 0;
}