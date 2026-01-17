#pragma once

class Selector;

class Unit
{
private:
	int mapX_;
	int mapY_;
	int mapSize_;
	int id = 0;
	bool isSelected_ = false;

public:
	Unit() = default;

	// 初期化
	void Init(int idref);
	// 更新
	void Update();
	// 描画
	void Draw();

	void Move(int x, int y);
	void MoveEnd(Selector* selector);
};

