#ifndef JOUEUR_H
#define JOUEUR_H
#include "Unite.hpp"

#define PRIX_FANTASSIN (10)
#define PRIX_ARCHER (12)
#define PRIX_CATAPULTE (20)

class Joueur{
  int gold;
public:
  Joueur():gold(10){}
  Joueur(int argent):gold(argent){}
  ~Joueur(){}

  int getOr();
  void setOr(int argent);
  bool creerUnite(unitEnum type);
};

#endif
