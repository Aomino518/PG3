#pragma once
#include <Novice.h>

class InputManager
{
public:
	static InputManager* GetInstance();
	void Update();

	bool IsDown(int dik) const;
	bool IsPressed(int dik) const;
	bool IsReleased(int dik) const;

private:
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
};

