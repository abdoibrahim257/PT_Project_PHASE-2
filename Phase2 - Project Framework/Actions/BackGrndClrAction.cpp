#include "BackGrndClrAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


BackGrndClrAction::BackGrndClrAction(ApplicationManager* pApp) : Action(pApp)
{}


void BackGrndClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose color from following");
}


void BackGrndClrAction::Execute()
{
	ReadActionParameters();
}


BackGrndClrAction::~BackGrndClrAction() {}


