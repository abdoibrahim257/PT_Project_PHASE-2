#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
		{
			return Label;
		}
		if (Key == 8)	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_DRAWITEM: return TO_ADDITEM;
			case ITM_DRAWCOL: return CHNG_DRAW_CLR;
			case ITM_FILL: return CHNG_FILL_CLR;
			case ITM_BKCOL: return CHNG_BK_CLR;
			case ITM_SELECT: return SELECT;
			case ITM_MOVE: return MOVE;
			case ITM_RESIZE: return RESIZE;
			case ITM_DEL: return DEL;
			case ITM_COPY: return COPY;
			case ITM_PASTE: return PASTE;
			case ITM_CUT: return CUT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_ZOOMIN: return ZOOM_IN;
			case ITM_ZOOMOUT: return ZOOM_OUT;
			case ITM_PLAY: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_ADDITEM)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_LINE: return DRAW_LINE;
			case ITM_TRIA: return DRAW_TRI;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_BACK: return TO_DRAW;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)                        //GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_BYTYPE: return BY_TYPE;
			case ITM_BYCOLOR: return BY_COLOR;
			case ITM_BOTH: return BY_BOTH;
			case ITM_BYAREA: return BY_AREA;
			case ITM_DRAW: return TO_DRAW;

			default: return EMPTY;	//A click on empty place in design toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_COLORITEM)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			int ClickedItemOrder = (x / UI.MenuItemWidth);


			switch (ClickedItemOrder)
			{
			case ITM_WHITE: return COLOR_WHITE;
			case ITM_BLACK: return COLOR_BLACK;
			case ITM_RED: return COLOR_RED;
			case ITM_GREEN: return COLOR_GREEN;
			case ITM_BLUE: return COLOR_BLUE;
			case ITM_YELLOW: return COLOR_YELLOW;
			case ITM_PURPLE: return COLOR_PURPLE;
			case ITM_ORANGE: return COLOR_ORANGE;

			default: return EMPTY;	//A click on empty place in design toolbar
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_FILLITEM)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			int ClickedItemOrder = (x / UI.MenuItemWidth);


			switch (ClickedItemOrder)
			{
			case fITM_WHITE: return FILL_WHITE;
			case fITM_BLACK: return FILL_BLACK;
			case fITM_RED: return FILL_RED;
			case fITM_GREEN: return FILL_GREEN;
			case fITM_BLUE: return FILL_BLUE;
			case fITM_YELLOW: return FILL_YELLOW;
			case fITM_PURPLE: return FILL_PURPLE;
			case fITM_ORANGE: return FILL_ORANGE;

			default: return EMPTY;	//A click on empty place in design toolbar
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_BACKCLRITEM)
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case BITM_WHITE: return BCFILL_WHITE;
			case BITM_BLACK: return BCFILL_BLACK;
			case BITM_RED: return BCFILL_RED;
			case BITM_GREEN: return BCFILL_GREEN;
			case BITM_BLUE: return BCFILL_BLUE;
			case BITM_YELLOW: return BCFILL_YELLOW;
			case BITM_PURPLE: return BCFILL_PURPLE;
			case BITM_ORANGE: return BCFILL_ORANGE;

			default: return EMPTY;	//A click on empty place in design toolbar
			}

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		return STATUS;
	}
	///TODO:
	//perform checks similar to Draw mode checks above
	//and return the correspoding action
}
/////////////////////////////////

Input::~Input()
{
}
