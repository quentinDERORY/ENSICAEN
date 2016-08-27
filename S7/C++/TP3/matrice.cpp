#include <iostream>
#include <matrice.h>
#include <string.h>
#include <ctime>
#include <exception>

int Matrice::count=0;

Matrice::Matrice(){
  _ligne=0;
  _colonne=0;
  _tableau=nullptr;
}

Matrice::Matrice(int ligne,int colonne){
  _ligne=ligne;
  _colonne=colonne;
  _tableau=nullptr;
}

Matrice::Matrice(const Matrice & m){
  _ligne=m._ligne;
  _colonne=m._colonne;
  

  if(m._tableau)
    {
      _tableau=(float*)malloc(sizeof(float)*m._ligne*m._colonne);
      memcpy(_tableau,m._tableau,_colonne*_ligne*sizeof(float));
    }
  else
    {
      _tableau=nullptr;
    }
}

Matrice::Matrice(Matrice && m ){

  cout << "Constructeur par déplacement : " << m << endl ;
  _ligne=m._ligne;
  _colonne=m._colonne;

  if(m._tableau)
    _tableau=m._tableau;
  else
    _tableau=nullptr;

  m._ligne=0;
  m._colonne=0;
  m._tableau= nullptr;
}

Matrice & Matrice::operator=(const Matrice & autre){
  if( this == &autre ) return *this;

  _ligne=autre._ligne;
  _colonne=autre._colonne;
  if(_tableau)
    free(_tableau);

  if(autre._tableau)
    {
      _tableau=(float*)malloc(sizeof(float)*autre._ligne*autre._colonne);
      memcpy(_tableau,autre._tableau,_colonne*_ligne*sizeof(float));
    }
  else
    {
      _tableau=nullptr;
    }

	return *this;
    }

  Matrice & Matrice::operator=(Matrice && autre){

    cout << "Opérateur d'affectation par déplacement : " << autre  << "dans " << *this << endl;
    
    if(_tableau)
         free(_tableau);

    _ligne=autre._ligne;
    _colonne=autre._colonne;

    if(autre._tableau)
      {
	_tableau=(float*)malloc(sizeof(float)*autre._ligne*autre._colonne);
	_tableau=autre._tableau;
	autre._tableau=nullptr;
      }
    else
      {
	_tableau=nullptr;
      }
    autre._ligne=0;
    autre._colonne=0;

    return *this;
  }

  Matrice::~Matrice(){
    if(_tableau)
      free(_tableau);
  }

  Matrice  operator+(const Matrice & m1,const Matrice & m2)  {

    if(m1._ligne == m2._colonne && m1._ligne == m2._colonne)
      {
	Matrice resultat(m1._ligne,m1._colonne);
	resultat._tableau=(float*)malloc(sizeof(float)*m1._ligne*m1._colonne);
     
	if(m1._tableau && m2._tableau)
	  {
	    int j=0;
	    //Addition si toutes les conditions réunies
	    for(int i=0;i<m1._colonne*m1._ligne;i++)
	      {
		resultat._tableau[i]=m1._tableau[i]+m2._tableau[i];
		if( resultat._tableau[i] == 0 )
		  j++;
	      }
	    if( j == m1._ligne*m1._colonne )
	      free(resultat._tableau);
	  }
	else
	  {
	    //Si la matrice m2 ne contient pas de valeurs
	    if(m1._tableau)
	      {
		memcpy(resultat._tableau,m1._tableau,m1._colonne*m1._ligne*sizeof(float));
	      }
	    else
	      //Si la matrice m1 ne contient pas de valeurs
	      {   
		memcpy(resultat._tableau,m2._tableau,m2._colonne*m2._ligne);
	      }
	  }
	return resultat;
      }
    else
      {
	throw exc_fat("Problème de taille"); 
      }
  }

  Matrice operator-(const Matrice & m1,const Matrice & m2)
  {
    if(m1._ligne == m2._colonne && m1._ligne == m2._colonne)
      {
	Matrice resultat(m1._ligne,m1._colonne);
	resultat._tableau=(float*)malloc(sizeof(float)*m1._ligne*m1._colonne);
     
	if(m1._tableau && m2._tableau)
	  {
	    int j=0;
	    //Soustraction lorsque les matrices sont de meme taille et qu'elles ne sont pas vides
	    for(int i=0;i<m1._colonne*m1._ligne;i++)
	      {
		resultat._tableau[i]=m1._tableau[i]-m2._tableau[i];
		if(resultat._tableau[i] == 0)
		  j++;
	      }
	    //Verification de la contenance de la matrice résultat
	    if(j == m1._ligne*m1._colonne)
	      free(resultat._tableau);
	  }
	else
	  {
	    if(m1._tableau)
	      {
		//Si m2 est vide le résultat est ce que contient m1
		memcpy(resultat._tableau,m1._tableau,m1._colonne*m1._ligne*sizeof(float));
	      }
	    else
	      {
		//Si m1 est vide le resultat est ce que contient m2 négativement
		for(int i=0;i<m2._ligne*m2._colonne;i++)
		  resultat._tableau[i]=-m2._tableau[i];
	      }
	  }
	return resultat;
      }
    else
      {
	throw "Problème de taille"; 
      }
  }


  Matrice  Matrice::operator-(){
    Matrice res(this->_ligne,this->_colonne);

    if(!this->_tableau) return res;

    res._tableau=(float*)malloc(sizeof(float)*res._ligne*res._colonne);
    for(int i=0;i<this->_ligne*this->_colonne;i++)
      {
	res._tableau[i]=-this->_tableau[i];
      }
    return res;
  }

 Matrice operator*(const Matrice & m1,const Matrice & m2)
 {
   if(m1._colonne!=m2._ligne)
     throw exc_fat("Incompabilité de tailles:multiplication impossible");

   Matrice resultat(m1._ligne,m2._colonne);
   
   //Si l'une des deux matrice est nulle alors le résultat sera une matrice nulle
   if( !m1._tableau || !m2._tableau )
     return resultat;

   resultat._tableau=(float*)malloc(sizeof(float)*m1._ligne*m2._colonne);

   int verif = 0 ;

   //On réalise la multiplication matricielle
   for(int i=0;i<m1._ligne;i++)
     {
       for(int j=0;j<m2._colonne;j++)
	 {
	   float tmp=0.0;
	   for(int k=0;k<m1._colonne;k++)
	     {
	       tmp+=m1._tableau[i*m1._colonne+k]*m2._tableau[k*m2._colonne+j];
	     }
	   if( tmp == 0 )
	     verif++;
	   resultat._tableau[i*resultat._colonne+j]=tmp;
	 }
     }

   //Si la matrice est nulle,on ne stocke pas la matrice nulle
   if( verif == resultat._ligne*resultat._colonne )
     free(resultat._tableau);

   return resultat;


 }

Matrice operator*(const Matrice & m1,float x)
{
  Matrice resultat(m1._ligne,m1._colonne);
  if(!m1._tableau || x==0.0)
    return resultat;

  resultat._tableau=(float*)malloc(sizeof(float)*m1._ligne*m1._colonne);

  for(int i=0;i<m1._ligne*m1._colonne;i++)
    resultat._tableau[i]=m1._tableau[i]*x;

  return resultat;
}
    

Matrice operator*(float x,const Matrice & m1)
{
  Matrice resultat(m1._ligne,m1._colonne);
  if(!m1._tableau || x==0.0)
    return resultat;

  resultat._tableau=(float*)malloc(sizeof(float)*m1._ligne*m1._colonne);

  for(int i=0;i<m1._ligne*m1._colonne;i++)
    resultat._tableau[i]=x*m1._tableau[i];

  return resultat;
}
    

ostream& operator<<(ostream &out,Matrice m)
{
  out << "Matrice avec " << m._ligne << " et " << m._colonne << endl;

  if(m._tableau)
    {

      for(int i=0;i<m._ligne;i++)
	{
	  for(int j=0;j<m._colonne;j++)
	    {
	      out << m._tableau[i*m._colonne + j] << "  " ;
	    }
	  out << endl;
	}
    }
  else
    {
      out << "Matrice nulle " <<endl;
    }
  return  out;
}

  istream & operator>>( istream & in,Matrice & m )
  {
    cout << "Nombre de lignes ? ";
    in >> m._ligne;

    cout << "Nombre de colonne ? ";
    in >> m._colonne;

    if(m._tableau)
      free(m._tableau);

    char c=0;
    while(c!= 'o' && c!= 'n')
      {
	cout << "Voulez vous que la matrice soit non nulle ? [o/n]";
	  in >> c;
      }
    if( c == 'n' )
      {
	m._tableau=nullptr;
	return in;
      }
    m._tableau=(float*)malloc(sizeof(float)*m._ligne*m._colonne);
    for(int i=0;i<m._ligne;i++)
      {
	for(int j=0;j<m._colonne;j++)
	  {
	    cout << "valeur[" << i << "][" << j << "]" << endl;
	    in >> m._tableau[i*m._colonne + j] ;
	  }

      }
    return in;

  }
  //Principe d'encapsulation nn respecté 
  float  Matrice:: operator()(int i,int j){
    if( i<this->_ligne && j<this->_colonne )
      {
	if(this->_tableau)
	  return this->_tableau[i*this->_colonne + j];
	else
	  return 0.0;
      }

    else
      {
	throw exc_fat("Problème de débordement d'indices");
      }
  }

  Matrice Matrice::transpose(){
    Matrice t(this->_ligne,this->_colonne);
    if(this->_tableau)
      {
	t._tableau=(float*)malloc(sizeof(float)*this->_ligne*this->_colonne);
	for(int i=0;i<this->_ligne;i++)
	  {
	    for(int j=0;j<this->_colonne;j++)
	      {	
		t._tableau[i*this->_colonne+j]=this->_tableau[j*this->_colonne+i];	
	      }
	  }
      }
    return t;
  }



Matrice Matrice::mat_red(int row_delete,int column_delete)
{
  if(row_delete>=_ligne || column_delete>=_colonne)
    throw exc_fat("Depassement de la taille de la matrice");

  Matrice resultat(_ligne-1,_colonne-1);
  if(!_tableau)
    return resultat;

  resultat._tableau=(float*)malloc(sizeof(float)*resultat._ligne*resultat._colonne);

  for(int i=0;i<_ligne;i++)
    {
      for(int j=0;j<_colonne;j++)
	{
	  //On ne veut pas les éléments situés sur la colonne et ligne voulues
	  if(i!=row_delete && j!=column_delete)
	    {
	      if(i>row_delete && j>column_delete)
		resultat._tableau[(i-1)*resultat._colonne+j-1]=_tableau[i*_colonne+j];
	      else
		//On ajuste à la nouvelle taille de matrice
		{
		  if(i>row_delete)
		    resultat._tableau[(i-1)*resultat._colonne+j]=_tableau[i*_colonne+j];
		  if(j>column_delete)
		    resultat._tableau[i*resultat._colonne+j-1]=_tableau[i*_colonne+j];
		  if(i<row_delete && j<column_delete)
		    resultat._tableau[i*resultat._colonne+j]=_tableau[i*_colonne+j];
		}
	    }
	}
    }
  return resultat;
}


double Matrice::determinant(){

  this->count++;

  if(_ligne!=_colonne)
    throw exc_fat("Matrice non carrée,impossibilité de calculer le déterminant");

  if(!_tableau)
    return 0.0;

  double res=0.0;

  //Si la matrice ne contient qu'un élément,cette élément est le déterminant
  if(_ligne==1)
    return (double)_tableau[0];

  //Pour simplifier l'écriture je développe mon déterminant par rapport à la première ligne
  for(int i=0;i<_ligne;i++)
    {
      res+=puiss_moins(i)*_tableau[i]*(*this).mat_red(0,i).determinant();
    }
  return res;


}

double Matrice::cofacteur(int ligne,int colonne)
{
  if(ligne>=_ligne || colonne>=_colonne)
    throw exc_fat("Depassement de la taille de la matrice");

  if(_ligne!=_colonne)
    throw exc_fat("Matrice non carrée,impossibilité de calculer le cofacteur");

  //(-1)^(ligne+colonne)*delta(ligne,colonne)
  return puiss_moins(ligne+colonne)*(*this).mat_red(ligne,colonne).determinant();
}


Matrice Matrice::comatrice(){
  if(_ligne!=_colonne)
    throw exc_fat("Matrice non carrée,impossible de calculer sa comatrice");

  Matrice res(_ligne,_colonne);

  if(!_tableau)
    return res;

  int tmp=0;

 res._tableau=(float*)malloc(sizeof(float)*_ligne*_colonne);

  for(int i=0;i<_ligne;i++)
    {
      for(int j=0;j<_colonne;j++)
	{
	  res._tableau[i*_colonne+j]=(*this).cofacteur(i,j);
	  if(res(i,j)==0)
	    tmp++;
	}
    }

  if(tmp==_ligne*_colonne)
    free(res._tableau);

  return res;
}

Matrice Matrice::inverse(){
  if(_ligne!=_colonne)
    throw exc_fat("Matrice non carrée,impossible de l'inverser");
  double det= (*this).determinant();
  if(det == 0)
    throw exc_low("determinant nulle,impossible de l'inverser");

  Matrice resultat=(*this).comatrice().transpose();

  resultat= resultat *  (float)(1/det);

  return resultat;
}
  
int Matrice:: get_count()
{
  return  this->count;
}

void Matrice::  reset_count()
{
  count=0;
}


void Matrice::rand_mat(int ligne,int colonne)
{
  //matrice aléatoires

  _ligne=ligne;
  _colonne=colonne;
  if(_tableau)
    free(_tableau);

  srand(time(NULL));
  _tableau=(float*)malloc(sizeof(float)*_ligne*_colonne);
  for(int i=0;i<_ligne*_colonne;i++)
    _tableau[i]=rand();
  
}


double puiss_moins(int i)
{
  if(i%2==0 )
    return 1.0;
  else
    return -1.0;
}

void foo( Matrice m ){
}

const char* exc_fat::what() const throw()
{
  return _err.c_str();
}
const char* exc_low::what() const throw()
{
  return _err.c_str();
}
