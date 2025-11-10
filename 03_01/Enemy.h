#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <windows.h>
#include <iostream>

using namespace std;

// 敵クラス
class Enemy {
public:
	Enemy();
	void Update();

	// 状態関数
	void Approach();
	void Attack();
	void Escape();

private:
	static void (Enemy::*stateFunc[])();
	int index;
	int stateTimer;
};

