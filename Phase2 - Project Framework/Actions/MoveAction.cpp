#include "MoveAction.h"
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "../DEFS.h"
#include "../ApplicationManager.h"
#include "Action.h"

MoveAction::MoveAction(ApplicationManager* pApp) : Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Move the selected item to a point. Click on a point");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();
	//Read a point and store in point P
	pIn->GetPointClicked(P.x, P.y);


	pOut->ClearStatusBar();

}

//Execute the action
void MoveAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (SelecFigCount != 0)
	{
		Point Dist;
		Dist.x = P.x - SelectedFigList[0]->getFirstPt().x;
		Dist.y = P.y - SelectedFigList[0]->getFirstPt().y;
		SelectedFigList[0]->Move(P.x, P.y);
		Point newPosition;
		for (int i = 1; i < SelecFigCount; i++)
		{
			newPosition.x = (SelectedFigList[i]->getFirstPt().x) + Dist.x;
			newPosition.y = (SelectedFigList[i]->getFirstPt().y) + Dist.y;
			SelectedFigList[i]->Move(newPosition.x, newPosition.y);
		}
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else
	{
		pOut->PrintMessage("No items selected, please select an item first!");
	}

}