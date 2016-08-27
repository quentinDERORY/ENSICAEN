using namespace std;


class Complexe{

 public:
  Complexe();
  Complexe(double r,double i);
  Comlexe(const Complexe& c);
  ~Complexe();
  Complexe & operator=(const Complexe& autre);


  double get_real();
  double get_im() ;
  double get_mod();
  double get_arg();
  void print();
  void swap();

 private:

  double re;
  double im;
}
Complexe operator+(const Complexe& c1,const Complexe& c2);
Complexe operator*(const Complexe& c1,const Complexe& c2);
Complexe operator-(const Complexe& c1,const Complexe& c2);
Complexe somme_comp(Complexe c1,Complexe c2);
Complexe diff_comp(Complexe c1,Complexe c2);
Complexe produit_comp(Complexe c1,Complexe c2);

Complexe normalise(Complexe c);
Complexe rotation(Complexe& c,double angle);
Complexe& max_mod(Complexe z1,Complexe z2);
void racine_unite(int n,Complexe* tab);
Complexe foo(Complexe a,Complexe b);
