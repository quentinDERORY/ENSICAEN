#include <iostream>
#include <Clou.h>
#include <ctime>

/**
 * @file Clou.cpp
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */



Clou::Clou(Clou* successeur_gauche,Clou* successeur_droit){
  

  _successeur_gauche=(Obstacle*)successeur_gauche;
  _successeur_droit=(Obstacle*)successeur_droit;
  //Si son successeur gauche est orphelin on l'assigne en ant que fils gauche
  if(successeur_gauche->est_orphelin())
    {
      gauche=true;
    _successeur_gauche->set_orphelin(false);
    }
   //Si son successeur droit est orphelin on l'assigne en tant que fils droit
  if(successeur_droit->est_orphelin())
    {
      droit=true;
    _successeur_droit->set_orphelin(false);
 } 
  
}
Clou::Clou(Compteur* successeur_gauche,Compteur* successeur_droit){
  

  _successeur_gauche=(Obstacle*)successeur_gauche;
  _successeur_droit=(Obstacle*)successeur_droit;
   //Si son successeur gauche est orphelin on l'assigne en ant que fils gauche
  if(_successeur_gauche->est_orphelin())
    {
     gauche=true;
    _successeur_gauche->set_orphelin(false);
    }
 //Si son successeur droit est orphelin on l'assigne en tant que fils droit
  if(_successeur_droit->est_orphelin())
    {
      droit=true;
    _successeur_droit->set_orphelin(false);
    }
}


Clou::~Clou(){
  // Si il a un fils droit il le supprime
   if(droit)
      delete _successeur_droit;
// Si il a un fils gauche il le supprime
    if(gauche)
      delete _successeur_gauche;
}



Clou & Clou::operator=(const Clou & autre){
  if ( this == &autre ) return *this;

  _successeur_droit=autre._successeur_droit;
  _successeur_gauche=autre._successeur_gauche;
  droit=autre.droit;
  gauche=autre.gauche;
 
  return *this;
}


void Clou::recoitPalet(){

  int tmp=rand()%100;
  //Les chances du palet de rejoindre le succeseur droit ou gauche sont équiprobables
  if(tmp>50)
    (_successeur_droit)->recoitPalet();
  else
    (_successeur_gauche)->recoitPalet();

}
