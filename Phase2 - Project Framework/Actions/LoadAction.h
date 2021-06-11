#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include <fstream>

class LoadAction : public Action
{
	ifstream Infile;
	string Filename;
	color GetColor(string RGB);

public:
	LoadAction(ApplicationManager* pApp);	//Constructor
	~LoadAction();							//Destructor

	//Reads parameters needed for the execution
	virtual void ReadActionParameters();

	//Execute action
	virtual void Execute();
};