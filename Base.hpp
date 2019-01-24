#ifndef BASE_H
#define BASE_H
#include "Entite.hpp"
#include "Unite.hpp"

class Base: public Entite{
public:
  Base(joueurEnum j):Entite(100,j==jA?0:11,j){}
  ~Base(){}

  Unite* creerUnite(int i);
};

#endif
