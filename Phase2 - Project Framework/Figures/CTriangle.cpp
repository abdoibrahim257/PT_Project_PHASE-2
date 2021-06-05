#include "CTriangle.h"


CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}


void CTriangle::print(Output* pOut)
{
	string strl;
	strl = "Figure ID: ";
	strl += to_string(MYid);
	strl += " Corner1: (";
	strl += to_string(Corner1.x);
	strl += ", ";
	strl += to_string(Corner1.y);
	strl += ") Corner2: (";
	strl += to_string(Corner2.x);
	strl += ", ";
	strl += to_string(Corner2.y);
	strl += ") Corner3: (";
	strl += to_string(Corner3.x);
	strl += ", ";
	strl += to_string(Corner3.y);
	strl += ") Area: ";
	strl += to_string(getarea(Corner1, Corner2, Corner3.x, Corner3.y));

	
	pOut->PrintMessage(strl);
}

float CTriangle::getarea(Point C1, Point C2, int x, int y)
{
	
	float A = (0.5)*abs(C1.x*(C2.y-y) + C2.x*(y-C1.y) + x*(C1.y-C2.y));
	return A;
}

bool CTriangle::checkLoc(int x, int y)
{
    float radius;
    int    Centerx, Centery;
	float a = getarea(Corner1, Corner2, x, y);
	float b= getarea(Corner1, Corner3, x, y);
	float c= getarea(Corner2, Corner3, x, y);
	float d= getarea(Corner1, Corner2, Corner3.x, Corner3.y);
	if ((a + b + c) == d)
	{
		return true;
	}
	else return false;
	
}

