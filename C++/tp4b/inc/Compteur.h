#ifndef INC_COMPTEUR_H
#define INC_COMPTEUR_H

#include <Obstacle.h>

class Compteur  : public Obstacle
{
private:
	int compteur;
	Obstacle* suivant;
public:
	Compteur() : compteur(0), suivant(nullptr) {}

	Compteur(Obstacle* suivant) : compteur(0), suivant(suivant) {}

	~Compteur();

	void recoitPalet();

	int getCompteur();

	void resetCompteur();
};

#endif
