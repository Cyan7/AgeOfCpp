#include <iostream>
#include <cstdlib>
#include "Catapulte.hpp"

void Catapulte::afficher(){
  std::string team = joueur == jA ? "\033[34m" : "\033[31m";
  if (this->position!=0 && this->position != 11){
    //std::cout << std::setw(7) << std::left;
    std::cout << team + "Cat    \033[0m";
  }
  else {
    //std::cout << std::setw(7) << std::left;
    std::cout << "|" + team + "Cat \033[0m| ";
  }
}

void Catapulte::phase2(){
  // RIENG
}

void Catapulte::phase3(struct _Cible* c){
  if(c){};
  if(!action1) avancer();
  action1 = false;
}
