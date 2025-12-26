#include <iostream>

using namespace std;

template <typename T>
T Min(T a, T b) {
	return (a < b) ? a : b;
}

int main() {
	cout << Min<int>(6, 5) << endl;
	cout << Min<float>(4.3f, 7.2f) << endl;
	cout << Min<double>(7.294, 4.284) << endl;
	return 0;
}