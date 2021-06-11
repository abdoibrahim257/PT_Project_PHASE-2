#include "CutAction.h"
#include "..\ApplicationManager.h"
CutAction::CutAction(ApplicationManager* pApp):Action(pApp)
{
	Cx = 0;
	Cy = 0;
}
CutAction::~CutAction()
{
}
void CutAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Cut Figure: Selected figure has been cut to the Clipboard, Click any where to continue");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void CutAction::Execute()
{
	ReadActionParameters();
	//fig = pManager->GetFigure(Cx, Cy);  //Get the coordinates of the selected figure
	//pManager->SetClipboard(fig);
	//pManager->SetIsFigCut(true);       //The Figure is cut not copied
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}