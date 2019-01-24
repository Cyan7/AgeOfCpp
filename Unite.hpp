#ifndef UNITE_H
#define UNITE_H
#include <vector>
#include "Entite.hpp"

class Unite: public Entite{
  int prix,ptAttaque;
  int* portee;

public:
  Unite(int ptVie, int posi, joueurEnum j, int p, int attaque, int* v) :
    Entite(ptVie,posi,j), prix(p), ptAttaque(attaque), portee(v){}
  ~Unite(){}

  int getPrix() const;
  int getPtAttaque() const;
  int* getPortee() const;

  void setPrix(int p);
  void setPtAttaque(int attaque);
  void setPortee(int* v);

  virtual void attaquer(Entite& e){};
  void avancer();
};

#endif
