#include <iostream>
#include <magasin.h>
#include <cstdlib>


int main()
{
  float prix;
  float& ref=prix;
  Article art1, art2;
  Article &a1=art1, &a2=art2;
  Article* tab;
  

  /*
//2.2.1
cout << lecture_prix() << endl;
  
  lecture_prix(&prix);
  cout << prix << endl;

  value::lecture_prix(prix);
  cout << prix << endl;

  reference::lecture_prix(ref);
  cout << prix << endl;
  */

  /*
//2.2.2
art=saisie_articles();
  cout << art.prix << endl << art.designation << endl;
  */

  //2.4
   tab=(Article*)malloc(sizeof(Article)*3);

  saisie_articles(tab,3);

  blague_bis(tab,3);

  /* 
//3.
echange_prix(saisie_articles(),saisie_articles());
/



  return 0;
}
