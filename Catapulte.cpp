#include <iostream>
#include <cstdlib>
#include "Catapulte.hpp"

void Catapulte::afficher(){
  char a = joueur ==jA ? 'A' : 'B';
  std::cout << "Cat" << a << std::endl;
  //TODO : afficher les pv
}
