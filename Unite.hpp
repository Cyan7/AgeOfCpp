#ifndef UNITE_H
#define UNITE_H
#include <vector>
#include "Entite.hpp"

enum unitEnum {fantassin, archer, catapulte};

class Unite: public Entite{
protected:
  int prix,ptAttaque;
  std::vector<int> portee;

public:
  Unite(int ptVie, int posi, joueurEnum j, int p, int attaque) :
    Entite(ptVie,posi,j), prix(p), ptAttaque(attaque){}
  ~Unite(){}

  int getPrix() const;
  int getPtAttaque() const;
  std::vector<int> getPortee() const;

  void setPrix(int p);
  void setPtAttaque(int attaque);
  void setPortee(std::vector<int> v);

  void attaquer(Entite& e);
  void avancer(); // change position de l'unité ; print erreur si position hors du terrain
};

#endif
