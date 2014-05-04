#include <Windows.h>
#include <cstdlib>
#include <iostream>
#include "ErrorReport.h"
#include "CArrow.h"
#include "ObjectInterface.h"

int Move(float fTime)
{
	return 1;
}

int Render(float fTime);

int MainLoop(float fTime)
{

	Move(fTime);
	Render(fTime);

	return 1;
}

int InitScene()
{
	return 1;
}

void EndScene()
{
}

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpSmd, int nCmdShow)
{	
	float fTime = 0.0f;

	if(!InitStage())
		return 0;

	int r = 0;
	do
	{
		r = Move(fTime);
		if(!r)
			break;

		r = Render(fTime);
	}while(r);

	EndScene();

	return 0;
}
