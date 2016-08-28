#include <iostream>
#include <math.h>

#include <Lanceur.h>
#include <Clou.h>
#include <Planche.h>

// pour la destruction, c particulier => lequel d'un pere va detruire un même successeur ? idee simple, boolean pour dire si oprphelin

// relier avec ceux d'en dessous

Planche::Planche(int nbr_compteurs)
{
	nb_compteurs = nbr_compteurs;

	compteur_final = new Compteur();

	compteurs = (Compteur**) new Compteur[nbr_compteurs];

	// creation des compteurs
	for(int i=0; i<nbr_compteurs; i++)
		compteurs[i] = new Compteur(compteur_final);

	// affectation des compteurs a la construction
	construction = (Obstacle**) new Obstacle[nbr_compteurs];

	for(int i=0; i<nbr_compteurs; i++)
	{
		construction[i] = compteurs[i];
	}

	// Creation des clous
	for(int i=nbr_compteurs-1; i>=0; i--)
	{
		for(int j=0; j<i; j++)
		{
			// creation du fils, et sauvegarde dans le tableau tmp
			construction[j] = new Clou(construction[j], construction[j+1]);
		}
	}

	// rq: construction[0] <=> clou racine
	lanceur = new Lanceur(construction[0]);

	// @todo probleme ici, implicitement lanceur.~Lanceur() est appelé alors qu'on ne veut pas, en effet il est utilisé lors de la simulation
}

void Planche::simulation(int nbr)
{
	for(int i=0; i<nbr; i++)
	{
		lanceur->lancer();
	}

	for(int i=0; i<nb_compteurs; i++)
	{
		std::cout << "Compteur(" << i << ") : " << round(((float)(compteurs[i])->getCompteur()/compteur_final->getCompteur()) * 100.0) << "%" << std::endl;
	}
}

void Planche::affiche_compteurs()
{
	for(int i=0; i<nb_compteurs; i++)
	{
		std::cout << "Compteur(" << i << ") : " << (compteurs[i])->getCompteur() << std::endl;
	}

	std::cout << "Compteur final : " << compteur_final->getCompteur() << std::endl;
}

Planche::~Planche()
{
	lanceur->~Lanceur();
}
