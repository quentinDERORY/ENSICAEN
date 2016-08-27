#ifndef LANCEUR_H
#define LANCEUR_H

/**
 * @file Lanceur.h
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


#include <Obstacle.h>
#include <Clou.h>
#include <Compteur.h>

class Lanceur{

 public :
  Lanceur();
  Lanceur(Clou* o);
  Lanceur(Compteur* o);
  ~Lanceur();
  void lancer();
 

 private :
  
  Obstacle* o1;

};

#endif
