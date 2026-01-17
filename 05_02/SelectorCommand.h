#pragma once
#include "IStageSceneCommand.h"
#include "Selector.h"

class SelectorMoveCommand : public IStageSceneCommand
{
public:
	SelectorMoveCommand(Selector* selector, int x, int y);
	void Exec() override;

private:
	Selector* selector_;
	int x_;
	int y_;
};

class SelectUnitCommand : public IStageSceneCommand
{
public:
	SelectorCommand(Selector* selector);
}



