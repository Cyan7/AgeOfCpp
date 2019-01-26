#ifndef CATAPULTE_H
#define CATAPULTE_H
#include "Unite.hpp"
#include "Entite.hpp"


class Catapulte : public Unite{
public:
  Catapulte(joueurEnum j) : Unite(12, j==jA?0:11,j,20,6,nullptr){
    int initPorteeCatapulte[3]={2,3,4};
    this->setPortee(initPorteeCatapulte);
  }
  ~Catapulte(){}

  void afficher();
};

#endif
