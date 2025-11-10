#include "Enemy.h"

Enemy::Enemy()
{
	index = 0;
	stateTimer = 0;
}

/// <summary>
/// 更新関数
/// </summary>
void Enemy::Update()
{
	(this->*stateFunc[index])();
	Sleep(1000);

	if (++stateTimer > 3) {
		++index;
		stateTimer = 0;
	}

	if (index >= 3) {
		index = 0;
	}

}

/// <summary>
/// 接近中の関数
/// </summary>
void Enemy::Approach()
{
	cout << "接近中..." << endl;
}

/// <summary>
/// 攻撃中の関数
/// </summary>
void Enemy::Attack()
{
	cout << "攻撃中..." << endl;
}

/// <summary>
/// 離脱中の関数
/// </summary>
void Enemy::Escape()
{
	cout << "離脱中..." << endl;
}

void (Enemy::*Enemy::stateFunc[])() = {
	&Enemy::Approach,
	&Enemy::Attack,
	&Enemy::Escape
};