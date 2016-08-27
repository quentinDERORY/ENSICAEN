#include <iostream>
#include <Compteur.h>

/**
 * @file Compteur.cpp
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


Compteur::Compteur()
{
  compt=0;
  _successeur=nullptr;
}

Compteur::Compteur(Compteur* successeur){
compt=0;
_successeur=successeur;
//Si son successeur est orphelin il devient son fils
 if(successeur->est_orphelin())
   {
     successeur->set_orphelin(false);
     pere=true;
     }
}

Compteur::~Compteur()
{
  if(pere)
    delete _successeur;
}
   
void Compteur::recoitPalet(){
  compt++;
  if(_successeur)
    _successeur->recoitPalet();
}
