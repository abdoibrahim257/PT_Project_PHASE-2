#include "FillClrAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


FillClrAction::FillClrAction(ApplicationManager* pApp) : Action(pApp)
{}


void FillClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose color from following");
}


void FillClrAction::Execute()
{
	ReadActionParameters();
}


FillClrAction::~FillClrAction() {}


