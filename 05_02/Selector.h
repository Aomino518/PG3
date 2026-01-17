#pragma once

class Selector
{
public:
	Selector();

	// 初期化
	void Init();
	// 更新
	void Update();
	// 描画
	void Draw();

	// 移動関数
	void Move(int x, int y);
	void Selectinit();

private:
	int mapX_;
	int mapY_;
	int mapSize_;

	int SelectMode_;
};

