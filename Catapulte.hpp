#ifndef CATAPULTE_H
#define CATAPULTE_H
#include "Entite.hpp"
#include "Unite.hpp"

int p[3]={2,3,4};

class Catapulte : public Unite{
public:
  Catapulte(joueurEnum j) : Unite(12, j==jA?0:11,j,20,6,p){}
  ~Catapulte(){}

  void attaquer(Entite& e);
};

#endif
