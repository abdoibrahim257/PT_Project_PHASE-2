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
	bool x = isValid(Corner1, Corner2, Corner3);
	if (x)
	{
		pOut->DrawTriangle(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
	}
	else pOut->PrintMessage("Invalid Drawing Area Please try again");
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

	float A = (0.5) * abs(C1.x * (C2.y - y) + C2.x * (y - C1.y) + x * (C1.y - C2.y));
	return A;
}

bool CTriangle::checkLoc(int x, int y)
{
	float radius;
	int    Centerx, Centery;
	float a = getarea(Corner1, Corner2, x, y);
	float b = getarea(Corner1, Corner3, x, y);
	float c = getarea(Corner2, Corner3, x, y);
	float d = getarea(Corner1, Corner2, Corner3.x, Corner3.y);
	if ((a + b + c) == d)
	{
		return true;
	}
	else return false;

}


void CTriangle::Move(int x, int y)
{
	Corner3.x = x - Corner1.x + Corner3.x; Corner3.y = y - Corner1.y + Corner3.y;
	Corner2.x = x - Corner1.x + Corner2.x; Corner2.y = y - Corner1.y + Corner2.y;
	Corner1.x = x; Corner1.y = y;
}

void CTriangle::Paste(int x, int y, Point& temp1, Point& temp2, Point& temp3)
{
	temp3.x = x - Corner1.x + Corner3.x; temp3.y = y - Corner1.y + Corner3.y;
	temp2.x = x - Corner1.x + Corner2.x; temp2.y = y - Corner1.y + Corner2.y;
	temp1.x = x; temp1.y = y;
}

Point CTriangle::getFirstPt()
{
	Point P;
	P.x = Corner1.x;
	P.y = Corner1.y;
	return P;
}

Point CTriangle::getLastPt()
{
	Point P;
	P.x = Corner3.x;
	P.y = Corner3.y;
	return P;
}

void CTriangle::Resize(string scale)
{
	if (scale == "1/4" || scale == "quarter")
	{
		Corner2.x = (Corner2.x - Corner1.x) / 4 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) / 4 + Corner1.y;
		Corner3.x = (Corner3.x - Corner1.x) / 4 + Corner1.x;
		Corner3.y = (Corner3.y - Corner1.y) / 4 + Corner1.y;
	}
	else if (scale == "1/2" || scale == "half")
	{
		Corner2.x = (Corner2.x - Corner1.x) / 2 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) / 2 + Corner1.y;
		Corner3.x = (Corner3.x - Corner1.x) / 2 + Corner1.x;
		Corner3.y = (Corner3.y - Corner1.y) / 2 + Corner1.y;
	}
	else if (scale == "2" || scale == "double")
	{
		Corner2.x = (Corner2.x - Corner1.x) * 2 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 2 + Corner1.y;
		Corner3.x = (Corner3.x - Corner1.x) * 2 + Corner1.x;
		Corner3.y = (Corner3.y - Corner1.y) * 2 + Corner1.y;
	}
	else if (scale == "4" || scale == "quadruple")
	{
		Corner2.x = (Corner2.x - Corner1.x) * 4 + Corner1.x;
		Corner2.y = (Corner2.y - Corner1.y) * 4 + Corner1.y;
		Corner3.x = (Corner3.x - Corner1.x) * 4 + Corner1.x;
		Corner3.y = (Corner3.y - Corner1.y) * 4 + Corner1.y;
	}
}

void CTriangle::Save(ofstream& Outfile)
{
	string DrawClr = GetColorName(FigGfxInfo.DrawClr);
	Outfile << "TRIANG\t" << MYid << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t";
	Outfile << Corner2.y << "\t" << Corner3.x << "\t" << Corner3.y << "\t" << DrawClr << "\t";
	if (FigGfxInfo.isFilled)
	{
		string FillClr = GetColorName(FigGfxInfo.FillClr);
		Outfile << FillClr << "\n";
	}
	else
	{
		Outfile << "NO_FILL\n";
	}
}



bool CTriangle::isValid(Point p1, Point p2, Point p3) const
{
	if ((p1.x<0 || p1.x>UI.width) || (p2.x<0 || p2.x>UI.width) || (p3.x<0 || p3.x>UI.width))
	{
		return false;
	}
	else if ((p1.y<UI.ToolBarHeight || p1.y >(UI.height - UI.StatusBarHeight)) || (p2.y<UI.ToolBarHeight || p2.y >(UI.height - UI.StatusBarHeight)) || (p3.y<UI.ToolBarHeight || p3.y >(UI.height - UI.StatusBarHeight)))
	{
		return false;
	}
	else return true;
}



void CTriangle::Load(ifstream& Infile)
{
	string draw_clr;
	string fill;
	Infile >> MYid >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
	Infile >> draw_clr >> fill;
	FigGfxInfo.DrawClr = GetColor(draw_clr);
	if (fill == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.FillClr = GetColor(fill);
	}
}