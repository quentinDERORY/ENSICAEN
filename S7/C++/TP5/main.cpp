#include <iostream>
#include <ostream>

#include "Ensemble.h"
#include "imageEnsemble.h"

using namespace std;


int main() {

  Ensemble<int> A, B;

  for (int i=5; i<8; i++) {
    A.ajoute(i);
    B.ajoute(i+2);
  }

  cout << A << endl;
  
  //Utilisation de l'itérateur
  Iterator<int> it(A);
  
    cout<< *it <<endl;
    while(it.hasNext()){
      it.next();
      cout<< *it <<endl;
    }
    //Réalisation de l'ensemble image
    Ensemble<int> Resultat;
    Fonc1<int> f(3,5);
    
    Resultat=imageEnsemble(A,f);

  Iterator<int> it2(Resultat);  cout << "Affichage du résultat" <<endl;
    cout<< *it2 <<endl;
    while(it2.hasNext()){
      it2.next();
      cout<< *it2 <<endl;
    }
  return 0;
}
