#ifndef JOUEUR_H
#define JOUEUR_H
#include "Unite.hpp"

class Joueur{
  int gold;
public:
  Joueur(int argent):gold(argent){}
  ~Joueur(){}

  int getOr();
  void setOr(int argent);

  Unite* creerUnite(char u);
};

#endif
