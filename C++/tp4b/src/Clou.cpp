#include <typeinfo>
#include <iostream>

#include <Obstacle.h>
#include <Compteur.h>
#include <Clou.h>

void Clou::recoitPalet()
{
	Obstacle::recoitPalet();
	transmetPalet();
	perdPalet();
}

void Clou::transmetPalet()
{
	if(!paletPresent())
		return;

	if((std::rand()%2) == 0)
		gauche->recoitPalet();
	else
		droite->recoitPalet();
}

Clou::~Clou()
{
	if(gauche->orphelin())
	{
		gauche->set_orphelin(false);
		delete gauche;
	}

	if(droite->orphelin())
	{
		droite->set_orphelin(false);
		delete droite;
	}
}
