#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;			//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;			//creates Play mode toolbar & menu
	void CreateDrawItemsToolbar() const;	//create draw items toolbar & menu
	void CreateStatusBar() const;			//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolbarArea() const; //Clears the toolbar
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const;	    //Draw a circle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const;        //Draw a line
	void DrawTriangle(Point P1, Point P2, Point p3, GfxInfo TriangleGfxInfo, bool selected) const;  //Draw a triangle
	///Make similar functions for drawing all other figures.
	void PrintInteger(int i) const;
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	color getCrntHightLight() const;
	int getCrntPenWidth() const;		//get current pen width


	~Output();
};

#endif