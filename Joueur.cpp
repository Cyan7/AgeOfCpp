#include <iostream>
#include <cstdlib>
#include "Joueur.hpp"

int Joueur::getOr(){
  return gold;
}
void Joueur::setOr(int argent){
  gold=argent;
}

bool Joueur::creerUnite(unitEnum type){
  bool result;
  switch(type){
    case fantassin:
      result = gold >= PRIX_FANTASSIN;
      if (result) this->gold = gold - PRIX_FANTASSIN;
      return result;
    case archer:
      result = gold >= PRIX_ARCHER;
      if (result) this->gold = gold - PRIX_ARCHER;
      return result;
    case catapulte:
      result = gold >= PRIX_CATAPULTE;
      if (result) this->gold = gold - PRIX_CATAPULTE;
      return result;
  }
}
