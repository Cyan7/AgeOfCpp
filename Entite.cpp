#include <iostream>
#include <cstdlib>
#include "Entite.hpp"

//getters et setters
int Entite::getPV() const{
  return pv;
}
int Entite::getPosition() const{
  return position;
}
joueurEnum Entite::getJoueur() const{
  return joueur;
}

void Entite::setPV(int ptVie){
  pv = ptVie;
}
void Entite::setPosition(int posi){
  position = posi;
}
void Entite::setJoueur(joueurEnum j){
  joueur = j;
}
