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

void Fantassin::afficher(){
  std::string team = joueur == jA ? "A" : "B";
  std::string perso = "Fan" + team;
  std::cout << perso;
}
