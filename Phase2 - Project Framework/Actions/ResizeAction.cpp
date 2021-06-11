#include "ResizeAction.h"
#include "Action.h"
#include "../Figures/CFigure.h"

ResizeAction::ResizeAction(ApplicationManager* pApp) : Action(pApp)
{}

void ResizeAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Resize the selected item to a scale on your choice. Please type '1/4','1/2','2', or '4' for the respective scaling");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();

}

//Execute the action
void ResizeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//This action needs to read some parameters first
	ReadActionParameters();
	//Get the scale from the user
	if (SelecFigCount != 0)
	{
		string scale = pIn->GetString(pOut);
		while (scale != "1/4" && scale != "1/2" && scale != "2" && scale != "4" && scale != "quarter" && scale != "half" && scale != "double" && scale != "quadruple")
		{
			pOut->PrintMessage("Wrong scaling input! please type '1/4', '1/2', '2', or '4'");
			scale = pIn->GetString(pOut);
		}
		pOut->PrintMessage("You selected: " + scale);
		for (int i = 0; i < SelecFigCount; i++)
		{
			SelectedFigList[i]->Resize(scale);
		}
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}
	else
	{
		pOut->PrintMessage("No items selected, please select an item first!");
	}

}
