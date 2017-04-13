/*	
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	irrahm.h - Interface of the "Irrahm Engine".
	Irrahm engine uses "Irrlicht Engine" for graphic rendering engine.
*/

/* software versioning */
#define Project_Name "Irrahm Studio"
#define Version_Major 1
#define Version_Minor 1
#define Version_Build 1
#define Version_Revision 1

#include <video/irrlicht.h>

/* Libs */
#if defined(_MSC_VER)
#pragma comment(lib, "Irrlicht.lib")
#endif

/* deffinitions */
/* Hide console? (Windows) */
//#define HideConsole

/* functions */
/* Load and start GUI. */
int GUI();