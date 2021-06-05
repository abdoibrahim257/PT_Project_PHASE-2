#include "SelectAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on a figure to Select");

	//get point clicked 
	pIn->GetPointClicked(P.x, P.y); //need validations 


	pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	ReadActionParameters();

	selectedFig = pManager->GetFigure(P.x, P.y); //kda byshawr 3la el selected figure

	if (selectedFig != NULL) //check if el pointer shawr 3la 7aga aslun wla l2
	{
		if (selectedFig->IsSelected())
		{
			un_Select();
		}
		else Select_Fig();
	}
}

void SelectAction::Select_Fig()
{
	Output* pOut = pManager->GetOutput(); //prints info of figure seleected IFF ONE FIGURE ONLY 

	selectedFig->SetSelected(true); //selected

	pManager->AddSelectedFigure(selectedFig); //add fig to the list

	pManager->printinfo(selectedFig);
}
void SelectAction::un_Select()
{
	selectedFig->SetSelected(false); //unselected
	pManager->UNSelectFigure(selectedFig); //add fig to the list
	pManager->printinfo(selectedFig);
}

SelectAction::~SelectAction() {} //destructor 

