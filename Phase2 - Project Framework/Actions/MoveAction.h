#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Action.h"

class MoveAction : public Action
{
	Point P;
	int SelecFigCount;
	CFigure** SelectedFigList; //Array of pointers

public:
	MoveAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();

};