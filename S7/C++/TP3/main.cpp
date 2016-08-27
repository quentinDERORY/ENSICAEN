#include <iostream>
#include <matrice.h>


int main(int argc,char* argv[])
  {
    /* Matrice* m=new Matrice[9];
    Matrice* inv=(Matrice*)malloc(9*sizeof(Matrice));
    
    //Experimentation
    
    for(int i=0;i<9;i++)
      { 
	m[i].rand_mat(i+2,i+2);
	while(m[i].determinant() == 0)
	  {
	   m[i].rand_mat(i+2,i+2);
	  }
    m[i].reset_count();
    inv[i]=m[i].inverse();
    cout  << " Pour la matrice" << i+2 << "*" << i+2 << ", le nombre de calculs intermédiaires de déterminants s'élèvent à " << m[i].get_count() << endl ;
      }
    */
    /*
La formule vérifiée empiriquement est la suivante

Nombre d'appels au detérminant=(n*n)*C(det(n-1))+n*C(det(n-1))+1

ou n est la taille de la matrice carrée et C(det(n)),le nombre d'appel à la fonction déterminant pour le calcul d'une matrice carrée de taille n(incluant l'appel initial de la fonction déterminant)
    */ 

    
    //Verifications

    Matrice* tmp=new Matrice[1];

    try{
    for(int i=0;i<4;i++)
      {
	cin >> tmp[i];
	cout << tmp[i] << tmp[i].inverse() ;
      }
    }
    catch(exc_fat e)
      {
	cout << "ERREUR FATALE :" << e.what() << endl ;
      }
    
    return 0;
  }

