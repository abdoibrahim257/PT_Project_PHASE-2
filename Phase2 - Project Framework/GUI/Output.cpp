#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1500;
	UI.height = 800;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 70;
	UI.MenuItemWidth = 80;


	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = ORANGE;		//Filling color
	UI.MsgColor = WHITE;		//Messages color
	UI.BkGrndColor = WHITE;	//Background color
	UI.HighlightColor = VIOLET;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = DIMGRAY;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	//pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height, FILLED);
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	ClearToolbarArea();
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_DRAWITEM] = "images\\MenuItems\\Menu_Add.jpg";
	MenuItemImages[ITM_DRAWCOL] = "images\\MenuItems\\Menu_DrawCol.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImages[ITM_BKCOL] = "images\\MenuItems\\Menu_BKCol.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\MenuItems\\Menu_Resize.jpg";
	MenuItemImages[ITM_ZOOMIN] = "images\\MenuItems\\Menu_Zoom_In.jpg";
	MenuItemImages[ITM_ZOOMOUT] = "images\\MenuItems\\Menu_Zoom_Out.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Menu_Del.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\Menu_Play.jpeg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//pWind->SetPen(UI.ToolBarColor, 1); //not working
	//pWind->SetBrush(UI.ToolBarColor); //not working

	//Draw a line under the toolbar
	pWind->SetPen(DIMGREY, 7);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	ClearToolbarArea();
	UI.InterfaceMode = MODE_PLAY;

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_BYTYPE] = "images\\MenuItems\\Menu_By_Type.jpg";
	MenuItemImages[ITM_BYCOLOR] = "images\\MenuItems\\Menu_By_Color.jpg";
	MenuItemImages[ITM_BOTH] = "images\\MenuItems\\Menu_By_Both.jpg";
	MenuItemImages[ITM_BYAREA] = "images\\MenuItems\\Menu_By_Area.jpg";
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\Menu_Draw.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(DIMGREY, 7);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawItemsToolbar() const
{
	ClearToolbarArea();
	UI.InterfaceMode = MODE_ADDITEM;

	string MenuItemImages[ADD_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_LINE] = "images\\menuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_TRIA] = "images\\menuItems\\Menu_Tria.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\Menu_Return.jpg";

	for (int i = 0; i < ADD_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(DIMGREY, 7);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
/// //////////////////////////////////////////////////////////////////////////////////////

void Output::CreateDrawClrToolBar() const
{
	ClearToolbarArea();
	UI.InterfaceMode = MODE_COLORITEM;

	string MenuItemImages[COLOR_ITM_COUNT];
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\Menu_White.jpg";
	MenuItemImages[ITM_BLACK] = "images\\menuItems\\Menu_Black.jpg";
	MenuItemImages[ITM_RED] = "images\\menuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_PURPLE] = "images\\MenuItems\\Menu_Purple.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";

	for (int i = 0; i < COLOR_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(DIMGREY, 7);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

///////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateFillClrToolBar() const
{
	ClearToolbarArea();
	UI.InterfaceMode = MODE_FILLITEM;

	string MenuItemImages[FILL_ITM_COUNT];
	MenuItemImages[fITM_WHITE] = "images\\MenuItems\\Menu_White.jpg";
	MenuItemImages[fITM_BLACK] = "images\\menuItems\\Menu_Black.jpg";
	MenuItemImages[fITM_RED] = "images\\menuItems\\Menu_Red.jpg";
	MenuItemImages[fITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[fITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[fITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[fITM_PURPLE] = "images\\MenuItems\\Menu_Purple.jpg";
	MenuItemImages[fITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";

	for (int i = 0; i < FILL_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(DIMGREY, 7);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}

/////////////////////////////////////////////////////////////////////////////////////////////


void Output::CreateBackClrToolBar() const
{
	ClearToolbarArea();
	UI.InterfaceMode = MODE_BACKCLRITEM;

	string MenuItemImages[BACKCLR_ITM_COUNT];
	MenuItemImages[BITM_WHITE] = "images\\MenuItems\\Menu_White.jpg";
	MenuItemImages[BITM_BLACK] = "images\\menuItems\\Menu_Black.jpg";
	MenuItemImages[BITM_RED] = "images\\menuItems\\Menu_Red.jpg";
	MenuItemImages[BITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[BITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[BITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[BITM_PURPLE] = "images\\MenuItems\\Menu_Purple.jpg";
	MenuItemImages[BITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";

	for (int i = 0; i < BACKCLR_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(DIMGREY, 7);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}



void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 7, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////




void Output::ClearToolbarArea() const
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintInteger(int i) const	//Prints AN INTEGER ANA MEZAWDHA ~ABDO / HASHISH
{
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawInteger(220, UI.height - (int)(UI.StatusBarHeight / 1.5), i);
}


color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;



}color Output::getCrntHightLight() const		//get current pen width
{
	return UI.HighlightColor;
}



//======================================================================================//
//								Figures Drawing Functions		jjj						//
//======================================================================================//

//Draw a rectangle 
void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draw a circle
void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const
{
	double radius = sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = CircGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircGfxInfo.BorderWdth);  //Set drawing color &width 

	drawstyle style;
	if (CircGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircGfxInfo.FillClr); //sets fill shape color according to selection 
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, radius, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draw a line 
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draw a triangle
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
