#include <iostream>
#include <cstdlib>
#include "Catapulte.hpp"

void Catapulte::afficher(){
  std::string team = joueur == jA ? "A" : "B";
  std::string perso = "Cat" + team;
  std::cout << perso;
}
