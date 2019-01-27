#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Terrain.hpp"
#include "Unite.hpp"

Terrain *Terrain::monTerrain = nullptr;

Terrain Terrain::getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
  if (monTerrain == nullptr){
    monTerrain = new Terrain(deuxJoueurs, charger, fichierSauvegarde);
    return *monTerrain;
  }
  return *monTerrain;
}

bool Terrain::creerUnite(joueurEnum j, unitEnum type){
  switch(j){
    case jA:
    {
      Base* b = dynamic_cast<Base*>(mesEntitesA.at(0));
      if(mesJoueurs.at(0)->creerUnite(type)){
        mesEntitesA.push_back(b->creerUnite(type));
        return true;
      }
      return false;
    }
    case jB:
    {
      Base* b = dynamic_cast<Base*>(mesEntitesB.at(0));
      if(mesJoueurs.at(1)->creerUnite(type)){
        mesEntitesB.push_back(b->creerUnite(type));
        return true;
      }
      return false;
    }
  }
  return false;
}

Entite* Terrain::cible(Unite* u) const{
  Entite* cible = nullptr;
  int distmin = 12;
  switch (u->getJoueur()) {
    case jA:
      for (Entite* e:mesEntitesA){
        int dist = std::abs(e->getPosition()-u->getPosition());
        if (dist >= u->getPortee().at(0) && dist <= u->getPortee().back() && dist<distmin){
          distmin = dist;
          cible = e;
        }
      }
    break;
    case jB:
      for (Entite* e:mesEntitesB){
        int dist = std::abs(e->getPosition()-u->getPosition());
        if (dist >= u->getPortee().at(0) && dist <= u->getPortee().back() && dist<distmin){
          distmin = dist;
          cible = e;
        }
      }
    break;
  }
  return cible;
}

void Terrain::update(){
  if(mesEntitesA.at(0)->getPV() <= 0) this->Aloose = true;
  for(int i=mesEntitesA.size()-1; i>=1; i--){
    Unite* u = dynamic_cast<Unite*>(mesEntitesA.at(i));
    if(u->getPV() <= 0){
      mesJoueurs.at(0)->setOr(mesJoueurs.at(0)->getOr() - 0.5*u->getPrix());
      delete mesEntitesA.at(i);
      mesEntitesA.erase(mesEntitesA.begin()+i);
    }
  }
  for(int i=mesEntitesB.size()-1; i>=1; i--){
    Unite* u = dynamic_cast<Unite*>(mesEntitesB.at(i));
    if(u->getPV() <= 0){
      mesJoueurs.at(1)->setOr(mesJoueurs.at(1)->getOr() - 0.5*u->getPrix());
      delete mesEntitesB.at(i);
      mesEntitesB.erase(mesEntitesA.begin()+i);
    }
  }
}

void Terrain::afficherTerrain(){
  //on range les entités dans leur ordre de position
  std::vector<Entite*> casesTerrain(12);
  for(Entite* eA : mesEntitesA){
    casesTerrain.insert(casesTerrain.begin()+eA->getPosition(),eA);
  }
  for(Entite* eB : mesEntitesB){
    casesTerrain.insert(casesTerrain.begin()+eB->getPosition(),eB);
  }
  //on parcourt casesTerrain pour afficher les PV puis l'entité

  for(Entite* e : casesTerrain){
    if(e){
      std::cout << std::setw(5) << std::left << e->getPV();
    }
    else{
      std::cout << std::setw(5) << std::left << "    ";
    }
  }

  std::cout << "" << std::endl;

  for(Entite* e : casesTerrain){
    if(e){
      std::cout << std::setw(10) << std::left;
      if(Base* b = dynamic_cast<Base*>(e)){
        b->afficher();
      }
      else if(Fantassin *f = dynamic_cast<Fantassin*>(e)){
        f->afficher();
      }
      else if(Archer *a = dynamic_cast<Archer*>(e)){
        a->afficher();
      }
      else if(Catapulte *c = dynamic_cast<Catapulte*>(e)){
        c->afficher();
      }
    }
    else{
      std::cout << std::setw(10) << std::left << "    ";
    }
  }
  std::cout << "" << std::endl;
}

int main(){
  Terrain terrain = Terrain::getInstance(true, false, "");
  joueurEnum jouA = jA;
  unitEnum fA = fantassin;
  terrain.creerUnite(jouA,fA);
  terrain.mesEntitesA.at(1)->setPV(-2);
  terrain.update();
  terrain.afficherTerrain();
}
