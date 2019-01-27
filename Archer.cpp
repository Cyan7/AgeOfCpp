#include <iostream>
#include <cstdlib>
#include <string>
#include "Archer.hpp"

void Archer::afficher(){
  std::string team = joueur == jA ? "A" : "B";
  std::string perso = "Arc" + team;
  std::cout << perso;
}
