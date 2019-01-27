#include <iostream>
#include <cstdlib>
#include "Unite.hpp"

int Unite::getPrix() const{
  return prix;
}
int Unite::getPtAttaque() const{
  return ptAttaque;
}
std::vector<int> Unite::getPortee() const{
  return portee;
}

void Unite::setPrix(int p){
  prix=p;
}
void Unite::setPtAttaque(int attaque){
  ptAttaque=attaque;
}
void Unite::setPortee(std::vector<int> v){
  portee=v;
}

void Unite::phase1(struct _Cible* c){
  if(c->cible1){
    attaquer(c->cible1);
    if(c->cible2) attaquer(c->cible2);
    action1 = true;
  }
}

void Unite::attaquer(Entite* e){
  e->setPV(e->getPV()-this->getPtAttaque());
}

void Unite::avancer(){
  int pos = this->getPosition();
  if(this->joueur == jA){
    if (pos<10) this->setPosition(pos+1);
    else std::cout << "position is out of playfield" << std::endl;
  }
  else {
    if (pos>1) this->setPosition(pos-1);
    else std::cout << "position is out of playfield" << std::endl;
  }
}
