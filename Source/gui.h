#include "video/irrlicht.h"
#include "namespaces.h"
#include "system.h"
#include "dialoguebox.h"
#include "scene.h"
#include "simulations.h"

/* External variables needed. */
extern int state;
extern IGUIWindow *window[64];

/* GUI structures */
struct SAppContext
{
	IrrlichtDevice *device;
};

/* GUI enumerations */
enum
{
	GUI_ID_NULL = NULL, /* Null ID. */
	GUI_ID_QUIT, /* Quit the program. */
	GUI_ID_TIME, /* Time. */
	GUI_ID_GRAVITY, /* Gravity. */
	GUI_ID_CLEAR, /* Gravity. */
	GUI_ID_CAMERA, /* Gravity. */
	GUI_ID_NEW_WINDOW_BUTTON, /* Create a new empty window. */
	GUI_ID_ABOUT, /* About window. */
	GUI_ITOOLSC, /* Tools window. */
	GUI_ID_TOOLSC,
	GUI_ID_TOOLSE, /* Tools window. */
	GUI_ID_FORCE_1, /* Create. */
	GUI_ID_FORCE_2, /* Create. */
	GUI_ID_FORCE_Q, /* Create. */
	GUI_ID_FORCE_BALL, /* Create. */
	GUI_ID_FORCE_PLAT, /* Create. */
	GUI_ID_FORCE_QL,
	GUI_ID_FORCE_LH,
	GUI_ID_FORCE_LO,
	GUI_ID_CLEAR_SMGR, /* Remove all the elements from the scene. */
	GUI_ID_CALCULATE /* Calculate */
};

/* GUI class */
class GUIEventReceiver: public IEventReceiver
{
public:
	GUIEventReceiver(SAppContext & context) : Context(context){}
	/* Get Events */
	virtual bool OnEvent(const SEvent& event)
	{
		if (event.EventType == EET_GUI_EVENT)
		{
			s32 id = event.GUIEvent.Caller->getID();
			IGUIEnvironment* env = Context.device->getGUIEnvironment();
			if (event.GUIEvent.EventType == EGET_BUTTON_CLICKED) /* Get buttons events. */
			{
				if (id == GUI_ID_QUIT)
				{
					state = 0; return true;
				}
				if (id == GUI_ID_NEW_WINDOW_BUTTON)
				{
					window[0] = env->addWindow(rect<s32>(100, 100, 300, 200), false, L"Window"); return true;
				}
				if(id == GUI_ID_FORCE_1)
				{
					if(BF1)
						obj_node_1->remove();
					DrawForce1();
					BF1 = true;
				}
				if(id == GUI_ID_FORCE_2)
				{
					if(BF2)
						obj_node_2->remove();
					DrawForce2();
					BF2 = true;
				}
				if(id == GUI_ID_FORCE_Q)
				{
					if(BQ)
						obj_node_prove->remove();
					DrawForceProve();
					BQ = true;
				}
				if(id == GUI_ID_FORCE_BALL)
				{
					if(BB)
						obj_node_ball->remove();
					DrawBall();
					BB = true;

				}
				if(id == GUI_ID_FORCE_PLAT)
				{
					if(BP)
						obj_node_plat->remove();
					DrawPlat();
					BP = true;
				}
				if(id == GUI_ID_CLEAR_SMGR)
				{
					extern float vel, vel2;
					vel = vel2 = 0;
					BF1 = false;
					BF2 = false;
					BQ = false;
					BB = false;
					BP = false;
					smgr->clear();
					DrawCamera();
					stringw str = L"";InformationText->setText(str.c_str());
				}
				if(id == GUI_ID_TIME)
				{
					extern float hmx;
					hmx = 0;
					stime = 0;
				}
				if(id == GUI_ID_CALCULATE)
				{
					if(BF1 && BQ || BF2 && BQ)
						CalculateForceField();
				}
				if(id == GUI_ID_FORCE_QL)
				{
					Vi = wcstod(v0->getText(),NULL);
					LH = LO = false;
					if(QL)
						QL = false;
					else
						QL = true;
				}
				if(id == GUI_ID_FORCE_LH)
				{
					Vi = wcstod(v0->getText(),NULL);
					QL = LO = false;
					if(LH)
						LH = false;
					else
						LH = true;
					extern float di;
					di = sz0;
				}
				if(id == GUI_ID_FORCE_LO)
				{
					Vi = wcstod(v0->getText(),NULL);
					angle = -wcstod(ang->getText(),NULL);
					QL = LH = false;
					if(LO)
						LO = false;
					else
						LO = true;
					extern float di;
					di = sz0;
				}
			}
			if (event.GUIEvent.EventType == EGET_MENU_ITEM_SELECTED) /* Get menus events. */
			{
				OnMenuItemSelected((IGUIContextMenu*)event.GUIEvent.Caller); return true;
			}
		}
		return false;
	}
	/* Handle "menu item clicked" events. */
	void OnMenuItemSelected( IGUIContextMenu* menu )
	{
		s32 id = menu->getItemCommandId(menu->getSelectedItem());
		IGUIEnvironment *env = device->getGUIEnvironment();
		if(id == GUI_ID_QUIT)
			state = 0;
		if(id == GUI_ID_ABOUT)
			AboutBox();
		if(id == GUI_ID_TOOLSC)
		{
			ToolsBoxC();
		}
		if(id == GUI_ID_TOOLSE)
		{
			ToolsBoxE();
		}
	}
private:
	SAppContext & Context;
};
