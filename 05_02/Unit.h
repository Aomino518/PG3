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

	// Getter
	int GetMapX() { return mapX_; }
	int GetMapY() { return mapY_; }
	int GetMapSize() { return mapSize_; }
	int GetId() { return id; }
	bool GetIsSelected() { return isSelected_; }

	// Setter
	void SetMapX(int mapX) { this->mapX_ = mapX; }
	void SetMapY(int mapY) { this->mapY_ = mapY; }
	void SetMapSize(int mapSize) { this->mapSize_ = mapSize; }
	void SetId(int idNum) { this->id = idNum; }
	void Set(bool isSelected) { this->isSelected_ = isSelected; }
};

