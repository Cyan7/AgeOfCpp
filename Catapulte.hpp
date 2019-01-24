#ifndef CATAPULTE_H
#define CATAPULTE_H
#include "Entite.hpp"
#include "Unite.hpp"

class Catapulte : public Unite{
public:
  Catapulte(int ptVie, int posi, joueurEnum j, int p, int attaque,int* v) : Unite(ptVie, posi,j,p,attaque,v){}
  ~Catapulte(){}

  void attaquer(Entite& e);
};

#endif
