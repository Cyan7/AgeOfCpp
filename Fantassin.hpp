#ifndef FANTASSIN_H
#define FANTASSIN_H
#include "Unite.hpp"
#include "Entite.hpp"

int p[1]={1};

class Fantassin : public Unite{
  bool superSoldat;
public:
  Fantassin(joueurEnum j) :
    Unite(10, j==jA?1:10,j,10,4,p){superSoldat=false;}
  ~Fantassin(){}

  bool isSuperSoldat();

  void promouvoir();
  void attaquer(Entite& e);
};

#endif
