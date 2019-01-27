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
}

void Fantassin::afficher(){
  std::string team = joueur == jA ? "A" : "B";
  if (this->position!=0){
    std::string perso = "Fan" + team;
    std::cout << perso;
  }
  else {
    std::string perso = "|Fan" + team + "|";
    std::cout << perso;
  }
}
