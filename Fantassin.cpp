#include <cstdlib>
#include <iostream>
#include "Fantassin.hpp"
#include "Entite.hpp"

bool Fantassin::isSuperSoldat(){
  return superSoldat;
}

void Fantassin::promouvoir(){
  if(this.isSuperSoldat()){
    printf("Déjà super soldat\n");
  }
}

void Fantassin::attaquer(Entite& e){
  //TODO
}
