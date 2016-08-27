/**
 * @file   imageEnsemble.h
 * @author Jb Mauranyapin
 * @author Quentin Derory
 * @date   Nov 2014
 * 
 * @brief Declaration et implémentation de la classe iterator et de la méthode imageEnsemble.  
 * 
 */
#ifndef IMAGEENSEMBLE_H
#define IMAGEENSEMBLE_H



#include "Ensemble.h"

template<typename T>
class Iterator {

 public:

  Iterator(Ensemble<T> &  F) {
    debut = F.liste;
    courant = debut;
  }

  bool hasNext() {
    if(courant->getSuivant())
      return true;

    return false;
  }

  void next() {
    if (courant->getSuivant())
      courant = courant->getSuivant();
  }

  void reset() {
    courant = debut;
  }

  T getCurrent() {
    return courant->getValeur();
  }


 private:
  typename Ensemble<T>::Noeud *debut;
  typename Ensemble<T>::Noeud *courant;
};


template <typename T>
T operator*(Iterator<T> & it) {
  return it.getCurrent();
}

  
template <typename T>
class Fonc {
 public:
  virtual T operator()(T x)=0;

};
//Exemple avec une fonction affine
  template <typename T>
  class Fonc1 : public Fonc<T> {
    int _A;
    int _B;
 public:
    Fonc1(int A,int B){
      _A=A;
      _B=B;
    }
  T operator()(T x){
  return _A*x+_B;
  }
  };



template<typename T> Ensemble<T>  imageEnsemble(Ensemble<T> & E,Fonc1<T> fonc)
{
  Iterator<T> it(E);
  Ensemble<T> F;
  //On va ajouter un a un les images des élements par la fonction fonc
    F.ajoute(fonc(it.getCurrent()));
    
  
  while(it.hasNext())
    {
      it.next();
      F.ajoute(fonc(it.getCurrent())); 
    }
 
    return F;
}



  




#endif
