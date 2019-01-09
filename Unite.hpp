#ifndef UNITE_H
#define UNITE_H
#include <vector>
#include "Entite.hpp"

class Unite: public Entite{
  int prix,ptAttaque;
  std::vector<int> portee;

public:
  Unite(int ptVie, int posi, joueurEnum j, int p, int attaque,std::vector<int> v) :
    Entite(ptVie,posi,j), prix(p), ptAttaque(attaque), portee(v){}
  ~Unite(){}

  int getPrix() const;
  int getPtAttaque() const;
  std::vector<int> getPortee() const;

  void setPrix(int p);
  void setPtAttaque(int attaque);
  void setPortee(std::vector<int> v);

  virtual void attaquer(Entite& e){};
  void avancer();
};

#endif
