#ifndef BASE_H
#define BASE_H
#include "Entite.hpp"
#include "Unite.hpp"

class Base: public Entite{
public:
  Base(int ptVie, int posi, joueurEnum j):Entite(ptVie,posi,j){}
  ~Base(){}

  Unite* creerUnite(int i);
};

#endif
