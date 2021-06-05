#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->DrawCirc(Center, Radius, FigGfxInfo, Selected);
}


void CCircle::print(Output* pOut)
{
	float radius = sqrt((Center.x - Radius.x) * (Center.x - Radius.x) + (Center.y - Radius.y) * (Center.y - Radius.y));
	int Area = 3.14 * (radius)*(radius);

	string strl;
	strl = "Figure ID: ";
	strl += to_string(MYid);
	strl += "  Center: (";
	strl += to_string(Center.x);
	strl += ", ";
	strl += to_string(Center.y);
	strl += ")  Radius: ";
	strl += to_string(radius);
	strl += "  Area: ";
	strl += to_string(Area);
	

	pOut->PrintMessage(strl);
}


bool CCircle::checkLoc(int x, int y)
{
	double radius = sqrt((Center.x - Radius.x) * (Center.x - Radius.x) + (Center.y - Radius.y) * (Center.y - Radius.y));
	double check = sqrt((x - Center.x) * (x - Center.x) + (y - Center.y) * (y - Center.y));
	if (check <= radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}