#include <iostream>
#include <cstdlib>
#include "Unite.hpp"

int Unite::getPrix() const{
  return prix;
}
int Unite::getPtAttaque() const{
  return ptAttaque;
}
int* Unite::getPortee() const{
  return portee;
}

void Unite::setPrix(int p){
  prix=p;
}
void Unite::setPtAttaque(int attaque){
  ptAttaque=attaque;
}
void Unite::setPortee(int* v){
  portee=v;
}

void Unite::avancer(){
  //TODO
}
