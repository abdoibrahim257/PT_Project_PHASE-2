#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class DrwColorAction : public Action
{
private:
	color clr; //e; color ely el user hyd5lo
public:
	DrwColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void Execute();
	~DrwColorAction();
};
