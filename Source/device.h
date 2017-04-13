#include "video/irrlicht.h"
#include "namespaces.h"

extern IrrlichtDevice *device;
extern IVideoDriver *driver;
extern IGUIEnvironment *env;
extern ISceneManager* smgr;
extern dimension2d<u32> resolution;

/* Functions */

/* Creates a irrlicht device. Must have "device.h" included on your code.
If this function return 0 it means that it couldn't create a device and
returns 1 if all went well. */
int CreateDevice();

/* Closes the existent device. */
int CloseDevice();

/* Remove all the elements on scene and gui. */
void ClearDevice();

/* Drops the existent device. */
int DestroyDevice();