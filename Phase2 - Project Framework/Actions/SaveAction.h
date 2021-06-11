#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include <fstream>

class SaveAction : public Action
{
	ofstream Outfile;
	string Filename;
	string GetColorName(color RGB);

public:
	SaveAction(ApplicationManager* pApp);	//Constructor
	~SaveAction();							//Destructor
	
	//Reads parameters needed for the execution
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();
};