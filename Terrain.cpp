#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Terrain.hpp"

Terrain *Terrain::monTerrain = nullptr;

Terrain Terrain::getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
  if (monTerrain == nullptr){
    monTerrain = new Terrain(deuxJoueurs, charger, fichierSauvegarde);
    return *monTerrain;
  }
  return *monTerrain;
}

bool Terrain::creerUnite(joueurEnum j, unitEnum type){
  switch(j){
    case jA:
    {
      Base* b = dynamic_cast<Base*>(mesEntitesA.at(0));
      if(mesJoueurs.at(0)->creerUnite(type)){
        mesEntitesA.push_back(b->creerUnite(type));
        return true;
      }
      return false;
    }
    case jB:
    {
      Base* b = dynamic_cast<Base*>(mesEntitesB.at(0));
      if(mesJoueurs.at(1)->creerUnite(type)){
        mesEntitesB.push_back(b->creerUnite(type));
        return true;
      }
      return false;
    }
  }
  return false;
}

struct _Cible* Terrain::cible(Unite* u) const{
  struct _Cible* cible = new struct _Cible();
  int distmin = 12;
  switch (u->getJoueur()) {
    case jB:
      for (Entite* e:mesEntitesA){
        int dist = std::abs(e->getPosition()-u->getPosition());
        if (dist >= u->getPortee().at(0) && dist <= u->getPortee().back() && dist<distmin){
          distmin = dist;
          cible->cible1 = e;
        }
      }
      if(dynamic_cast<Catapulte*>(u)){
        if(distmin < 4){
          for (Entite* e:mesEntitesA){
            if(std::abs(e->getPosition()-u->getPosition())==distmin+1){
              cible->cible2 = e;
              cible->nb = 2;
            }
            else cible->nb = 1;
          }
        }
        if(distmin == 4){
          for (Entite* e:mesEntitesB){
            if(std::abs(e->getPosition()-u->getPosition())==distmin-1){
              cible->cible2 = e;
              cible->nb = 2;
            }
            else cible->nb = 1;
          }
        }
    }
      else cible->nb = 1;
      break;
    case jA:
      for (Entite* e:mesEntitesB){
        int dist = std::abs(e->getPosition()-u->getPosition());
        if (dist >= u->getPortee().at(0) && dist <= u->getPortee().back() && dist<distmin){
          distmin = dist;
          cible->cible1 = e;
      }
    }
      if(dynamic_cast<Catapulte*>(u)){
        if(distmin < 4){
          for (Entite* e:mesEntitesB){
            if(std::abs(e->getPosition()-u->getPosition())==distmin+1){
              cible->cible2 = e;
              cible->nb = 2;
            }
            else cible->nb = 1;
          }
        }
        if(distmin == 4){
          for (Entite* e:mesEntitesA){
            if(std::abs(e->getPosition()-u->getPosition())==distmin-1){
              cible->cible2 = e;
              cible->nb = 2;
            }
            else cible->nb = 1;
          }
        }
      }
      else cible->nb = 1;
      break;
  }
  return cible;
}

void Terrain::update(){
  if(mesEntitesA.at(0)->getPV() <= 0) this->Aloose = true;
  if(mesEntitesA.at(1)->getPV() <= 0) this->Bloose = true;
  for(int i=mesEntitesA.size()-1; i>=1; i--){
    Unite* u = dynamic_cast<Unite*>(mesEntitesA.at(i));
    if(u->getPV() <= 0){
      mesJoueurs.at(0)->setOr(mesJoueurs.at(0)->getOr() - 0.5*u->getPrix());
      delete mesEntitesA.at(i);
      mesEntitesA.erase(mesEntitesA.begin()+i);
    }
  }
  for(int i=mesEntitesB.size()-1; i>=1; i--){
    Unite* u = dynamic_cast<Unite*>(mesEntitesB.at(i));
    if(u->getPV() <= 0){
      mesJoueurs.at(1)->setOr(mesJoueurs.at(1)->getOr() - 0.5*u->getPrix());
      delete mesEntitesB.at(i);
      mesEntitesB.erase(mesEntitesA.begin()+i);
    }
  }
}

void Terrain::afficherTerrain(){

  std::cout << std::endl;

  //affichage or des joueurs
  std::cout << std::setw(7) << std::left << "Or jA : " << mesJoueurs.at(0)->getOr();
  for(int i= 0; i<9;i++){
    std::cout << std::setw(7) << std::left << "";
  }
  std::cout << std::setw(7) << std::left << "Or jB : " << mesJoueurs.at(1)->getOr() << std::endl;
  std::cout << std::endl;

  //on range les entités dans leur ordre de position
  std::vector<Entite*> casesTerrain(12);
  for(Entite* eA : mesEntitesA){
      casesTerrain.at(eA->getPosition())=eA;
  }
  for(Entite* eB : mesEntitesB){
    casesTerrain.at(eB->getPosition())=eB;
  }

  //affichage des PV de l'entité
  for(Entite* e : casesTerrain){
    if(e){
      if(dynamic_cast<Base*>(e) && e->getPosition()==0){
        std::cout << std::setw(7) << std::left << "/ A  \\";
      }
      else if(dynamic_cast<Base*>(e) && e->getPosition()==11){
        std::cout << std::setw(7) << std::left << "/ B  \\";
      }
      else{
        std::cout << std::setw(7) << std::left << e->getPV();
      }
    }
    else{
      std::cout << std::setw(7) << std::left << "    ";
    }
  }

  std::cout << std::endl;

  //affichage des personnages
  for(Entite* e : casesTerrain){
    if(e){
      std::cout << std::setw(7) << std::left;
      if(Base* b = dynamic_cast<Base*>(e)){
        b->afficher();
      }
      if(Fantassin *f = dynamic_cast<Fantassin*>(e)){
        f->afficher();
      }
      if(Archer *a = dynamic_cast<Archer*>(e)){
        a->afficher();
      }
      if(Catapulte *c = dynamic_cast<Catapulte*>(e)){
        c->afficher();
      }
    }
    else{
      std::cout << std::setw(7) << std::left << "____";
    }
  }
  std::cout << std::endl;

  //affichage des pv des bases
  for(Entite* e : casesTerrain){
    if(e){
      if(e->getPosition()==0){
        std::cout << std::setw(7) << std::left << mesEntitesA.at(0)->getPV();
      }
      else if(e->getPosition()==11){
        std::cout << std::setw(7) << std::left << mesEntitesB.at(0)->getPV();
      }
      else{
        std::cout << std::setw(7) << std::left << "    ";
      }
    }
    else{
      std::cout << std::setw(7) << std::left << "    ";
    }
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

void Terrain::payDay(){
  mesJoueurs.at(0)->setOr(mesJoueurs.at(0)->getOr()+SALAIRE);
  mesJoueurs.at(1)->setOr(mesJoueurs.at(1)->getOr()+SALAIRE);
}

void Terrain::effectuerTour(joueurEnum j){
  switch (j) {
    case jA:
    {
      // Phase 1
      for(int i=mesEntitesA.size()-1; i>=1; i--){
        Unite* u = dynamic_cast<Unite*>(mesEntitesA.at(i));
        struct _Cible* c = cible(u);
        u->phase1(c);
        update();
        afficherTerrain();
      }
      // Phase 2
      for(int i=1;i<mesEntitesA.size(); i++){
        Unite* u = dynamic_cast<Unite*>(mesEntitesA.at(i));
        u->phase2();
        afficherTerrain();
      }
      // Phase 3
      for(int i=1;i<mesEntitesA.size(); i++){
        Unite* u = dynamic_cast<Unite*>(mesEntitesA.at(i));
        struct _Cible* c = cible(u);
        u->phase3(c);
        update();
        afficherTerrain();
      }

    }
    case jB:
    {
      // Phase 1
      for(int i=mesEntitesB.size()-1; i>=1; i--){
        Unite* u = dynamic_cast<Unite*>(mesEntitesB.at(i));
        struct _Cible* c = cible(u);
        u->phase1(c);
        update();
        afficherTerrain();
      }
      // Phase 2
      for(int i=1;i<mesEntitesB.size(); i++){
        if(Fantassin* u = dynamic_cast<Fantassin*>(mesEntitesB.at(i))){
          u->phase2();
        };
        if(Archer* u = dynamic_cast<Archer*>(mesEntitesB.at(i))){
          u->phase2();
        };
        if(Catapulte* u = dynamic_cast<Catapulte*>(mesEntitesB.at(i))){
          u->phase2();
        };
        afficherTerrain();
      }
      // Phase 3
      for(int i=1;i<mesEntitesB.size(); i++){
        Unite* u = dynamic_cast<Unite*>(mesEntitesB.at(i));
        struct _Cible* c = cible(u);
        u->phase3(c);
        update();
        afficherTerrain();
      }
    }
  }
}

int main(){
  Terrain terrain = Terrain::getInstance(true, false, "");
  terrain.mesJoueurs.at(0)->setOr(100);
  joueurEnum jouA = jA;
  unitEnum fA = catapulte;
  terrain.creerUnite(jouA,fA);
  terrain.effectuerTour(jouA);
  return 0;
}
