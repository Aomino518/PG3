#include "InputManager.h"

InputManager* InputManager::GetInstance()
{
	static InputManager instance;
	return &instance;
}

void InputManager::Update()
{
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
}

bool InputManager::IsDown(int dik) const
{
	return keys[dik];
}

bool InputManager::IsPressed(int dik) const
{
	return keys[dik] && !preKeys[dik];
}

bool InputManager::IsReleased(int dik) const
{
	return !keys[dik] && preKeys[dik];
}
