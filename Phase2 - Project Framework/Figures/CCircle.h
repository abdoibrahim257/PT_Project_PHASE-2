 #ifndef CCircle_H
#define CCircle_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	void print(Output* pOut);
	bool checkLoc(int x, int y);
	bool isValid(Point, Point) const;

	Point getFirstPt();
	Point getLastPt();
	void Move(int x, int y);        //Move the figure
	virtual void Paste(int x, int y, Point& temp1, Point& temp2, Point& temp3);  //Function gets the new corner points to be pasted
	void Resize(string scale);					//Resize the figure
	void Save(ofstream& Outfile);	//Save the figure parameters to the file
	//void Load(ifstream& Infile);	//Load the figure parameters to the file
};

#endif