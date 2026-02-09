#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class BaseMin {
public:
	virtual void PrintMin() = 0;
	virtual ~BaseMin() {}
};

template <typename Type1, typename Type2>

class MinFunc : public BaseMin{
public:
	Type1 a;
	Type2 b;

	MinFunc(Type1 a, Type2 b) : a(a), b(b){};

	auto Min() {
		return a < b ? a : b;
	}

	void PrintMin() override {
		cout << Min() << endl;
	}
};

int main() {
	vector<unique_ptr<BaseMin>> m;

	m.push_back(make_unique<MinFunc<int, int>>(4, 6));
	m.push_back(make_unique<MinFunc<float, float>>(5.0f, 2.0f));
	m.push_back(make_unique<MinFunc<double, int>>(4.35, 5.32));
	m.push_back(make_unique<MinFunc<int, float>>(4, 2.5));
	m.push_back(make_unique<MinFunc<int, double>>(4, 3.14));
	m.push_back(make_unique<MinFunc<float, double>>(2.5f, 3.14));

	for (auto& item : m) {
		item->PrintMin();
	}
	
	return 0;
}