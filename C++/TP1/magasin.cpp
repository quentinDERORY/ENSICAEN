#include <iostream>
#include <magasin.h>



//2.2.1
float lecture_prix(void)
{
  float res=0;

  cout << "Prix de l'article" << endl;
  while(res<=0)//Vérification de la condition
    cin >> res;

  return res;
}

void lecture_prix(float* prix)
{
 
  *prix=lecture_prix();
}

namespace value{
  void lecture_prix(float prix)
  {
    prix=::lecture_prix();
  }
}

namespace reference{
  void lecture_prix(float& prix)
  {
    prix=::lecture_prix();
  }
}


//2.2.2
Article saisie_articles(void)
{
  Article art;

  art.prix=lecture_prix();
  cout << "Designation de l'article" << endl;
  cin >> art.designation;

  return art;
}

//2.2.3
void saisie_articles(Article* tab,int taille)
{
  int i=0;
  if(taille!=0 && tab)
    {
 
      while(i<taille)//On appelle la fonction précédente pour rentrer les articles un à un
	{
	  tab[i]=saisie_articles();
	  i++;
	}
    }
}

//2.3
void affiche_articles(Article art)
{
  
      cout << "Le nom de l'article" << endl << art.designation << endl << "Le prix de l'article " << endl << art.prix << endl;
    
}

void affiche_articles(Article* art,int taille)
{
  int i;
  if(art)
    {
      for(i=0;i<taille;i++)//On appelle la fonction précédente pour chaque article
	affiche_articles(art[i]);
    }
}

//2.4.1

void echange_prix(Article & a1,Article & a2)
{
  int tmp;
  tmp=a1.prix;
  a1.prix=a2.prix;
  a2.prix=tmp;
}

//2.4.2

Article & prix_min(Article* tab,int taille)
{
  int* tmp;

  if(taille==1)//Si il n'y a qu'un article c'est forcément le moins cher
    {
      Article & resultat=tab[0];
      return resultat;
    }

  //Variable stockant l'emplacement et le prix de l'article avec le prix minimal
  tmp=(int*)malloc(sizeof(int)*2);

  tmp[0]=0;
  tmp[1]=tab[0].prix;
  for(int i=1;i<taille;i++)//On parcours toute la liste d'article
    {
      if(tab[i].prix<tmp[1])//On compare chaque prix pour trouver le plus petit
	{
	  tmp[1]=tab[i].prix;
	  tmp[0]=i;
	}
    }
  Article & resultat=tab[tmp[0]];
  free(tmp);
  return resultat;
}

Article & prix_max(Article* tab,int taille)
{
  int* tmp;

  if(taille==1)//Si il n'y a qu'un article c'est forcément le plus cher
    {
      Article & resultat=tab[0];
      return resultat;
    }

  //Variable stockant l'emplacement et le prix de l'article avec le prix maximal
  tmp=(int*)malloc(sizeof(int)*2);

  tmp[0]=0;
  tmp[1]=tab[0].prix;
  for(int i=1;i<taille;i++)//On parcours toute la liste d'article
    {
      if(tab[i].prix>tmp[1])//On compare chaque prix pour trouver le plus grand
	{
	  tmp[1]=tab[i].prix;
	  tmp[0]=i;
	}
    }
  Article & resultat=tab[tmp[0]];
  free(tmp);
  return resultat;
}

//2.4.3


void blague(Article* tab,int taille)
{

  echange_prix(prix_max(tab,taille),prix_min(tab,taille));

  affiche_articles(tab,taille);
}
  
//2.4.4

void blague_bis(Article* tab,int taille)
{
  Article & Amin=prix_min(tab,taille);//Sauvegarde de l'article le moins cher dans une variable intermédiaire
  Article & Amax=prix_max(tab,taille);//Sauvegarde de l'article le plus cher dans une variable intermédiaire

  echange_prix(Amin,Amax);

affiche_articles(tab,taille);
}
