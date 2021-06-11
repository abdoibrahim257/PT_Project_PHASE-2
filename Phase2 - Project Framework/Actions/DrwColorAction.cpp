#include "DrwColorAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrwColorAction::DrwColorAction(ApplicationManager* pApp) : Action(pApp)
{}


void DrwColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose color from following");
}


void DrwColorAction::Execute()
{
	ReadActionParameters();
}


DrwColorAction::~DrwColorAction() {}
