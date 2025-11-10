#include <stdio.h>
#include <functional>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include "Enemy.h"

using namespace std;

int main() {
	Enemy enemy;

	while (true) {
		enemy.Update();
	}

	return 0;
}