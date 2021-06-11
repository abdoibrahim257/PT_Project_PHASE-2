#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for all figures
class CFigure
{
protected:
	int MYid;		//Each figure has an ID
	bool Selected = false;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	static int ID;
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	int getID();
	void SetID(int);
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual void print(Output* pOut);
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void HighLightClr();	//changes the figure's filling color
	string GetColorName(color RGB);		//Gets the name of a color (save)
	color GetColor(string RGB);			//Gets the color from its name (load)
	virtual bool checkLoc(int x, int y);
	virtual GfxInfo GetGFXINFO();  //Gets graphical info

	virtual Point getFirstPt() = 0;
	virtual Point getLastPt() = 0;
	virtual void Move(int x, int y) = 0;        //Move the figure
	virtual void Paste(int x, int y, Point& temp1, Point& temp2, Point& temp3)=0;  //Function gets the new corner points to be pasted
	virtual void Resize(string scale) = 0;					//Resize the figure

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure


	virtual void Save(ofstream &Outfile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif