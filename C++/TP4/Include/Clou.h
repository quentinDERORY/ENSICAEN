#ifndef CLOU_H
#define CLOU_H


/**
 * @file Clou.h
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */

#include <Obstacle.h>
#include <Compteur.h>

class Clou : Obstacle {
 public :
  Clou(Clou* successeur_gauche,Clou* successeur_droit);
  Clou(Compteur* successeur_gauche,Compteur* successeur_droit);
  ~Clou();
  Clou & operator=(const Clou & autre);
  void recoitPalet() override;

 private:
  Obstacle* _successeur_gauche;
  Obstacle* _successeur_droit;
  bool droit=false;//possède un fils à droite
  bool gauche=false;//possède un fils à gauche

};
#endif
