#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	MYid = ++ID;
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::print(Output* pOut)
{}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::SetID(int id)
{
	ID = id;
}


int CFigure::getID()
{
	return MYid;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure::HighLightClr()
{
	FigGfxInfo.HighLightClr = VIOLET;
}


bool CFigure::checkLoc(int x, int y)
{
	return true;
}
GfxInfo CFigure::GetGFXINFO()
{
	return FigGfxInfo;
}

string CFigure::GetColorName(color RGB)
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
 color CFigure::GetColor(string RGB)
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

