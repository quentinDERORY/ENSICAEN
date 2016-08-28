#ifndef INC_OBSTACLE_H
#define INC_OBSTACLE_H

class Obstacle
{
private:
	bool palet_present;
	bool est_orphelin;

public:
	Obstacle(bool orphelin=true) : palet_present(false), est_orphelin(orphelin) {}
	virtual ~Obstacle();

	virtual void recoitPalet();

	void perdPalet();

	bool paletPresent();

	void set_orphelin(bool);

	bool orphelin();
};

#endif
