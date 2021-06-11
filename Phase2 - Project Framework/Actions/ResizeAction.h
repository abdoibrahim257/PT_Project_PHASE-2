#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "Action.h"


class ResizeAction : public Action
{
	int SelecFigCount;
	CFigure** SelectedFigList;

public:
	ResizeAction(ApplicationManager* pmanager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

