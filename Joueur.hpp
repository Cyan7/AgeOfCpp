#ifndef JOUEUR_H
#define JOUEUR_H
#include "Unite.h"

class Joueur{
  int or;
public:
  Joueur(int argent):or(argent){}
  ~Joueur(){}

  int getOr();
  void setOr(int argent);

  Unite creerUnite(char u);
}

#endif
