#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
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
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		//pAct = new AddLineAction(this);
		break;

	case DRAW_TRI:
		//pAct = new AddTriAction(this);
		break;

	case DRAW_CIRC:
		//pAct = new AddCircAction(this);
		break;

	case DRAW_ITEM:	//Draw an item    //MESH 3AREF LEHA LAZMA WLA EH
		//pAct = new AddITEMAction(this);
		break;

	case CHNG_DRAW_CLR: //Change the drawing color
		//pAct = new CHNG_DRAW-CLRAction(this);
		break;

	case CHNG_FILL_CLR:	//Change the filling color
		//pAct = new CHNG_FILL-CLRAction(this);
		break;

	case CHNG_BK_CLR:	//Change background color
		//pAct = new CHNG_BK-CLRAction(this);
		break;

	case SELECT:		//Select an item
		//pAct = SELECTAction(this);
		break;

	case MOVE:			//Move a figure(s)
		//pAct = new MOVEAction(this);
		break;

	case RESIZE:		//Resize a figure(s)
		//pAct = new RESIZEAction(this);
		break;

	case DEL:			//Delete a figure(s)
		//pAct = new DElAction(this);
		break;

	case COPY:           //Copy an item to Clipboard
		//pAct = new COPYAction(this);
		break;

	case PASTE:         //Paste an item from Clipboard
		//pAct = new PASTEAction(this);
		break;

	case CUT:            //Cut an item and have it in Clipboard
		//pAct = new CUTAction(this);
		break;

	case SAVE:			//Save the whole graph to a file
		//pAct = new SAVEAction(this);
		break;

	case LOAD:			//Load a graph from a file
		//pAct = new LOADAction(this);
		break;

	case ZOOM_IN:        //Zooming the whole graph in
		//pAct = new Zoom_INAction(this);
		break;

	case ZOOM_OUT:       //Zooming the whole graph out
		//pAct = new Zoom_OUTAction(this);
		break;

	case EXIT:			//Exit the application
		//pAct = new EXITAction(this);
		break;
		
	case STATUS:	//a click on the status bar ==> no action
		return;
	}
	
	//Execute the created action
	if(pAct != NULL)
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
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const // ll select
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
