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

bool Terrain::peutAttaquer(Unite u) const{

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
