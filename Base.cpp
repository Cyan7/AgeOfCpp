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
      {Fantassin f(this->joueur);
      unit = &f;}
    case archer :
      {Archer a(this->joueur);
      unit = &a;}
    default :
      {Catapulte c(this->joueur);
      unit = &c;}
  }
  return unit;
}
