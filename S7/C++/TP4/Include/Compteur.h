#ifndef COMPTEUR_H
#define COMPTEUR_H

/**
 * @file Compteur.h
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


#include <Obstacle.h>

class Compteur : Obstacle {
 public:
  Compteur();
  ~Compteur();
  Compteur(Compteur* successeur);
  int get_compt(){return compt;};
  void reset_compt(){compt=0;};
  void recoitPalet() override;
 


 private:

  int compt;
  Compteur* _successeur;
  bool pere=false;
};
#endif
