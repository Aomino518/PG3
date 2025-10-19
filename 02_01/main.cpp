#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename T1, typename T2, typename T3>
T1 Min(T1 a, T2 b, T3 c) {
	if (a < b && a < c) {
		return static_cast<T1>(a);
	}

	if (b < a && b < c) {
		return static_cast<T1>(b);
	}

	return static_cast<T1>(c);
}

int main() {
	printf("%d\n", Min<int, float, double>(6, 5.0f, 7.29452l));
	return 0;
}