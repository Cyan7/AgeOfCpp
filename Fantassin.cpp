#include <cstdlib>
#include <iostream>
#include <string>
#include "Fantassin.hpp"
#include "Entite.hpp"


bool Fantassin::isSuperSoldat() const{
  return superSoldat;
}

void Fantassin::promouvoir(){
  if(this->isSuperSoldat()){
    //Déjà super soldat
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
    if(isSuperSoldat()){
      if(c->cible1) attaquer(c->cible1);
    }
  }
  action1 = false;
}

void Fantassin::afficher(){
  std::string team = joueur == jA ? "\033[34m" : "\033[31m";
  std::string type = isSuperSoldat() ? "Sup" : "Fan";
  if (this->position!=0 && this->position != 11){
    //std::cout << std::setw(7) << std::left;
    std::cout << team + type + "    \033[0m";
  }
  else {
    //std::cout << std::setw(7) << std::left;
    std::cout << "|" + team + type + " \033[0m| ";
  }
}
