/*	
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	System.cpp - System's general definitions, variables and fuctions.
	For more informations about the functions in this source file, go to "system.h".
*/

#include "device.h"
#include "video.h"

extern stringw AboutText; /* Show a texte loaded from a XML on the "About" window. */
bool BF1 = false,
	 BF2 = false,
	 BQ = false,
	 BT = false,
	 BC = false,
	 BB = false,
	 BP = false,
	 QL = false,
	 LH = false,
	 LO = false;
float
	 UX = 0,
	 UY = 0,
	 UZ = 0,
	 sy0 = 0,
	 sz0 = 0,
	 Vi = 0,
	 Viy = 0,
	 Viz = 0,
	 angle,
	 lim;

float stime = 0;

int LoadSystem()
{
	env->getSkin()->setFont(env->getFont("./data/fontlucida.png"));
	return 1;
}

void SetSkinApparence(s32 alpha, SColor Color_1, SColor Color_2)
{
	for (s32 i=0; i<gui::EGDC_COUNT ; ++i)
	{
		video::SColor col = env->getSkin()->getColor((gui::EGUI_DEFAULT_COLOR)i);
		col.setAlpha(alpha);
		env->getSkin()->setColor((EGUI_DEFAULT_COLOR)i, col);
	}
	if(Color_1 == NULL)
		Color_1 = SColor(255,114,114,114);
	if(Color_2 == NULL)
		Color_2 = SColor(255,127,127,127);
	env->getSkin()->setColor((EGUI_DEFAULT_COLOR)1, Color_1);
	env->getSkin()->setColor((EGUI_DEFAULT_COLOR)2, Color_2);
}

int LoadXML()
{
	device->getFileSystem()->addFolderFileArchive("./");
	io::IXMLReader* xml = device->getFileSystem()->createXMLReader( L"config.ahmx");
	while(xml && xml->read())
	{
		switch(xml->getNodeType())
		{
		case io::EXN_TEXT:
			AboutText = xml->getNodeData(); /* Load the data from the XML file to the variable "AboutText". */
			break;
		case io::EXN_ELEMENT:
			{/*
				if (core::stringw("startUpModel") == xml->getNodeName())
					StartUpModelFile = xml->getAttributeValue(L"file");
				else
				if (core::stringw("messageText") == xml->getNodeName())
					Caption = xml->getAttributeValue(L"caption");*/
			}
			break;
		default:
			break;
		}
	}
	if (xml)
		xml->drop();
	return 1;
}