#include <iostream>
#include <cstdlib>
#include <string>
#include "Archer.hpp"

void Archer::afficher(){
  std::string team = joueur == jA ? "A" : "B";
  if (this->position!=0){
    std::string perso = "Arc" + team;
    std::cout << perso;
  }
  else {
    std::string perso = "|Arc" + team + "|";
    std::cout << perso;
  }
}
