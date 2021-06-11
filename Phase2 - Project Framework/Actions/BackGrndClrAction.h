#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class BackGrndClrAction : public Action
{
private:
	color color;
public:
	BackGrndClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~BackGrndClrAction();
};