#ifndef ENTITE_H
#define ENTITE_H

enum joueurEnum { jA, jB };

class Entite {
protected:
  int pv, position;
  joueurEnum joueur;

public :
  //constructeur
  Entite(int ptVie, int posi, joueurEnum j) : pv(ptVie), position(posi), joueur(j){}
  //destructeur
  ~Entite(){}

  //getters et setters
  int getPV() const;
  int getPosition() const;
  joueurEnum getJoueur() const;

  void setPV(int ptVie);
  void setPosition(int posi);
  void setJoueur(joueurEnum j);
  //afficher
  void afficher();
  //mourir
  virtual void mourir(){};//doit donner de l'argent au joueur qui l'a tuée
};

#endif
