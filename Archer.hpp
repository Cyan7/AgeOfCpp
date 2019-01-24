#ifndef ARCHER_H
#define ARCHER_H
#include "Entite.hpp"
#include "Unite.hpp"

int p[3]={1,2,3};

class Archer : public Unite{
public:
  Archer(joueurEnum j) : Unite(8, j==jA?0:11,j,12,3,p){}
  ~Archer(){}

  void attaquer(Entite& e);
};

#endif
