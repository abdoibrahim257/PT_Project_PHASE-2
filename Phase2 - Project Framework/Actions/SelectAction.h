#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"
#include "..\Figures\CFigure.h"

// we can use Cfigure for selection
class SelectAction : public Action
{
private:

	Point P; //point clicked
	CFigure* selectedFig; //pointer to selected fiqure

	
public:

	SelectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();
	void Select_Fig();
	void un_Select();
	~SelectAction();
};
#endif