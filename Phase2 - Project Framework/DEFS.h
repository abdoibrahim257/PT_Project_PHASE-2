#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	DRAW_ITEM,		//Draw an item
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	SELECT,			//Select an item
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	DEL,			//Delete a figure(s)
	COPY,           //Copy an item to Clipboard
	PASTE,          //Paste an item from Clipboard
	CUT,            //Cut an item and have it in Clipboard
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	ZOOM_IN,        //Zooming the whole graph in
	ZOOM_OUT,       //Zooming the whole graph out
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	TO_ADDITEM,		//Switch interface to Add item mode

	BY_TYPE,            //Pick the same shapes
	BY_COLOR,			//Pick the same colour
	BY_BOTH,			//Pick the same shapes and colour
	BY_AREA,            //Pick the largest(smallest) area and so on
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif