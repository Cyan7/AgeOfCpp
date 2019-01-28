#include <iostream>
#include <cstdlib>
#include <string>
#include "Archer.hpp"

void Archer::afficher(){
  std::string team = joueur == jA ? "\033[34m" : "\033[31m";
  if (this->position!=0 && this->position != 11){
    //std::cout << std::setw(7) << std::left;
    std::cout << team + "Arc    \033[0m";
  }
  else {
    //std::cout << std::setw(7) << std::left;
    std::cout << "|" + team + "Arc \033[0m| ";
  }
}

void Archer::phase2(){
  avancer();
}

void Archer::phase3(struct _Cible* c){
  if(c){};
}
