#pragma once
#include "Entite.hpp"
#include "Unite.hpp"


class Archer : public Unite{
public:
  Archer(joueurEnum j) : Unite(8, j==jA?0:11,j,12,3){
    std::vector<int> v{1,2,3};
    this->portee = v;
  }
  ~Archer(){}

  void afficher();

  void phase2();
  void phase3(struct _Cible* c);
};
