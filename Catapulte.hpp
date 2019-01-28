#pragma once
#include "Unite.hpp"
#include "Entite.hpp"


class Catapulte : public Unite{
public:
  Catapulte(joueurEnum j) : Unite(12, j==jA?0:11,j,20,6){
    std::vector<int> v{2,3,4};
    this->portee = v;
  }
  ~Catapulte(){}

  void afficher();

  void phase2();
  void phase3(struct _Cible* c);
};
