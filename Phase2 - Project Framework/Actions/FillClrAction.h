#pragma once
#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class FillClrAction : public Action
{
private:
	color color;
public:
	FillClrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~FillClrAction();
};