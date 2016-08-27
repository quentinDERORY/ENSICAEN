#ifndef MAGASIN_H
#define MAGASIN_H
using namespace std;

struct Article{
  char  designation[30];
  float prix;
};


float lecture_prix(void);

void lecture_prix(float* art);


namespace value{
void lecture_prix(float art);
}

namespace reference{
void lecture_prix(float& art);
}

Article saisie_articles(void);

void saisie_articles(Article* tab,int taille);

void affiche_articles(Article art);

void affiche_articles(Article* art,int taille);

void echange_prix(Article & a1,Article & a2);

Article & prix_min(Article* tab,int taille);

Article & prix_max(Article* tab,int taille);

void blague(Article* tab,int taille);

void blague_bis(Article* tab,int taille);

#endif








