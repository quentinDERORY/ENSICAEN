#ifndef INC_LANCEUR_H
#define INC_LANCEUR_H

#include <Obstacle.h>

class Lanceur
{
private:
	Obstacle* obstacle_depart;
public:
	Lanceur() {}
	Lanceur(Obstacle* obstacle) : obstacle_depart(obstacle) {}
	~Lanceur();
	
	void lancer();
};

#endif
