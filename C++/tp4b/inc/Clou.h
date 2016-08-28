#ifndef INC_CLOU_H
#define INC_CLOU_H

#include <cstdlib>
#include <ctime>

#include <Obstacle.h>

class Clou : public Obstacle
{
private:
	Obstacle* gauche;
	Obstacle* droite;
public:
	Clou(Obstacle* gauche, Obstacle* droite) : gauche(gauche), droite(droite){}
	~Clou();

	void recoitPalet();

	void transmetPalet();
};
#endif
