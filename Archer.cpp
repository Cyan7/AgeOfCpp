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

void Archer::phase2(){
  avancer();
}

void Archer::phase3(struct _Cible* c){
  // RIENG
}
