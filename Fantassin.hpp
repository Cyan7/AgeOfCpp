#ifndef FANTASSIN_H
#define FANTASSIN_H
#include "Unite.hpp"
#include "Entite.hpp"


class Fantassin : public Unite{
  bool superSoldat;
public:
  Fantassin(joueurEnum j) :
    Unite(10, j==jA?0:11,j,10,4){
      std::vector<int> v{1};
      this->portee = v;
      superSoldat=false;
    }
  ~Fantassin(){}

  bool isSuperSoldat();

  void promouvoir();

  void afficher();

  void phase2();
  void phase3(struct _Cible* c);
};

#endif
