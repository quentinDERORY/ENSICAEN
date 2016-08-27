#ifndef PLANCHE_H
#define PLANCHE_H

/**
 * @file Planche.h
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */

using namespace std;



#include <Compteur.h>
#include <Lanceur.h>
 
class Planche{

 public :
  Planche(int nbr_compt);
  void simulation(int N);
  void affichage();
  ~Planche();


 private:

  Lanceur* _lanceur;
  int _nombre_compteurs;
  Compteur** _tab_compt;
};
#endif
