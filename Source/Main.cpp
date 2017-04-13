/*	
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	Main.cpp
*/

#include "irrahm.h"
#include "namespaces.h"
#include "device.h"
#include "system.h"
#include "gui.h"
#include "windows.h" /* hide console */

/* Software state.
Helps the program switch between it states. */
int state = 1;

int main()
{
	printf("Irrahm Engine [version %d.%d.%d.%d]\n", Version_Major, Version_Minor, Version_Build, Version_Revision);

	CreateDevice(); /* Start Irrlicht. */
	stringw str = Project_Name;
	device->setWindowCaption(str.c_str());
	LoadSystem();
	LoadXML();

#ifdef HideConsole
	ShowWindow( GetConsoleWindow(), SW_HIDE);
#endif

	do
	{
		switch(state)
		{
		case -1: /* Reload state 1. */
			state = 1;
			break;
		case 1:
			GUI();
			break;
		default:
			state = 0;
			break;
		}
		ClearDevice();
	}while(state != 0);

	CloseDevice();
	DestroyDevice();

	return 1;
}