#ifndef FANTASSIN_H
#define FANTASSIN_H
#include "Unite.hpp"
#include "Entite.hpp"

class Fantassin : public Unite{
  bool superSoldat;
public:
  Fantassin(int ptVie, int posi, joueurEnum j, int p, int attaque,std::vector<int> v) :
    Unite(ptVie, posi,j,p,attaque,v){superSoldat=false;}
  ~Fantassin(){}

  bool isSuperSoldat();
  void attaquer(Entite& e);
};

#endif
