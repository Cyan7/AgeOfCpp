#ifndef HUMAIN_H
#define HUMAIN_H
#include "Joueur.hpp"

class Humain : public Joueur{
public:
  Humain(int argent):Joueur(argent){}
  ~Humain(){}
};

#endif
