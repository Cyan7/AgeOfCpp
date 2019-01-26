#ifndef FANTASSIN_H
#define FANTASSIN_H
#include "Unite.hpp"
#include "Entite.hpp"


class Fantassin : public Unite{
  bool superSoldat;
public:
  Fantassin(joueurEnum j) :
    Unite(10, j==jA?0:11,j,10,4,nullptr){
      int initPorteeFantassin[1]={1};
      this->setPortee(initPorteeFantassin);
      superSoldat=false;}
  ~Fantassin(){}

  bool isSuperSoldat();

  void promouvoir();
};

#endif
