#ifndef IA_H
#define IA_H
#include "Joueur.hpp"
class IA: public Joueur{
public:
  IA(int argent):Joueur(argent){}
  ~IA(){}
};

#endif
