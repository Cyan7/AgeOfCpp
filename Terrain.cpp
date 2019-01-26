#include <cstdlib>
#include <iostream>
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

bool Terrain::peutAttaquer(Unite u) const{

}
