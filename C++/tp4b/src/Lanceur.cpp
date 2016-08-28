#include <iostream>

#include <Lanceur.h>
#include <Clou.h>

void Lanceur::lancer()
{

	if(obstacle_depart != nullptr)
		obstacle_depart->recoitPalet();
}

Lanceur::~Lanceur()
{
	if(obstacle_depart->orphelin())
	{
		obstacle_depart->set_orphelin(false);
		delete obstacle_depart; // REMARQUE: delete (*Clou) obstacle_depart <=> ((Clou*)obstacle_depart)->~Clou();
	}
}
