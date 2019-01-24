#include <cstdlib>
#include <iostream>
#include "Terrain.hpp"

Terrain Terrain::getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
  if (Terrain.monTerrain == NULL){
    monTerrain = Terrain(deuxJoueurs, charger, fichierSauvegarde);
    return monTerrain;
  }
  return monTerrain;
}
