#ifndef ARCHER_H
#define ARCHER_H
#include "Entite.hpp"
#include "Unite.hpp"

class Archer : public Unite{
public:
  Archer(int ptVie, int posi, joueurEnum j, int p, int attaque,std::vector<int> v) : Unite(ptVie, posi,j,p,attaque,v){}
  ~Archer(){}

  void attaquer(Entite& e);
};

#endif
