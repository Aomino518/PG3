#include <stdlib.h>
#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Airplane.h"
#include "Ship.h"

using namespace std;

int main() {
	Vehicle* vehicles[4];

	// 生成フェーズ
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			vehicles[i] = new Car;
		} else if(i == 1){
			vehicles[i] = new Airplane;
		} else if (i >= 2) {
			vehicles[i] = new Ship;
		}
	}

	// 動くフェーズ
	for (int i = 0; i < 4; i++) {
		vehicles[i]->Move();
	}

	// 破棄フェーズ
	for (int i = 0; i < 4; i++) {
		delete vehicles[i];
	}

	return 0;
}