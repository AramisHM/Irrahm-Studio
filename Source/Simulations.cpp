/*	
	Irrahm Engine
	Developer: Aramis Hornung Moraes

	Simulations.cpp - In this "Plug-in" we could make simple functions for Irrahm Engine
	Developed by Aramis hornung moraes on 04.11.2012.
	PHYSICS SIMULATOR PROJECT
*/

#include "video/irrlicht.h" /* Irrlicht main interface. */
#include "namespaces.h" /* Irrlichts's namespaces. */
#include "device.h" /* Irrahm device set. */
#include "dialoguebox.h"
#include "scene.h"
#include "system.h"

double E1, E2, Q1, Q2, ER;
extern IGUIEditBox *btime, /* Tempo. */
				   *bgravity; /* Gravidade. */
float vel = 0,
	  vel2 = 0,
	  velR = 0,
	  di = 0,
	  df = 0,
	  hmx = 0;

double FFDistance(IMeshSceneNode *a, IMeshSceneNode *b) /* Calculates the distance.  */
{
	double distance;
	double xd = (double(b->getPosition().X) - double(a->getPosition().X));
	double yd = (double (b->getPosition().Y) - double (a->getPosition().Y));
	double zd = (double (b->getPosition().Z) - double (a->getPosition().Z));
	distance = (xd*xd)+(yd*yd)+(zd*zd);
	distance = sqrt(distance);
	return distance; 
}

double FFE(double Q, double rad)
{
	double E;
	if(Q<0)
			Q=-Q;
	E = (((9000000000*Q)/(rad*rad))/1000000);
	return E;
}

void CalculateForceField() /* Calculates and display in somewere the results of the forces and its propeties. */
{
	if(BQ && BF1 && BF2)
	{
		E1 = FFE(Q1, FFDistance(obj_node_prove, obj_node_1));
		E2 = FFE(Q2, FFDistance(obj_node_prove, obj_node_2));
		ER = E2 - E1;
		
		/* Information */
		float distanceqF1 = FFDistance(obj_node_prove, obj_node_1), distanceqF2 = FFDistance(obj_node_prove, obj_node_2);
		stringw str = L"Distancia q ao campo 1: "; str += distanceqF1; str += L" metros\n\n";
		str += L"Distancia q ao campo 2: "; str += distanceqF2; str += L" meters\n\n";
		str += L"Q campo 1: "; str += Q1; str += L" micro coulombs\nE F1: "; str += E1; str += L" N/C\n\n";
		str += L"Q campo 2: "; str += Q2; str += L" micro coulombs\nE F2: "; str += E2; str += L" N/C\n\n";
		str += L"Campo resltante: "; str += ER; str += L" N/C\n";
		InformationText->setText(str.c_str());
	}
}

void SQL() /* Queda livre simulation. */
{
	if(BB && BP) /* If ball and platform. */
	{
		if(sy0 - Vi*stime- 0.5*(float)wcstod(bgravity->getText(),NULL)*(stime*stime) >= lim)
		{
			stime = stime + (float)wcstod(btime->getText(),NULL);
			UY = sy0 - Vi*stime- 0.5*(float)wcstod(bgravity->getText(),NULL)*(stime*stime);
			vel = Vi + wcstod(bgravity->getText(),NULL)*stime;
			obj_node_ball->setPosition(vector3df(UX, UY, UZ));
		}

		/* Information */
		stringw str = L"h = "; str += UY; str += L" metros\nvelocidade: ";str += vel; str += L" m/s\n";
		InformationText->setText(str.c_str());
	}
}
void SLH() /* Lançamento horizontal simulation. */
{
	if(BB && BP) /* If ball and platform. */
	{
		if(sy0 - 0.5*(float)wcstod(bgravity->getText(),NULL)*(stime*stime) >= lim)
		{
			stime = stime + (float)wcstod(btime->getText(),NULL);
			UY = sy0 - 0.5*(float)wcstod(bgravity->getText(),NULL)*(stime*stime);
			UZ = sz0 + Vi * stime;
			vel = wcstod(bgravity->getText(),NULL)*stime;
			vel2 = sqrt((Vi*Vi)+(vel*vel));
			obj_node_ball->setPosition(vector3df(UX, UY, UZ));
		}
		df = obj_node_ball->getPosition().Z - di;
		/* Information */
		stringw str = L"h = "; str += UY; str += L" metros\nvelocidade: ";str += vel2; str += L" m/s\nDistancia axima: ";str += df;
		InformationText->setText(str.c_str());
	}
}
void SLO() /* Lançamento oblíquo simulation. */
{
	if(BB && BP) /* If ball and platform. */
	{
		vel = Vi*sin(angle*(3.1415/180));
		vel2 = Vi*cos(angle*(3.1415/180));
		float rv1 = vel + (float)wcstod(bgravity->getText(),NULL)*stime; /* Realtime Y velocity. */

		if(sy0 - vel*stime- 0.5*(float)wcstod(bgravity->getText(),NULL)*(stime*stime) >= lim)
		{
			stime = stime + (float)wcstod(btime->getText(),NULL);
			UY = sy0 - vel*stime - 0.5*(float)wcstod(bgravity->getText(),NULL)*(stime*stime);
			UZ = sz0 + vel2 * stime;
			velR = sqrt((rv1*rv1)+(vel2*vel2));
			obj_node_ball->setPosition(vector3df(UX, UY, UZ));
		}
		df = obj_node_ball->getPosition().Z - di;
		/* Information */
		if(hmx < obj_node_ball->getPosition().Y)
			hmx = obj_node_ball->getPosition().Y;
		stringw str = L"h = "; str += UY; str += L" metros\nvelocidade: ";str += velR; str += L" m/s\nDistancia maxima: ";str += df;str += L"\nAltura axima: ";str += hmx;
		InformationText->setText(str.c_str());

		extern float di;
	}
}