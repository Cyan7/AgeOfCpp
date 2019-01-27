#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "Unite.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"

void Base::afficher(){
  std::cout << "|    |";
}

Unite* Base::creerUnite(unitEnum u){
  Unite* unit;
  switch(u){
    case fantassin :
      unit = new Fantassin(this->joueur);
      break;
    case archer :
      unit = new Archer(this->joueur);
      break;
    default :
      unit = new Catapulte(this->joueur);
      break;
  }
  return unit;
}
