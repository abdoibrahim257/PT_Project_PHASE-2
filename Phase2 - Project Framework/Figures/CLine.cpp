#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	StartingPoint = P1;
	EndPoint = P2;
}


void CLine::Draw(Output* pOut) const
{
	bool x = isValid(StartingPoint, EndPoint);
	if (x)
	{
		pOut->DrawLine(StartingPoint, EndPoint, FigGfxInfo, Selected);
	}
	else pOut->PrintMessage("Invalid Drawing Area Please try again");
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

bool CLine::isValid(Point p1, Point p2) const
{
	if (((p1.y < UI.ToolBarHeight) || (p1.y > (UI.height - UI.StatusBarHeight))) || (((p2.y < UI.ToolBarHeight) || (p2.y > (UI.height - UI.StatusBarHeight)))))
	{
		return false;
	}
	else if ((p1.x<0 || p1.x >UI.width) || (p2.x<0 || p2.x>UI.width))
	{
		return false;
	}
	else return true;
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

void CLine::Move(int x, int y)
{
	EndPoint.x = x - StartingPoint.x + EndPoint.x; EndPoint.y = y - StartingPoint.y + EndPoint.y;
	StartingPoint.x = x; StartingPoint.y = y;
}

void CLine::Paste(int x, int y, Point& temp1, Point& temp2, Point& temp3)
{
	temp2.x = x - StartingPoint.x + EndPoint.x; temp2.y = y - StartingPoint.y + EndPoint.y;
	temp1.x = x; temp1.y = y;
}

Point CLine::getFirstPt()
{
	Point P;
	P.x = StartingPoint.x;
	P.y = StartingPoint.y;
	return P;
}

Point CLine::getLastPt()
{
	Point P;
	P.x = EndPoint.x;
	P.y = EndPoint.y;
	return P;
}

void CLine::Resize(string scale)
{

	if (scale == "1/4" || scale == "quarter")
	{
		EndPoint.x = (EndPoint.x - StartingPoint.x) / 4 + StartingPoint.x;
		EndPoint.y = (EndPoint.y - StartingPoint.y) / 4 + StartingPoint.y;
	}
	else if (scale == "1/2" || scale == "half")
	{
		EndPoint.x = (EndPoint.x - StartingPoint.x) / 2 + StartingPoint.x;
		EndPoint.y = (EndPoint.y - StartingPoint.y) / 2 + StartingPoint.y;
	}
	else if (scale == "2" || scale == "double")
	{
		EndPoint.x = (EndPoint.x - StartingPoint.x) * 2 + StartingPoint.x;
		EndPoint.y = (EndPoint.y - StartingPoint.y) * 2 + StartingPoint.y;
	}
	else if (scale == "4" || scale == "quadruple")
	{
		EndPoint.x = (EndPoint.x - StartingPoint.x) * 4 + StartingPoint.x;
		EndPoint.y = (EndPoint.y - StartingPoint.y) * 4 + StartingPoint.y;
	}
}

void CLine::Save(ofstream& Outfile)
{
	string DrawClr = GetColorName(FigGfxInfo.DrawClr);
	Outfile << "LINE\t" << MYid << "\t" << StartingPoint.x << "\t" << StartingPoint.y << "\t" << EndPoint.x << "\t";
	Outfile << EndPoint.y << "\t" << DrawClr << "\n";
}
void CLine::Load(ifstream& Infile)
{
	string draw_clr;
	string fill;
	Infile >> MYid >> StartingPoint.x >> StartingPoint.y >> EndPoint.x >> EndPoint.y;
	Infile >> draw_clr;
	FigGfxInfo.DrawClr = GetColor(draw_clr);
}
