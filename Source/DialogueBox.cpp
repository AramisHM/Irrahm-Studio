/*
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	Dialogue.cpp - System's general definitions, variables and fuctions. Some windows/dialogue boxes build sets.
	For more informations about the functions in this source file, go to "Dialogue.h".
*/

#include "video/irrlicht.h"
#include "namespaces.h"
#include "device.h"
#include "video.h"
#include "gui.h"
#include "simulations.h"

/* Dialogue boxes Edite Boxes. */
IGUIEditBox *px, /* Position X. */
			*py, /* Position Y. */
			*pz, /* Position Z. */
			*pq,
			*pcx,
			*pcy,
			*pcz,
			*v0,
			*ang; /* angle X. */

IGUIWindow *window[64]; /* A vector of windows that we reuse. */
stringw AboutText; /* Show a texte loaded from a XML on the "About" window. */
IGUIStaticText *InformationText; /* The right bottom debug text. */

void SplashBox()
{
	window[0] = env->addWindow(rect<s32>(resolution.Width/2 - 310, resolution.Height/2 - 129, resolution.Width/2 - 313 + 630, resolution.Height/2 - 120 + 360), false, L"");
	device->getGUIEnvironment()->addImage(driver->getTexture("./data/splash.png"), core::position2d<s32>(0,20), -1, window[0]);
	device->getGUIEnvironment()->addStaticText(L"Irrahm Engine version 1.1\nHornung Moraes, Aramis", rect<s32>(216, 320, 413, 359), false, true, window[0]);
}

void AboutBox()
{
	IGUIWindow *about_window = device->getGUIEnvironment()->addMessageBox(L"Sobre", AboutText.c_str());
	device->getGUIEnvironment()->addImage(driver->getTexture("./data/Mr.Aramis.PNG"), core::position2d<s32>(20,200), -1, about_window);
}

void ToolsBoxE()
{
	window[1] = env->addWindow(rect<s32>(0, 54, 300, 560), false, L"Eletromagnetismo");
	env->addButton(rect<s32>(10,30,40,50), window[1], GUI_ID_FORCE_1, L"E1", L"Adicionar campo de forca.");
	env->addButton(rect<s32>(50,30,80,50), window[1], GUI_ID_FORCE_2, L"E2", L"Adicionar campo de forca.");
	env->addButton(rect<s32>(90,30,110,50), window[1], GUI_ID_FORCE_Q, L"q", L"Adicionar carga de prova.");
	env->addButton(rect<s32>(140,30,240,50), window[1], GUI_ID_CALCULATE, L"Calcular", L"Calcular.");
	px = env->addEditBox(L"0", rect<s32>(10, 60, 140, 80), true, window[1]); env->addStaticText(L" X pos (metros)", rect<s32>(140, 60, 280, 80), false, true, window[1]);
	py = env->addEditBox(L"0", rect<s32>(10, 90, 140, 110), true, window[1]); env->addStaticText(L" Y pos (metros)", rect<s32>(140, 90, 280, 110), false, true, window[1]);
	pz = env->addEditBox(L"0", rect<s32>(10, 120, 140, 140), true, window[1]); env->addStaticText(L" Z pos (metros)", rect<s32>(140, 120, 280, 140), false, true, window[1]);
	pq = env->addEditBox(L"1", rect<s32>(10, 150, 140, 170), true, window[1]); env->addStaticText(L" Q (micro coulombs)", rect<s32>(140, 150, 280, 170), false, true, window[1]);
}
void ToolsBoxC()
{
	window[1] = env->addWindow(rect<s32>(0, 54, 300, 560), false, L"Lancamentos");
	env->addButton(rect<s32>(10,30,40,50), window[1], GUI_ID_FORCE_BALL, L"Bola", L"Adicionar progetil.");
	env->addButton(rect<s32>(50,30,80,50), window[1], GUI_ID_FORCE_PLAT, L"Plat", L"Adicionar plataforma.");
	env->addButton(rect<s32>(90,30,120,50), window[1], GUI_ID_FORCE_QL, L"QL", L"Queda livre.");
	env->addButton(rect<s32>(130,30,150,50), window[1], GUI_ID_FORCE_LH, L"LH", L"Lancamento horizontal.");
	env->addButton(rect<s32>(160,30,190,50), window[1], GUI_ID_FORCE_LO, L"LO", L"Lancamento obliquo.");
	px = env->addEditBox(L"0", rect<s32>(10, 60, 140, 80), true, window[1]); env->addStaticText(L" X pos (metros)", rect<s32>(140, 60, 280, 80), false, true, window[1]);
	py = env->addEditBox(L"0", rect<s32>(10, 90, 140, 110), true, window[1]); env->addStaticText(L" Y pos (metros)", rect<s32>(140, 90, 280, 110), false, true, window[1]);
	pz = env->addEditBox(L"0", rect<s32>(10, 120, 140, 140), true, window[1]); env->addStaticText(L" Z pos (metros)", rect<s32>(140, 120, 280, 140), false, true, window[1]);
	ang = env->addEditBox(L"45", rect<s32>(10, 150, 140, 170), true, window[1]); env->addStaticText(L" Angulo (deg)", rect<s32>(140, 150, 280, 170), false, true, window[1]);
	v0 = env->addEditBox(L"0", rect<s32>(10, 180, 140, 200), true, window[1]); env->addStaticText(L" Vel. Ini. (m/s)", rect<s32>(140, 180, 280, 200), false, true, window[1]);
}