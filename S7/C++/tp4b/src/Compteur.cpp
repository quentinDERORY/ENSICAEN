#include <iostream>

#include <Compteur.h>

void Compteur::recoitPalet()
{
	Obstacle::recoitPalet();
	compteur++;

	if(suivant != nullptr)
	{
		suivant->recoitPalet();
		perdPalet();
	}
}

int Compteur::getCompteur()
{
	return compteur;
}

void Compteur::resetCompteur()
{
	compteur = 0;
}

Compteur::~Compteur()
{
	if(suivant != nullptr && suivant->orphelin())
	{
		suivant->set_orphelin(false);
		delete (Compteur*) suivant;
	}
}
