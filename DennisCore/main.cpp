// ==================[Copyright Aarik R. 2023]==================
// Purpose : The main loop of Dennis.
//
//
// =============================================================

#include <Windows.h>
#include <iostream>
#include "interface.h"
#include "dennis.h"
#include "app.h"

#define DENNIS_MAX_TIME 900000
#define DENNIS_MIN_TIME 60000

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	DENNISAPP* DENNISINSTANCE = new DENNISAPP();

	DENNISINSTANCE->Start();

	srand(time(NULL));

	// Add a small delay after starting up
	int timeToNextTick = 35000;
	
	Sleep(timeToNextTick);

	while (true) {
		timeToNextTick = rand() % (DENNIS_MAX_TIME - DENNIS_MIN_TIME) + DENNIS_MIN_TIME;
		DENNISINSTANCE->dennisInstance->Tick();
		Sleep(timeToNextTick);
	}

	DennisShutdown();

}