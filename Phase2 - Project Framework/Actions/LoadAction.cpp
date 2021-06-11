#include "LoadAction.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CLine.h"
#include "../ApplicationManager.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please enter the name of the file you wish to load from: ");
	Filename = pIn->GetString(pOut) + ".txt";
	Infile.open(Filename);
	if (Infile.is_open())
	{
		pOut->PrintMessage("Your file has been Loaded Successfully");
	}
	else {
		pOut->PrintMessage("Unable to load file");
	}
}

void LoadAction::Execute()
{
	ReadActionParameters();
	if (Infile.is_open())
	{
		string Draw_Clr, Fill_Clr, BK_Clr;
		int NumOfFigs;
		Infile >> Draw_Clr >> Fill_Clr >> BK_Clr >> NumOfFigs;
		UI.DrawColor = GetColor(Draw_Clr);
		UI.FillColor = GetColor(Fill_Clr);
		UI.BkGrndColor = GetColor(BK_Clr);
		for (int i = 0; i < NumOfFigs; i++)
		{
			CFigure* pFig;
			string Shape;
			Infile >> Shape;
			Point Dummy_PT1, Dummy_PT2, Dummy_PT3;
			Dummy_PT1.x = 0; Dummy_PT1.y = 0; Dummy_PT2.x = 0; Dummy_PT2.y = 0; Dummy_PT3.x = 0; Dummy_PT3.y = 0;
			GfxInfo Dummy_GFX;
			Dummy_GFX.BorderWdth=3; Dummy_GFX.DrawClr = BLACK; Dummy_GFX.FillClr = BLUE; Dummy_GFX.isFilled = true; Dummy_GFX.HighLightClr = RED;

			if (Shape == "CIRCLE")
				pFig = new CCircle(Dummy_PT1, Dummy_PT2, Dummy_GFX);
			else if (Shape == "LINE")
				pFig = new CLine(Dummy_PT1, Dummy_PT2, Dummy_GFX);
			else if (Shape == "RECT")
				pFig = new CRectangle(Dummy_PT1, Dummy_PT2, Dummy_GFX);
			else if (Shape == "TRIANG")
				pFig = new CTriangle(Dummy_PT1, Dummy_PT2, Dummy_PT3, Dummy_GFX);

			pManager->AddFigure(pFig);
			pFig->Load(Infile);
		}
		Output* pOut= pManager->GetOutput();
		pOut->ClearDrawArea();
	}
}

color LoadAction::GetColor(string RGB)
{
	if (RGB == "BLACK")
		return BLACK;
	else if (RGB == "WHITE")
		return WHITE;
	else if (RGB == "RED")
		return RED;
	else if (RGB == "GREEN")
		return GREEN;
	else if (RGB == "BLUE")
		return BLUE;	
	else if (RGB == "YELLOW")
		return YELLOW;
	else if (RGB == "PURPLE")
		return PURPLE;
	else if (RGB == "ORANGE")
		return ORANGE;
}