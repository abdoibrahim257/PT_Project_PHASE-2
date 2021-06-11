#include "PasteAction.h"
#include "..\ApplicationManager.h"
#include "AddRectAction.h"
#include "..\Figures\CFigure.h"

PasteAction::PasteAction(ApplicationManager* pApp):Action(pApp)
{
	Cx=0;
	Cy=0;
}
PasteAction::~PasteAction()
{
}
void PasteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Paste Figure: Click anywhere to paste");

	SelectedFigList = pManager->GetSelectedFigs();
	SelecFigCount = pManager->GetSelectedCount();

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
	ReadActionParameters();
	SelectedFigList = pManager->GetClipboard();
	Output* pOut = pManager->GetOutput();
	if (SelecFigCount != 0)
	{
		Point TEMP1, TEMP2, TEMP3;
		TEMP1.y = 81; TEMP2.y = 81; TEMP3.y = 81;    //Initial value to allow drawing in drawing area only
		SelectedFigList[0]->Paste(Cx, Cy, TEMP1, TEMP2, TEMP3);
		Point Dist;   //Get the difference between first point of the selected figure and the first point of the pasted figure
		Dist.x = Cx - SelectedFigList[0]->getFirstPt().x;
		Dist.y = Cy - SelectedFigList[0]->getFirstPt().y;
		//Draw first selected figure only
		//Checks that the y-coordinate of the clicked point is in the drawing area
		if (TEMP1.y > UI.ToolBarHeight && TEMP1.y <= (UI.height - UI.StatusBarHeight) && TEMP2.y > UI.ToolBarHeight && TEMP2.y <= (UI.height - UI.StatusBarHeight) && TEMP3.y > UI.ToolBarHeight && TEMP3.y <= (UI.height - UI.StatusBarHeight))
		{
			if (dynamic_cast<CRectangle*>(SelectedFigList[0]))
			{
				CRectangle* pR = new CRectangle(TEMP1, TEMP2, (SelectedFigList[0]->GetGFXINFO()));
				pManager->AddFigure(pR);
			}
			else if (dynamic_cast<CLine*>(SelectedFigList[0]))
			{
				CLine* pR = new CLine(TEMP1, TEMP2, (SelectedFigList[0]->GetGFXINFO()));
				pManager->AddFigure(pR);
			}
			else if (dynamic_cast<CTriangle*>(SelectedFigList[0]))
			{
				CTriangle* pR = new CTriangle(TEMP1, TEMP2, TEMP3, (SelectedFigList[0]->GetGFXINFO()));
				pManager->AddFigure(pR);
			}
			else if (dynamic_cast<CCircle*>(SelectedFigList[0]))
			{
				CCircle* pR = new CCircle(TEMP1, TEMP2, (SelectedFigList[0]->GetGFXINFO()));
				pManager->AddFigure(pR);
			}
		}
		else
		{
			Output* pOut = pManager->GetOutput();
			Input* pIn = pManager->GetInput();
			pOut->PrintMessage("You can only draw in the drawing area, Click in the drawing area to paste");
			pIn->GetPointClicked(Cx, Cy);
		}
		for (int i = 1; i < SelecFigCount; i++)
		{
			SelectedFigList[i]->Paste(SelectedFigList[i]->getFirstPt().x + Dist.x, SelectedFigList[i]->getFirstPt().y + Dist.y, TEMP1, TEMP2, TEMP3);
			//Checks that the y-coordinate of the clicked point is in the drawing area
			if (TEMP1.y > UI.ToolBarHeight && TEMP1.y <= (UI.height - UI.StatusBarHeight) && TEMP2.y > UI.ToolBarHeight && TEMP2.y <= (UI.height - UI.StatusBarHeight) && TEMP3.y > UI.ToolBarHeight && TEMP3.y <= (UI.height - UI.StatusBarHeight))
			{
				if (dynamic_cast<CRectangle*>(SelectedFigList[i]))
				{
					CRectangle* pR = new CRectangle(TEMP1, TEMP2, (SelectedFigList[i]->GetGFXINFO()));
					pManager->AddFigure(pR);
				}
				else if (dynamic_cast<CLine*>(SelectedFigList[i]))
				{
					CLine* pR= new CLine(TEMP1, TEMP2, (SelectedFigList[i]->GetGFXINFO()));
					pManager->AddFigure(pR);
				}
				else if (dynamic_cast<CTriangle*>(SelectedFigList[i]))
				{
					CTriangle* pR = new CTriangle(TEMP1, TEMP2, TEMP3, (SelectedFigList[i]->GetGFXINFO()));
					pManager->AddFigure(pR);
				}
				else if (dynamic_cast<CCircle*>(SelectedFigList[i]))
				{
					CCircle* pR = new CCircle(TEMP1, TEMP2, (SelectedFigList[i]->GetGFXINFO()));
					pManager->AddFigure(pR);
				}
			}
			else
			{
				Output* pOut = pManager->GetOutput();
				Input* pIn = pManager->GetInput();
				pOut->PrintMessage("You can only draw in the drawing area, Click in the drawing area to paste");
				pIn->GetPointClicked(Cx, Cy);
			}
		}
	}
}