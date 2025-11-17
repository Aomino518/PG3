#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename Type1, typename Type2>

class MinFunc {
public:
	Type1 a;
	Type2 b;

	MinFunc(Type1 a, Type2 b) : a(a), b(b){};

	auto min() {
		return a < b ? a : b;
	}
};

int main() {
	MinFunc<int, int> m1(4, 6);
	MinFunc<float, float> m2(5.0f, 2.0f);
	MinFunc<double, int> m3(4.35, 5.32);

	MinFunc<int, float> m4(4, 2.5f);
	MinFunc<int, double> m5(4, 3.14);
	MinFunc<float, double> m6(2.5f, 3.14);

	cout << m1.min() << endl;
	cout << m2.min() << endl;
	cout << m3.min() << endl;
	cout << m4.min() << endl;
	cout << m5.min() << endl;
	cout << m6.min() << endl;

	return 0;
}