#ifndef ARCHER_H
#define ARCHER_H
#include "Entite.hpp"
#include "Unite.hpp"


class Archer : public Unite{
public:
  Archer(joueurEnum j) : Unite(8, j==jA?0:11,j,12,3,nullptr){
    int initPorteeArcher[3]={1,2,3};
    this->setPortee(initPorteeArcher);
  }
  ~Archer(){}

  void afficher();
};

#endif
