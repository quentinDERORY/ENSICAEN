#include <iostream>
#include <math.h>

class Complexe{

public:
  Complexe(){ 
    re = im = 0.0;
    std::cout << "adresse de l'objet   " << this << "   +++Complexe()" << std::endl; 
  }

  
  Complexe(double r,double i = 0.0){
    re=r;
    im=i;
    std::cout << "adresse de l'objet   " << this << "   +++Complexe(" << r << "," << i << ")" << std::endl ;
  }

  Complexe(const Complexe& c){
    re=c.re;
    im=c.im;
    std::cout << "adresse de l'objet   " << this << "   objet recopié   " << &c << "   rrrComplexe(" << re << "+ i." << im << ")" << std::endl;
  }

  ~Complexe() {
    std::cout << "adresse de l'objet   " << this << "   ---Complexe(" << re << "+ i." << im << ")" << std::endl;
  }
 

  Complexe & operator=(const Complexe& autre)
  {
    if (this == &autre) return *this;
   
    re=autre.re;
    im=autre.im;
    std::cout << "adresse de l'objet   " << this << "   objet recopié   " << &autre  << "   op=Complexe("  << re << "+ i." << im << ")" << std::endl;
    return *this;
     
  }

  double get_real(){
    return re;
  }

  double get_im(){
    return im;
  }

  double get_mod(){
    return sqrt(re*re+im*im);
  }
  
  double get_arg(){
    if(re!=0)
    return atan(im/re);
    if(im>0)
      return M_PI/2;
    else
      return -M_PI/2;
  }

  void print(){
    std::cout << re << " + i*" << im << std::endl;
  }
 
  void swap(){
    double tmp;
    tmp=re;
    re=im;
    im=tmp;
  }


  

private:
  double re;
  double im;
};


Complexe operator+(Complexe& c1,Complexe& c2)
{
  double r=c1.get_real()+c2.get_real();
  double i=c2.get_im()+c1.get_im();
  Complexe c(r,i);
  return c;
}

Complexe operator*(Complexe& c1,Complexe& c2)
{
  double r=c1.get_real()*c2.get_real()-c1.get_im()*c2.get_im();
  double i=c1.get_real()*c2.get_im()+c2.get_real()*c1.get_im();
  Complexe c(r,i);
  return c;
}

Complexe operator-(Complexe& c1,Complexe& c2)
{
  double r=c1.get_real()-c2.get_real();
  double i=c2.get_im()-c1.get_im();
  Complexe c(r,i);
  return c;
}


Complexe somme_comp(Complexe c1,Complexe c2)
{
 

  return c1+c2;
}

Complexe diff_comp(Complexe c1,Complexe c2)
{
  return c1-c2;
}

Complexe produit_comp(Complexe c1,Complexe c2)
{
  
  return c1*c2;
}

Complexe normalise(Complexe c)
{
  std::cout << "normalise" << std::endl;
  if(c.get_real() == 0 && c.get_im() == 0)
      return Complexe();

  double module=c.get_mod();
  Complexe resultat(c.get_real()/module,c.get_im()/module);
  return resultat;
}
  

Complexe rotation(Complexe& c,double angle)
{
  std::cout << "rotation" << std::endl;
  return Complexe(c.get_mod() * cos(c.get_arg() + angle), c.get_mod() * sin(c.get_arg() + angle));
  
}

Complexe& max_mod(Complexe z1,Complexe z2)
{
  std::cout << "max_mod" << std::endl;
  if( z1.get_mod() < z2.get_mod() )
    {
      Complexe & res=z2;
      return res;
    }
    
  Complexe & res= z1;
  return res;

}

void racine_unite(int n,Complexe* tab)
{
  std::cout << "racine_unite" << std::endl;
  tab[0]=Complexe(1,0);
  for(int i=1;i<n;i++)
    {
      tab[i]=produit_comp(Complexe(cos(2*M_PI/n),sin(2*M_PI/n)),tab[i-1]);
    }
}

/*
//3.5
Complexe foo( Complexe a, Complexe b )
{
  Complexe z(10,10);
  z = a;
  z = b;
  return z;
}

int main()
{
  Complexe z1(0,0);
  Complexe z2(1,1);
  Complexe z3(2,2);
  std::cout << "Appel de foo()\n";
  z3 = foo( z1, z2 );
  std::cout << "Fin de main()\n";
}
*/

int main()
{

  
  /*
    Complexe c1(5,5);
    //Partie 1.5
    double d=2;
    Complexe c3=somme_comp(c1,d);
  
    c3.print();
  */
  /*
//Partie 3.2
  Complexe c1(5,5);
  
  Complexe c2=normalise(c1);
  */
  /*
  //3.2
  Complexe c1(5,5);

  Complexe c2=rotation(c1,M_PI/2);
  */

  /*
    Complexe c1(5,5);
    //3.3
    Complexe z=max_mod(c1,c1*c1);
    z.print();
  */

  //3.4

  Complexe* tab=(Complexe *)malloc(sizeof(Complexe)*3);

  racine_unite(3,tab);


  return 0;
}

