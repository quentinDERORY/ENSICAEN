#ifndef INC_PLANCHE_H
#define INC_PLANCHE_H
// pour la destruction, c particulier => lequel d'un pere va detruire un même successeur ? idee simple, boolean pour dire si oprphelin

// relier avec ceux d'en dessous
#include <Compteur.h>
#include <Obstacle.h>
#include <Lanceur.h>

class Planche
{
private:
	Lanceur* lanceur;

	int nb_compteurs;
	Compteur** compteurs;
	Compteur* compteur_final;

	Obstacle** construction;
public:
	Planche(int);
	~Planche();

	void simulation(int nbr);

	void affiche_compteurs();
};

#endif
