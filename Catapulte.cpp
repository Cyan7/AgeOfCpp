#include <iostream>
#include <cstdlib>
#include "Catapulte.hpp"

void Catapulte::afficher(){
  std::string team = joueur == jA ? "A" : "B";
  if (this->position!=0){
    std::string perso = "Cat" + team;
    std::cout << perso;
  }
  else {
    std::string perso = "|Cat" + team + "|";
    std::cout << perso;
  }
}

void Catapulte::phase2(){
  // RIENG
}

void Catapulte::phase3(struct _Cible* c){
  avancer();
}
