#include <iostream>
#include <Planche.h>
#include <math.h>

/**
 * @file Planche.cpp
 * @author Mauranyapin Jean-Baptiste 
 * @auhor Derory Quentin
 * @version 1.0
 * @date 13 novembre 2014
 * */


Planche::Planche(int nbr_compt){
  
  _nombre_compteurs=nbr_compt;
  _tab_compt=new Compteur* [_nombre_compteurs];
  _tab_compt[_nombre_compteurs-1]=new Compteur();
  Compteur & _compteur_final= *(_tab_compt[_nombre_compteurs-1]);
  //On vérifie le nombre de compteurs voulue
  if(_nombre_compteurs == 1)//1 compteur
    {
      _lanceur=new Lanceur(&_compteur_final); //lanceur directement relié à l'unique compteur
    }
  else
    {
      for(int i=0;i<_nombre_compteurs-1;i++)//On construit le tableau de  compteurs
	{
	  _tab_compt[i]=new Compteur(&_compteur_final);
	}
      int j;
      //On se sert d'un tableau de clou local à la fonction pour créer les différents clous
      Clou*** tab_clous=new Clou**[nbr_compt-2];
      for(int i=_nombre_compteurs-2;i>0;i--)
	{
	  tab_clous[i-1]=new Clou*[i];
	  for(j=i;j>0;j--)
	    {
	      if(i == _nombre_compteurs-2)
		{
		  //on construit les clous sur la dernière ligne, ceux qui ont des compteurs comme successeurs
		  tab_clous[i-1][j-1] = new Clou(_tab_compt[j],_tab_compt[j-1]);
		}
	      else
		{
		  //on construit les clous qui ont des clous comme successeurs
		  tab_clous[i-1][j-1] = new Clou(tab_clous[i][j],tab_clous[i][j-1]);
		}
	    }
	}
      _lanceur=new Lanceur(tab_clous[0][0]);
      
    }
}


    
void Planche::simulation(int N)
{
  //On effectue les lancés de palets
  for(int i=0;i<N;i++)
    _lanceur->lancer();

  int c0=_tab_compt[0]->get_compt();
  //On vérifie la nullité du premier compteur
  if(c0!=0)
    {
      for(int i=0;i<_nombre_compteurs;i++)
	{
	  cout << round(_tab_compt[i]->get_compt()/c0) << ", " ;
	}
    }
  else
    {
      cout << "Le compteur à l'emplacement 0 n'a pas rencontré de palet" << endl;
      cout << "Affichage uniquement des valeurs des différents compteurs" << endl;
      for(int i=0;i<_nombre_compteurs;i++)
	{
	  cout << _tab_compt[i]->get_compt() << ", " ;
	}
    }
  cout << endl;
}

void Planche::affichage(){
}

Planche::~Planche(){
  
  delete _lanceur;
  delete[] _tab_compt;
 
}

