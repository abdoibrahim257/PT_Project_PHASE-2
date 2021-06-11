#include "CopyAction.h"
#include "..\ApplicationManager.h"

CopyAction::CopyAction(ApplicationManager* pApp):Action(pApp)
{
	Cx =0;
	Cy =0;
}
CopyAction::~CopyAction()
{
}
void CopyAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Copy Figure: Selected figure has been copied to the Clipboard, Click any where to continue");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void CopyAction::Execute()
{
	ReadActionParameters();
	pManager->SetClipboard(SelectedFigList);
	pManager->SetIsFigCut(false);       //The Figures are copied not cut
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
}