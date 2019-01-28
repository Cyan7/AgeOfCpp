#include <cstdlib>
#include <iostream>
#include <string>
#include "Fantassin.hpp"
#include "Entite.hpp"


bool Fantassin::isSuperSoldat(){
  return superSoldat;
}

void Fantassin::promouvoir(){
  if(this->isSuperSoldat()){
    std::cout << "Déjà super soldat" << std::endl;
  }
  else{
    this->superSoldat = true;
  }
}

void Fantassin::phase2(){
  avancer();
}

void Fantassin::phase3(struct _Cible* c){
  if(!action1){
    if(c->cible1) attaquer(c->cible1);
  }
  else {
    if(superSoldat == true){
      if(c->cible1) attaquer(c->cible1);
    }
  }
  action1 = false;
}

void Fantassin::afficher(){
  std::string team = joueur == jA ? "\033[34m" : "\033[31m";
  if (this->position!=0 && this->position != 11){
    //std::cout << std::setw(7) << std::left;
    std::cout << team + "Fan    \033[0m";
  }
  else {
    //std::cout << std::setw(7) << std::left;
    std::cout << "|" + team + "Fan \033[0m| ";
  }
}
