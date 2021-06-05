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

int CFigure::getID()
{	return ID;	}

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


