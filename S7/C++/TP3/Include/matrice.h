using namespace std;

#ifndef MATRICE_H
#define MATRICE_H


class Matrice{
public :
Matrice();
Matrice(int ligne,int colonne);
Matrice(const Matrice & m);
Matrice(Matrice && m);

Matrice & operator=(const Matrice & autre);
Matrice & operator=(Matrice && autre);

~Matrice();

friend Matrice  operator+(const Matrice & m1,const Matrice & m2);
friend Matrice  operator-(const Matrice & m1,const Matrice & m2);
Matrice operator-();
friend Matrice operator*(const Matrice & m1,const Matrice & m2);
friend Matrice operator*(const Matrice & m1,float x);
 friend Matrice operator*(float x,const Matrice & m1);
friend ostream& operator<<(ostream &out,Matrice m);
friend istream & operator>>( istream & in,Matrice & m);
float  operator()(int i,int j);

Matrice transpose();
Matrice mat_red(int row_delete,int column_delete);
double determinant();
double cofacteur(int ligne,int colonne);
Matrice comatrice();
Matrice inverse();

int get_count();
void reset_count();
void rand_mat(int ligne,int colonne);

private :
static int count;
int _ligne;
int _colonne;
float* _tableau;

};

class exc_fat : public exception{

 public:
  exc_fat(string err) throw():_err(err){};

  const char* what() const throw();

 private:
  string _err;
  
};

class exc_low : public exception{

 public:  
exc_low(string err) throw():_err(err){};

  const char* what() const throw();

 private:
  string _err;
  
};

void foo( Matrice m );
double puiss_moins(int i);
#endif
