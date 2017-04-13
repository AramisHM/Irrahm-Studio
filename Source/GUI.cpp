/*
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	Main.cpp - The GUI variables and GUI build set, also the main GUI loop.
*/

#include "video/irrlicht.h"
#include "device.h"
#include "system.h"
#include "gui.h"

IGUIEditBox *btime, /* Tempo. */
			*bgravity; /* Gravidade. */
IGUIStaticText* myTextBox;
SAppContext context;
GUIEventReceiver receiver(context);

int GUI()
{
	/* event receiver */
	context.device = device;
	device->setEventReceiver(&receiver);

	/* skin apparence */
	SetSkinApparence(255, 0, 0);

	/* build GUI set */
	IGUIContextMenu* menu = env->addMenu(); /* Menu vaiable. */
	menu->addItem(L"Irrahm", -1, true, true);
	menu->addItem(L"Ver", -1, true, true);
	menu->addItem(L"Ajuda", -1, true, true);

	IGUIContextMenu* submenu; /* Submenu variable. */
	submenu = menu->getSubMenu(0); /* "Irrahm" menu button */
	submenu->addSeparator();
	submenu->addItem(L"Sair", GUI_ID_QUIT);

	submenu = menu->getSubMenu(1); /* "View" menu button. */
	submenu->addItem(L"Simuladores", 0, true, true);
	submenu = menu->getSubMenu(1)->getSubMenu(0);
	submenu->addItem(L"Lancamentos", GUI_ID_TOOLSC); submenu->addItem(L"Eletromagnetismo", GUI_ID_TOOLSE); //submenu->addItem(L"Developing", 0);

	submenu = menu->getSubMenu(2); /* "Help" menu button. */
	submenu->addItem(L"Sobre", GUI_ID_ABOUT);

	IGUIToolBar *bar = env->addToolBar(); /* Tool bar. */
	video::ITexture* image = driver->getTexture("./data/quit.png");
	bar->addButton(GUI_ID_QUIT, 0, L"Sair", image, 0, false, true);
	image = driver->getTexture("./data/cloack.png");
	bar->addButton(GUI_ID_TIME, 0, L"Tempo", image, 0, false, true);
	image = driver->getTexture("./data/clear.png");
	bar->addButton(GUI_ID_CLEAR_SMGR, 0, L"Limpar cenario", image, 0, false, true);
	btime = env->addEditBox(L"0.007", rect<s32>(220, 25, 280, 45), true, window[1]); env->addStaticText(L"factor/s", rect<s32>(290, 25, 370, 45), false, true, window[1]);
	bgravity = env->addEditBox(L"9.76", rect<s32>(420, 25, 480, 45), true, window[1]); env->addStaticText(L"m/s**2", rect<s32>(490, 25, 570, 45), false, true, window[1]);
	myTextBox = env->addStaticText(L"Default_text", rect<s32>(490, 25, 680, 45), true, true, 0, -1, true); /* Dynamic text */
	env->addStaticText(L"cam pos:", rect<s32>(690, 25, 750, 45), false, true, window[1]);
	pcx = env->addEditBox(L"7", rect<s32>(760, 25, 820, 45), true, window[1]);
	pcy = env->addEditBox(L"3", rect<s32>(830, 25, 890, 45), true, window[1]);
	pcz = env->addEditBox(L"7", rect<s32>(900, 25, 960, 45), true, window[1]);

	InformationText = device->getGUIEnvironment()->addStaticText(L"", rect<s32>(10, 80, 290, 490), false, true, 0);
	InformationText->setOverrideColor(SColor(255, 255, 255, 255));

	SplashBox(); /*Splash screen. */
	DrawCamera();

	/* main loop */
	extern int state;
	u32 then = device->getTimer()->getTime();
	int lastFPS = -1;
	while (device->run() && state == 1)
	{
		const u32 now = device->getTimer()->getTime();/* Work out a frame delta time. */
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; /* Time in seconds. */
		then = now;

		UpdateCamera();
		stringw str = L"Time: "; str += stime; str += L" s";
		myTextBox->setText(str.c_str());
		if(QL)
			SQL();
		if(LH)
			SLH();
		if(LO)
			SLO();

		driver->beginScene(true, true, SColor(255, 57, 57, 57));
		smgr->drawAll();
		env->drawAll();
		driver->endScene();
	}
	return 1;
}
