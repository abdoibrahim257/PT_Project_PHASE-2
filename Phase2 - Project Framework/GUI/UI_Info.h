#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,			//Drawing mode (startup mode)
	MODE_PLAY,			//Playing mode
	MODE_ADDITEM,		//Add an item
	MODE_COLORITEM,		//change color
	MODE_FILLITEM,
	MODE_BACKCLRITEM,
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_DRAWITEM,	//Add items
	ITM_DRAWCOL,	//Change Draw color in menu
	ITM_FILL,		//Change fill color in menu
	ITM_BKCOL,		//Change background color in menu
	ITM_SELECT,		//Select Shape
	ITM_RESIZE,		//Resize a drawing area item in menu
	ITM_ZOOMIN,     //Zoom in item in menu
	ITM_ZOOMOUT,    //Zoom out item in menu
	ITM_MOVE,		//Move item in the drawing area in menu
	ITM_DEL,		//Delete an item
	ITM_COPY,       //Copy item in menu
	ITM_PASTE,      //Paste item in menu
	ITM_CUT,        //Cut item in menu
	ITM_SAVE,       //Save item in menu
	ITM_LOAD,       //Load item in menu
	ITM_PLAY,       //Go to Play toolbar in menu
	ITM_EXIT,		//Exit item



	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_BYTYPE,         //pick the same shapes
	ITM_BYCOLOR,	    //pick the same colour
	ITM_BOTH,			//pick the same shapes and colour
	ITM_BYAREA,         //Pick the largest(smallest) area and so on
	ITM_DRAW,           //Go to Draw toolbar in menu
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum DrawFigureItem	//Items of figure list
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_RECT,		//Draw a rectangle
	ITM_LINE,		//Draw a line
	ITM_TRIA,		//Draw a triangle
	ITM_CIRC,		//Draw a circle
	ITM_BACK,		//Return to draw item
	ADD_ITM_COUNT	//no. of "draw item" items

};

enum ChngDrwColor
{

	ITM_WHITE,
	ITM_BLACK,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,
	ITM_YELLOW,
	ITM_PURPLE,
	ITM_ORANGE,

	COLOR_ITM_COUNT

};

enum ChngFillColor
{

	fITM_WHITE,
	fITM_BLACK,
	fITM_RED,
	fITM_GREEN,
	fITM_BLUE,
	fITM_YELLOW,
	fITM_PURPLE,
	fITM_ORANGE,

	FILL_ITM_COUNT

};
enum ChngBackColor
{

	BITM_WHITE,
	BITM_BLACK,
	BITM_RED,
	BITM_GREEN,
	BITM_BLUE,
	BITM_YELLOW,
	BITM_PURPLE,
	BITM_ORANGE,

	BACKCLR_ITM_COUNT

};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif