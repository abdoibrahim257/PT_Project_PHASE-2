#include "CRectangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::print(Output* pOut)
{
	int width = Corner2.x - Corner1.x;
	if (width < 0) { width *= -1; }
	
	int length= Corner2.y - Corner1.y;
	if (length < 0) { length *= -1; }

	string strl;
	strl = "Figure ID: ";
	strl += to_string(MYid);
	strl += " - Corner 1: (";
	strl += to_string(Corner1.x);
	strl += ", ";
	strl += to_string(Corner1.y);
	strl += ") - Corner 2: (";
	strl += to_string(Corner2.x);
	strl += ", ";
	strl += to_string(Corner2.y);
	strl += ") - Length: ";
	strl += to_string(length);
	strl += " - Width: ";
	strl += to_string(width);
	strl += " - Area: ";
	strl += to_string(length*width);

	pOut->PrintMessage(strl);
}


bool CRectangle::checkLoc(int x, int y)
{
	if ( ((Corner1.x <= x && x <= Corner2.x) || (Corner2.x <= x && x <= Corner1.x)) && ((Corner1.y <=y && y<= Corner2.y) || (Corner2.y <=y && y<= Corner1.y)) )
	{
		return true;
	}
	else return false;

}