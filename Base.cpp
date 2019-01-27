#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "Unite.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"

void Base::afficher(){
  char a = joueur ==jA ? 'A' : 'B';
  std::cout << "Base" << a << std::endl;
  //TODO : afficher les pv
}

Unite* Base::creerUnite(unitEnum u){
  Unite* unit;
  switch(u){
    case fantassin :
      unit = new Fantassin(this->joueur);
      break;
    case archer :
      unit = new Fantassin(this->joueur);
      break;
    default :
      unit = new Fantassin(this->joueur);
      break;
  }
  return unit;
}
