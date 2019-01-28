#pragma once

#include <iomanip>

enum joueurEnum { jA, jB };

class Entite {
protected:
  int pv, position;
  joueurEnum joueur;


public :
  Entite(){}
  Entite(int ptVie, int posi, joueurEnum j) : pv(ptVie), position(posi), joueur(j){}
  virtual ~Entite(){}

  //getters et setters
  int getPV() const;
  int getPosition() const;
  joueurEnum getJoueur() const;

  void setPV(int ptVie);
  void setPosition(int posi);
  void setJoueur(joueurEnum j);
  //afficher
  virtual void afficher(){};

};

struct _Cible{
	int nb;
	Entite* cible1;
	Entite* cible2;
};
