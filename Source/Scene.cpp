/*	
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	Scene.cpp
*/


#include "video/irrlicht.h"
#include "namespaces.h"
#include "device.h"
#include "dialoguebox.h"
#include "system.h"
#include "simulations.h"

ICameraSceneNode *camera; /* The main camera for scene. */
ILightSceneNode *sunlight ;
IMeshSceneNode *obj_node_1, /* Force field 1. */
			   *obj_node_2, /* Force field 2. */
			   *obj_node_prove, /* Q. */
			   *obj_node_ball, /* Ball. */
			   *obj_node_plat, /* Platform. */
			   *obj_node_empty; /* Empty. */

void DrawCamera()
{
	camera = smgr-> addCameraSceneNode();
	camera->setNearValue(0.1f);
	camera->setFarValue(1024.0f);
	camera->setPosition(vector3df(0,0,0));
	camera->setTarget(vector3df(0,0,0));
	sunlight = smgr->addLightSceneNode(0, core::vector3df(0,1000,0),video::SColorf(1.0f,1.0f,1.0f,1.0f), 1024);
	IAnimatedMesh *obj = smgr->getMesh("./data/empty.obj");
	obj_node_empty = 0;
	if (obj)
		obj_node_empty = smgr->addMeshSceneNode(obj->getMesh(0), 0);
	if (obj_node_empty)
	{
		obj_node_empty->setMaterialFlag(video::EMF_LIGHTING, false);
	}
	obj_node_empty->setPosition(vector3df(0, 0, 0));
	obj_node_empty->setScale(vector3df(vector3df(1, 1, 1)));
}

void UpdateCamera()
{
	camera->setPosition(vector3df((s32)wcstod(pcx->getText(),NULL), (s32)wcstod(pcy->getText(),NULL), (s32)wcstod(pcz->getText(),NULL)));
	camera->setTarget(vector3df(0,0,0));
}
void DrawBall()
{
	IAnimatedMesh *obj = smgr->getMesh("./data/ball.obj");
	obj_node_ball = 0;
	if (obj)
		obj_node_ball = smgr->addMeshSceneNode(obj->getMesh(0), 0);
	if (obj_node_ball)
	{
		obj_node_ball->setMaterialFlag(video::EMF_LIGHTING, true);
	}
	obj_node_ball->setPosition(vector3df(((float)wcstod(px->getText(),NULL)), ((float)wcstod(py->getText(),NULL)), ((float)wcstod(pz->getText(),NULL))));
	obj_node_ball->setScale(vector3df(vector3df(1, 1, 1)));
	UX = (float)wcstod(px->getText(),NULL);
	UY = (float)wcstod(py->getText(),NULL);
	UZ = (float)wcstod(pz->getText(),NULL);
	sy0 = obj_node_ball->getPosition().Y;
	sz0 = obj_node_ball->getPosition().Z;
}

void DrawPlat()
{
	IAnimatedMesh *obj = smgr->getMesh("./data/Default_scene.obj");
	obj_node_plat = 0;
	if (obj)
		obj_node_plat = smgr->addMeshSceneNode(obj->getMesh(0), 0);
	if (obj_node_plat)
	{
		obj_node_plat->setMaterialFlag(video::EMF_LIGHTING, true);
	}
	obj_node_plat->setPosition(vector3df(((float)wcstod(px->getText(),NULL)), ((float)wcstod(py->getText(),NULL)), ((float)wcstod(pz->getText(),NULL))));
	obj_node_plat->setScale(vector3df(vector3df(1, 1, 1)));
	lim = obj_node_plat->getPosition().Y;
}

void DrawForce1()
{
	IAnimatedMesh *obj = smgr->getMesh("./data/force.obj");
	obj_node_1 = 0;
	if (obj)
		obj_node_1 = smgr->addMeshSceneNode(obj->getMesh(0), 0);
	if (obj_node_1)
	{
		obj_node_1->setMaterialFlag(video::EMF_LIGHTING, true);
	}
	obj_node_1->setPosition(vector3df(((float)wcstod(px->getText(),NULL)), ((float)wcstod(py->getText(),NULL)), ((float)wcstod(pz->getText(),NULL))));
	obj_node_1->setScale(vector3df(vector3df(1, 1, 1)));
	//R1 = (double)wcstod(rad->getText(),NULL);
	Q1 = (double)wcstod(pq->getText(),NULL);
}

void DrawForce2()
{
	IAnimatedMesh *obj = smgr->getMesh("./data/force.obj");
	obj_node_2 = 0;
	if (obj)
		obj_node_2 = smgr->addMeshSceneNode(obj->getMesh(0), 0);
	if (obj_node_2)
	{
		obj_node_2->setMaterialFlag(video::EMF_LIGHTING, true);
	}
	obj_node_2->setPosition(vector3df((float)wcstod(px->getText(),NULL), (float)wcstod(py->getText(),NULL), (float)wcstod(pz->getText(),NULL)));
	obj_node_2->setScale(vector3df(1, 1, 1));
	//R2 = (float)wcstod(rad->getText(),NULL);
	Q2 = (float)wcstod(pq->getText(),NULL);
}

void DrawForceProve()
{
	IAnimatedMesh *obj = smgr->getMesh("./data/force.obj");
	obj_node_prove = 0;
	if (obj)
		obj_node_prove = smgr->addMeshSceneNode(obj->getMesh(0), 0);
	if (obj_node_prove)
	{
		obj_node_prove->setMaterialFlag(video::EMF_LIGHTING, true);
	}
	obj_node_prove->setPosition(vector3df((float)wcstod(px->getText(),NULL), (float)wcstod(py->getText(),NULL), (float)wcstod(pz->getText(),NULL)));
	obj_node_prove->setScale(vector3df(0.2, 0.2, 0.2));
}