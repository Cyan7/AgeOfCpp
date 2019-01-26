#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Terrain.hpp"

Terrain *Terrain::monTerrain = nullptr;

Terrain Terrain::getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
  if (monTerrain == nullptr){
    monTerrain = new Terrain(deuxJoueurs, charger, fichierSauvegarde);
    return *monTerrain;
  }
  return *monTerrain;
}

bool Terrain::creerUnite(Base b, unitEnum type){
  switch(b.getJoueur()){
    case jA:
      if(mesJoueurs.at(0).creerUnite(type)){
        Entite e = (Entite) *(b.creerUnite(type));
        mesEntitesA.push_back(e);
        return true;
      }
      return false;
    case jB:
      if(mesJoueurs.at(1).creerUnite(type)){
        Entite e = (Entite) *(b.creerUnite(type));
        mesEntitesB.push_back(e);
        return true;
      }
    return false;
  }
  return false;
}

Entite* Terrain::cible(Unite u) const{
  Entite* cible = nullptr;
  int distmin = 12;
  switch (u.getJoueur()) {
    case jA:
      for (Entite e:mesEntitesA){
        int dist = std::abs(e.getPosition()-u.getPosition());
        if (dist >= u.getPortee().at(0) && dist <= u.getPortee().back() && dist<distmin){
          distmin = dist;
          cible = &e;
        }
      }
    break;
    case jB:
      for (Entite e:mesEntitesB){
        int dist = std::abs(e.getPosition()-u.getPosition());
        if (dist >= u.getPortee().at(0) && dist <= u.getPortee().back() && dist<distmin){
          distmin = dist;
          cible = &e;
        }
      }
    break;
  }
  return cible;
}

void Terrain::afficherTerrain(){
  //on range les entités dans leur ordre de position
  std::vector<Entite> casesTerrain;
  for(Entite eA : mesEntitesA){
    casesTerrain.insert(casesTerrain.begin()+eA.getPosition(),eA);
  }
  for(Entite eB : mesEntitesB){
    casesTerrain.insert(casesTerrain.begin()+eB.getPosition(),eB);
  }
  //on parcourt casesTerrain pour afficher les PV puis l'entité
  for(Entite e : casesTerrain){
    std::cout << std::setw(10) << std::left << e.getPV();
  }
  std::cout << std::endl;
  for(Entite e : casesTerrain){
    std::cout << std::setw(10) << std::left;
    e.afficher();
  }
  std::cout << std::endl;
}

int main(){
  std::cout << "gg" << std::endl;
}
