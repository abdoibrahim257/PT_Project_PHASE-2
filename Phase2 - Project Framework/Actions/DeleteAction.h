#ifndef DEL_ACTION_H
#define DEl_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

class DeleteAction : public Action
{
private:

	int SelecFigCount;
	CFigure** selectedFig;

public:
	DeleteAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteAction();
};

#endif