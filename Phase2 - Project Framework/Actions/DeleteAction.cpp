#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{
	selectedFig = pManager->GetSelectedFigs();

	SelecFigCount = pManager->GetSelectedCount();

}

void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	if (selectedFig[0] == NULL)
	{
		pOut->PrintMessage("Invalid Action: please select figure first");
	}
		pOut->PrintMessage("Figure Deleted");
}

DeleteAction::~DeleteAction() {}