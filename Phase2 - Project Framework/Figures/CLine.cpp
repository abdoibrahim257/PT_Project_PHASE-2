#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	StartingPoint = P1;
	EndPoint = P2;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(StartingPoint, EndPoint, FigGfxInfo, Selected);
}


void CLine::print(Output* pOut)
{
	int length = sqrt((StartingPoint.x - EndPoint.x) * (StartingPoint.x - EndPoint.x) + (StartingPoint.y - EndPoint.y) * (StartingPoint.y - EndPoint.y));

	string strl;
	strl = "Figure ID: ";
	strl += to_string(MYid);
	strl += " -  Starting Point: (";
	strl += to_string(StartingPoint.x);
	strl += ", ";
	strl += to_string(StartingPoint.y);
	strl += ") - End Point: (";
	strl += to_string(EndPoint.x);
	strl += ", ";
	strl += to_string(EndPoint.y);
	strl += ") - Length: ";
	strl += to_string(length);


	pOut->PrintMessage(strl);
}


bool CLine::checkLoc(int x, int y)
{
	float check1 = sqrt(((x)-StartingPoint.x) * ((x)-StartingPoint.x) + ((y)-StartingPoint.y) * ((y)-StartingPoint.y));
	float check2 = sqrt(((x)-EndPoint.x) * ((x)-EndPoint.x) + ((y)-EndPoint.y) * ((y)-EndPoint.y));
	float line = sqrt((StartingPoint.x - EndPoint.x) * (StartingPoint.x - EndPoint.x) + (StartingPoint.y - EndPoint.y) * (StartingPoint.y - EndPoint.y));
	if (((check1 + check2) <= (line + 10)) && ((check1 + check2) >= (line - 10)))
	{
		return true;
	}
	else return false;
}