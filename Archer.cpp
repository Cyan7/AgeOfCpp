#include <iostream>
#include <cstdlib>
#include "Archer.hpp"

void Archer::afficher(){
  char a = joueur ==jA ? 'A' : 'B';
  std::cout << "Arc" << a << std::endl;
  //TODO : afficher les pv
}
