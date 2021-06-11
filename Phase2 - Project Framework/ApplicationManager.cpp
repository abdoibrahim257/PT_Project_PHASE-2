#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\SelectAction.h"
#include "Actions/CopyAction.h"
#include "Actions/PasteAction.h"
#include "Actions\MoveAction.h"
#include "Actions\ResizeAction.h"
#include "Actions\DeleteAction.h"
#include "Actions/SaveAction.h"
#include "Actions/LoadAction.h"
#include "Figures/CCircle.h"
#include "Figures/CRectangle.h"
#include "Figures/CLine.h"
#include "Figures/CTriangle.h"
#include "Actions\DrwColorAction.h"
#include "Actions\FillclrAction.h"
#include "Actions\BackGrndClrAction.h"
#include "DEFS.h"
#include "CMUgraphicsLib/CMUgraphics.h"







int CFigure::ID = 0;

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	filled = false;
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelecFigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;

	for (int i = 0; i < MaxSelecCount; i++)
	{
		SelectedFigList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this, filled);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriAction(this, filled);
		break;

	case DRAW_CIRC:
		pAct = new AddCircAction(this, filled);
		break;

	case CHNG_DRAW_CLR: //Change the drawing color
		pOut->CreateDrawClrToolBar();
		pAct = new DrwColorAction(this);
		break;
		//case colors for change DRAW COLOR 
			///////////////////////////////////////////////////////////////////////////////

	case COLOR_WHITE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = WHITE;
		break;

	case COLOR_BLACK:
		pOut->CreateDrawToolBar();
		UI.DrawColor = BLACK;
		break;

	case COLOR_RED:
		pOut->CreateDrawToolBar();
		UI.DrawColor = RED;
		break;

	case COLOR_GREEN:
		pOut->CreateDrawToolBar();
		UI.DrawColor = GREEN;
		break;

	case COLOR_BLUE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = BLUE;
		break;

	case COLOR_YELLOW:
		pOut->CreateDrawToolBar();
		UI.DrawColor = YELLOW;
		break;

	case COLOR_PURPLE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = PURPLE;
		break;

	case COLOR_ORANGE:
		pOut->CreateDrawToolBar();
		UI.DrawColor = ORANGE;
		break;

		/////////////////////////////////////////////////////////////////////////////////

	case CHNG_FILL_CLR:	//Change the filling color
		pOut->CreateFillClrToolBar();
		filled = true;
		pAct = new FillClrAction(this);
		break;

	case FILL_WHITE:
		pOut->CreateDrawToolBar();
		UI.FillColor = WHITE;
		break;

	case FILL_BLACK:
		pOut->CreateDrawToolBar();
		UI.FillColor = BLACK;
		break;

	case FILL_RED:

		pOut->CreateDrawToolBar();
		UI.FillColor = RED;
		break;

	case FILL_GREEN:
		pOut->CreateDrawToolBar();
		UI.FillColor = GREEN;
		break;

	case FILL_BLUE:
		pOut->CreateDrawToolBar();
		UI.FillColor = BLUE;
		break;

	case FILL_YELLOW:
		pOut->CreateDrawToolBar();
		UI.FillColor = YELLOW;
		break;

	case FILL_PURPLE:
		pOut->CreateDrawToolBar();
		UI.FillColor = PURPLE;
		break;

	case FILL_ORANGE:
		pOut->CreateDrawToolBar();
		UI.FillColor = ORANGE;
		break;
		////////////////////////////////////////////////////////////////////////////////////////////////////


	case CHNG_BK_CLR:	//Change background color
		pOut->CreateBackClrToolBar();
		pAct = new BackGrndClrAction(this);
		break;

	case BCFILL_WHITE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = WHITE;
		pOut->ClearDrawArea();

		break;

	case BCFILL_BLACK:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = BLACK;
		pOut->ClearDrawArea();
		break;

	case BCFILL_RED:

		pOut->CreateDrawToolBar();
		UI.BkGrndColor = RED;
		pOut->ClearDrawArea();
	

		break;

	case BCFILL_GREEN:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = GREEN;
		pOut->ClearDrawArea();
		break;

	case BCFILL_BLUE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = BLUE;
		pOut->ClearDrawArea();
		break;

	case BCFILL_YELLOW:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = YELLOW;
		pOut->ClearDrawArea();
		break;

	case BCFILL_PURPLE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = PURPLE;
		pOut->ClearDrawArea();
		break;

	case BCFILL_ORANGE:
		pOut->CreateDrawToolBar();
		UI.BkGrndColor = ORANGE;
		pOut->ClearDrawArea();

		break;
	case SELECT:		//Select an item
		pAct = new SelectAction(this);
		break;

	case MOVE:			//Move a figure(s)
		pAct = new MoveAction(this);
		break;

	case RESIZE:		//Resize a figure(s)
		pAct = new ResizeAction(this);
		break;

	case DEL:			//Delete a figure(s)
		deleteFig();
		pOut->ClearDrawArea();
		pOut->ClearStatusBar();
		pOut->PrintMessage("Figure(s) Deleted succesfully");
		break;

	case COPY:           //Copy an item to Clipboard
		pAct = new CopyAction(this);
		break;

	case PASTE:         //Paste an item from Clipboard
		pAct = new PasteAction(this);
		break;

	case CUT:            //Cut an item and have it in Clipboard
		//pAct = new CUTAction(this);
		break;

	case SAVE:			//Save the whole graph to a file
		pAct = new SaveAction(this);
		break;

	case LOAD:			//Load a graph from a file
		pAct = new LoadAction(this);
		break;

	case ZOOM_IN:        //Zooming the whole graph in
		//pAct = new Zoom_INAction(this);
		break;

	case ZOOM_OUT:       //Zooming the whole graph out
		//pAct = new Zoom_OUTAction(this);
		break;

	case TO_ADDITEM:
		pOut->CreateDrawItemsToolbar();
		break;

	case EXIT:			//Exit the application
		//pAct = new EXITAction(this);
		break;

	case STATUS:	//a click on the status bar ==> no action
		return;

	case DRAWING_AREA:    //a click on the drawing area ==> no action   
		break;

	case EMPTY:    //a click on an empty area in the designed tool bar ==> no action
		break;

	case TO_PLAY:    //Switch to Play Mode, creating Play tool bar
		pOut->CreatePlayToolBar();
		break;

	case TO_DRAW:    //Switch to Draw Mode, creating Draw tool bar
		pOut->CreateDrawToolBar();
		break;

	case BY_TYPE:    //Pick figures by Type, for play mode
		break;

	case BY_COLOR:    //Pick figures by Color, for play mode
		break;

	case BY_BOTH:    //Pick figures by both Type and Color, for play mode
		break;

	case BY_AREA:    //Pick figures by Area, for play mode
		break;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::printinfo(CFigure* pI)
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		if (SelecFigCount == 1)
		{
			SelectedFigList[i]->print(pOut);
		}
		else if (SelecFigCount > 1)
		{
			pOut->PrintMessage("Number of selected figure: ");
			pOut->PrintInteger(SelecFigCount);
		}

	}
}

///////////////////////////////////////////////////////////////////////////////////////
// Add a selected figure to an array 
void ApplicationManager::AddSelectedFigure(CFigure* s)
{
	if (SelecFigCount < MaxSelecCount)
		SelectedFigList[SelecFigCount++] = s;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* *ApplicationManager::GetSelectedFigs()
{
	return SelectedFigList;
}

int ApplicationManager::GetSelectedCount()
{
	return SelecFigCount;
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}
void ApplicationManager::UNSelectFigure(CFigure* s)
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		if (SelectedFigList[i] == s) //[1 2 3 ]4 ] 
		{
			SelectedFigList[i] = SelectedFigList[SelecFigCount - 1];
			SelectedFigList[SelecFigCount - 1] = NULL;
			SelecFigCount--;
			break;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////

CFigure* ApplicationManager::GetFigure(int x, int y) const // ll select
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = 0; i < FigCount; i++)
	{
		CFigure* C = dynamic_cast<CRectangle*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

		C = dynamic_cast<CCircle*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

		C = dynamic_cast<CTriangle*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

		C = dynamic_cast<CLine*>(FigList[i]);
		if (C != NULL)
		{
			if (FigList[i]->checkLoc(x, y))
				return FigList[i];
		}

	}

	///Add your code here to search for a figure given a point x,y	

	return NULL;
}


void ApplicationManager::deleteFig()
{
	int k = 0;
	for (int i = 0; i < MaxFigCount; i++)
	{
		if (!FigList[i - k])
		{
			break;
		}
		if (FigList[i - k]->IsSelected())
		{
			clearselcFig();
			delete FigList[i - k];
			FigList[i - k] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			k++;
		}
	}
}




//==================================================================================//
//								Save Related Functions								//
//==================================================================================//

void ApplicationManager::SaveAll(ofstream& Outfile)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(Outfile); //Call Save Function
	}
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}

//////////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::clearselcFig()
{
	for (int i = 0; i < SelecFigCount; i++)
	{
		SelectedFigList[i] = NULL;
	}
	SelecFigCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < SelecFigCount; i++)
		delete SelectedFigList[i];
	delete pIn;
	delete pOut;

}

//=================================================================================//
//                 Clipboard used for Copy, Cut & Paste Functions                  //
//=================================================================================//
void ApplicationManager::SetClipboard(CFigure** fig)
{
	IsInClipboard = true;
	Clipboard = fig;
}
CFigure** ApplicationManager::GetClipboard()
{
	if (IsInClipboard)
		return Clipboard;
	else
		return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetIsFigCut(bool b)
{
	IsFigCut = b;
}
////////////////////////////////////////////////////////////////////
bool ApplicationManager::GetIsFigCut()
{
	return IsFigCut;
}