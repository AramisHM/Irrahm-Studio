/*
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	Device.cpp - Works with Irrlicht's device initialization, management and finalization.
*/

#include "video/irrlicht.h"
#include "video.h"
#include "namespaces.h"

IrrlichtDevice *device;
IVideoDriver *driver;
IGUIEnvironment *env;
ISceneManager* smgr;
dimension2d<u32> resolution;

int CreateDevice()
{
#ifdef CustomRes /* Custom resolution. */
	resolution = dimension2d<u32>(Wres, Hres);
#else /* Get maximum resolution. */
	IrrlichtDevice *nulldevice = createDevice(video::EDT_NULL);
	resolution = nulldevice->getVideoModeList()->getDesktopResolution();
	if(resolution.Width < MinWres || resolution.Height < MinHres)
		return -MinHres;
	if(resolution.Width > MaxWres || resolution.Height > MaxHres)
		return MaxHres;
	nulldevice -> drop();
#endif
	device = createDevice(EDT_OPENGL, resolution, 32, DFullScreen, true, true, 0);
	if(!device)
		return 0;
	if(!DFullScreen)
		device->setResizable(DResizable);
	driver = device->getVideoDriver();
	env = device->getGUIEnvironment();
	smgr = device->getSceneManager();
	if(device && driver && env && smgr)
		return 1;
	else
		return 0;
}

int CloseDevice()
{
	device->closeDevice();
	if(!device)
		return 1;
	else
		return 0;
}

void ClearDevice()
{
	env->clear();
	smgr->clear();
}

int DestroyDevice()
{
	device->drop();
	if(!device)
		return 1;
	else
		return 0;
}
