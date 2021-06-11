#include "SaveAction.h"
#include "../ApplicationManager.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please enter the name of the file you wish to save into: ");
	Filename = pIn->GetString(pOut) + ".txt";
	Outfile.open(Filename);
	if (Outfile.is_open())
	{
		pOut->PrintMessage("Your file has been Saved Successfully");
	}
	else {
		pOut->PrintMessage("Unable to save file");
	}
}

void SaveAction::Execute()
{
	ReadActionParameters();
	if (Outfile.is_open())
	{
		string Draw_Clr, Fill_Clr, BK_Clr;
		int NumOfFigs;
		Draw_Clr = GetColorName(UI.DrawColor);
		Fill_Clr = GetColorName(UI.FillColor);
		BK_Clr = GetColorName(UI.BkGrndColor);
		NumOfFigs = pManager->GetFigCount();
		Outfile << Draw_Clr << "\t" << Fill_Clr << "\t" << BK_Clr << "\n";
		Outfile << NumOfFigs << "\n";
		pManager->SaveAll(Outfile);
		Outfile.close();
	}
	
	
}

string SaveAction::GetColorName(color RGB)
{
	if (RGB.ucRed == 0 && RGB.ucGreen == 0 && RGB.ucBlue == 0)
	return "BLACK";
	else if (RGB.ucRed == 255 && RGB.ucGreen == 255 && RGB.ucBlue == 255)
		return "WHITE";
	else if (RGB.ucRed == 255 && RGB.ucGreen == 0 && RGB.ucBlue == 0)
		return "RED";
	else if (RGB.ucRed == 0 && RGB.ucGreen == 255 && RGB.ucBlue == 0)
		return "GREEN";
	else if (RGB.ucRed == 0 && RGB.ucGreen == 0 && RGB.ucBlue == 255)
		return "BLUE";
	else if (RGB.ucRed == 255 && RGB.ucGreen == 255 && RGB.ucBlue == 0)
		return "YELLOW";
	else if (RGB.ucRed == 160 && RGB.ucGreen == 32 && RGB.ucBlue == 240)
		return "PURPLE";
	else if (RGB.ucRed == 255 && RGB.ucGreen == 165 && RGB.ucBlue == 0)
		return "ORANGE";
}