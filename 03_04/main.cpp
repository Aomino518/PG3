#include <iostream>
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main()
{
	IShape* shapes[2];
	
	// 生成フェーズ
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			shapes[i] = new Circle(5.0);
		} else if (i == 1) {
			shapes[i] = new Rectangle(3.0f, 4.0f);
		}
	}

	// 実行フェーズ
	for (int i = 0; i < 2; i++) {
		shapes[i]->Size();
		shapes[i]->Draw();
	}

	// 破棄フェーズ
	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
}