#include <cstdlib>
#include <iostream>
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
  char a = joueur ==jA ? 'A' : 'B';
  std::cout << "Fan" << a << std::endl;
  //TODO : afficher les pv
}
