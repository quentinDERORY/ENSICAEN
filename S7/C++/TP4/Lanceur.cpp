#include <iostream>
#include <Lanceur.h>
/**
 * @file Lanceur.cpp
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


Lanceur::Lanceur(){
  o1=nullptr;
}

Lanceur::Lanceur(Compteur* c){
  o1=(Obstacle*)c;
}
Lanceur::Lanceur(Clou* c){
  o1=(Obstacle*)c;
}

Lanceur::~Lanceur()
{
  delete o1;
}

void Lanceur::lancer()
{
  o1->recoitPalet();
}


