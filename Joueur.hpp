#pragma once
#include "Unite.hpp"

#define PRIX_FANTASSIN (10)
#define PRIX_ARCHER (12)
#define PRIX_CATAPULTE (20)

enum typeJoueur {humain, ia};

class Joueur{
  int gold;
  typeJoueur type;

public:
  Joueur(typeJoueur tJ):gold(10), type(tJ){}
  //Joueur(int argent, typeJoueur tJ):gold(argent), type(tJ){}
  ~Joueur(){}

  int getOr() const;
  typeJoueur getType() const;
  void setOr(int argent);

  bool creerUnite(unitEnum type);
};
