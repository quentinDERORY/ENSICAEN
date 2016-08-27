/**
 * @file   Ensemble.h
 * @author Jb Mauranyapin
 * @author Quentin Derory
 * @date   Nov 2014
 * 
 * @brief Declaration de la classe Ensemble.  
 * 
 */
#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include <iostream>
#include <ostream>
#include <imageEnsemble.h>

using namespace std;

template<typename T>
class Ensemble {

  friend class Iterator<T>;
  
  class Noeud {
    T valeur;
    Noeud * suivant;
    
  public:
    
    Noeud(T valeur, Noeud * suivant=0) : valeur(valeur), suivant(suivant) {}
    
    ~Noeud() {
      if (suivant)
	delete suivant;
    }
    
    T getValeur() {
      return valeur;
    }

    Noeud * getSuivant() {
      return suivant;
    }

    void setSuivant(Noeud * suivant) {
      Noeud::suivant = suivant;
    }
  };

  Noeud * liste;

public:

  /** 
   * Construit un ensemble vide.
   */
  Ensemble():liste(0) {}

  /** 
   * Construit un singleton.
   */
  Ensemble(T x) {
    //    Noeud n(x);
    liste = new Noeud(x);
  }

  /** 
   * Destructeur.
   */
  ~Ensemble() {
    if (liste)
      delete(liste);
  }

  /** 
   * Test si l'ensemble est vide.
   *
   * @return true si l'ensemble est vide, sinon false.
   */
  inline bool estVide() {
    return liste == 0;
  }

  /** 
   * Envoie tous les elements dans un flot de sortie.
   * 
   * @param out un flot de sortie.
   * 
   * @return le flot de sortie donne en parametre.
   */
  std::ostream & flush(std::ostream & out) const {
    if(!liste)
      out << "{}" << std::endl;

    else {
      Noeud* courant = liste;
      out << "{";

      do {
	out << courant->getValeur() << ";";
	courant = courant->getSuivant();
      }	while(courant);

      out << "\b}";
    }

    return out;
  }

  /** 
   * Test l'appartenance d'un element a l'ensemble.
   * 
   * @param x un T.
   * 
   * @return true sie est dans l'ensemble, false sinon.
   */
  bool contient(T x) const {
    Noeud *n = liste;

    while(n) {
      if (n->getValeur() == x)
	return true;

      n = n->getSuivant();
    }

    return false;
  }
  
  /** 
   * Test l'inclusion dans un autre ensemble.
   * 
   * @param e un ensemble
   * 
   * @return true si "je" suis inclus dans e, false sinon.
   */
  bool estInclusDans(const Ensemble & autre) const {
    Noeud *n = liste;

    while (n) {
      if(!autre.contient(n->getValeur()))
	return false;

      n = n->getSuivant();
    }

    return true;
  }

  /** 
   * Ajoute un "objet" a l'ensemble.
   * 
   * @param x un T a ajouter à l'ensemble.
   */
  void ajoute(T x) {
    if (!this->contient(x)) {
      Noeud *n = new Noeud(x);
      n->setSuivant(liste);
      liste = n;
    }
  }

  /** 
   * Retire un T de l'esemble.
   * 
   * @param x un T a retirer.
   */
  void retire(T x) {
    Noeud *courant = liste;
    Noeud *suivant = courant;

    if (suivant->getValeur() == x) { // Cas de la tete de liste
      liste = suivant->getSuivant();
      suivant->setSuivant(nullptr); // Pour eviter de détruire toute la liste
      delete(suivant);
    }

    else {
      while(suivant && suivant->getValeur() != x) {
	courant = suivant;
	suivant = suivant->getSuivant();
      }
      
      if (suivant) {
	if (suivant->getSuivant()) {
	courant->setSuivant(suivant->getSuivant());
	suivant->setSuivant(0);
	delete(suivant);
	}
	
	else {
	  courant->setSuivant(nullptr);
	  delete(suivant);
	}
      }
    }
  }


  /** 
   * Ajoute tous les elements dans un autre ensemble.
   * 
   * @param e un ensemble
   */
  void ajouteDans(Ensemble & e) const {
    Noeud * courant = liste;

    while (courant) {
      if (!e.contient(courant->getValeur()))
	e.ajoute(courant->getValeur());

      courant = courant->getSuivant();
    }
  }

  /** 
   * Retire tous les elements dans un autre ensemble.
   * Apres a.enleveDe(b), b vaut b - a (- ensembliste)
   *
   * @param e un ensemble dont il faut retirer des elements.
   */
  void retireDe(Ensemble & e) const {
    Noeud * courant = liste;

    while (courant) {
      e.retire(courant->getValeur());
      courant = courant->getSuivant();
    }
  }


  /** 
   * Operateur d'affectation d'un ensemble.
   * 
   * @param e un ensemble
   * 
   * @return une reference a moi-meme
   */
  Ensemble & operator=(const Ensemble & e) {

    if (this == &e)
      return *this;

    if (liste || !e.liste) {
      delete(liste);

      if (!e.liste)
	return *this;
    }

    liste = new Noeud(e.liste->getValeur());
    Noeud * courant = e.liste->getSuivant();

    while (courant) {
      this->ajoute(courant->getValeur());
      courant = courant->getSuivant();
    }

    return *this;
  }

  /** 
   * Constructeur par recopie.
   * 
   * @param autre un ensemble
   */
  Ensemble(const Ensemble & autre) { 
    liste = new Noeud(0);
    this->retire(0);
    autre.ajouteDans(*this);
  }
  

private:

  /** 
   * Methode recursive de suppression d'un element dans
   * une liste chainee.
   *
   * @param liste une liste.
   * @param x un element.
   * 
   * @return la liste sans l'element.
   */
  Noeud * retireRec(Noeud * liste, T x) {
    //on rentre dans cette boucle qu'au premier appel
    if(liste->getValeur() == x) { 
	Noeud * tmp = liste;
	liste = liste->getSuivant();
	tmp->setSuivant(nullptr);
	delete tmp;
	return liste;
    }

    //On vérifie l'égalité du suivant pour pouvoir relier correctement la liste
    if(liste->getSuivant()) { 
      if(liste->getSuivant()->getValeur() == x) {
	Noeud * tmp = liste->getSuivant();
	liste->setSuivant(tmp->getSuivant());
	tmp->setSuivant(nullptr);
	delete tmp;
	return liste;
      }

      else {
	liste->setSuivant(retireRec(liste->getSuivant(),x));
	return liste;
      }
    }

    else
      return liste;
  }
};


/** 
 * Operateur << pour les enembles.
 * 
 * @param out un flot de sortie.
 * @param e un ensemble.
 * 
 * @return le flot de sortie donne en argument.
 */
template<typename T>
 std::ostream & operator<<(std::ostream & out, const Ensemble<T> & e)
{
  e.flush(out);

  return out; 
}

/** 
 * Creation d'un singleton.
 * 
 * @param x un element
 * 
 * @return le singleton {x}
 */
template <typename T>
Ensemble<T> singleton(T x) {
  return Ensemble<T>(x);
}

/** 
 * Creation d'un ensemble vide.
 * 
 * @param x un element
 * 
 * @return le singleton {x}
 */
template<typename T>
Ensemble<T> ensembleVide() {
  return Ensemble<T>();
}

/** 
 * Teste l'egalite de deux ensembles.
 * 
 * @param a un ensemble.
 * @param b un ensemble.
 * 
 * @return true si a=b (i.e., a est inclus dans b et b est inclus dans a),
 *         sinon false.
 */
template<typename T>
bool egale(const Ensemble<T> & a, const Ensemble<T> & b) {
  if(&a=&b)
    return true;

  if(a.estInclusDans(b) && b.estInclusDans(a))
    return true;

  return false;
}

template<typename T>
bool operator==(const Ensemble<T> & a, const Ensemble<T> & b) {
  if(&a==&b)
    return true;

  if(a.estInclusDans(b) && b.estInclusDans(a))
    return true;

  return false;
}

template<typename T>
bool operator<(const Ensemble<T> & a, const Ensemble<T> & b) {
  if(a.estInclusDans(b))
    return true;

  return false;
}

template<typename T>
bool operator>(const Ensemble<T> & a, const Ensemble<T> & b) {
  if(b.estInclusDans(a))
    return true;
  
  return false;
}



/** 
 * Union de deux ensembles.
 * 
 * @param a un ensemble.
 * @param b un ensemble.
 * 
 * @return a union b.
 */
template<typename T>
Ensemble<T> reunion(const Ensemble<T> & a, const Ensemble<T> & b) {
  Ensemble<T> resultat = a;
  b.ajouteDans(resultat);

  return resultat;
}

template<typename T>
Ensemble<T> operator+(const Ensemble<T> & a, const Ensemble<T> & b) {
  return reunion(a,b);
}

template<typename T>
Ensemble<T> operator|(const Ensemble<T> & a, const Ensemble<T> & b) {
  return reunion(a,b);
}

/** 
 * Difference de deux ensembles.
 * 
 * @param a un ensemble.
 * @param b un ensemble.
 * 
 * @return a prive de b.
 */
template<typename T>
Ensemble<T> difference(const Ensemble<T> & a, const Ensemble<T> & b) {
  Ensemble<T> resultat = a;
  b.retireDe(resultat);

  return resultat;
}

template<typename T>
Ensemble<T> operator-(const Ensemble<T> & a, const Ensemble<T> & b) {
  return difference(a,b);
}

/** 
 * Difference symetrique entre deux ensembles.
 * 
 * @param a un ensemble.
 * @param b un ensemble.
 * 
 * @return (a prive de b) union (b prive de a)
 */
template<typename T>
Ensemble<T> diffSymetrique(const Ensemble<T> & a, const Ensemble<T> & b) {
  return reunion(difference(a,b),difference(b,a));
}

template<typename T>
Ensemble<T> operator^(const Ensemble<T> & a, const Ensemble<T> & b) {
  return diffSymetrique(a,b);
}

/** 
 * Intersection entre deux ensembles.
 * 
 * @param a un ensemble.
 * @param b un ensemble.
 * 
 * @return l'intersection de a et b.
 */
template<typename T>
Ensemble<T> intersection(const Ensemble<T> & a, const Ensemble<T> & b) {
  return difference(reunion(a,b),diffSymetrique(a,b));
}

template<typename T>
Ensemble<T> operator&(const Ensemble<T> & a, const Ensemble<T> & b) {
  return intersection(a,b);
};


#endif
