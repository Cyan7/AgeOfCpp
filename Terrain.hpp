#pragma once
#include <vector>
#include "Joueur.hpp"
#include "Entite.hpp"
#include "Base.hpp"
#include "Unite.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include <string>
#include <unistd.h>

#define SALAIRE (8)

class Terrain{
	bool Aloose, Bloose;
	static Terrain *monTerrain;

	std::vector<Entite*> mesEntitesA;
	std::vector<Entite*> mesEntitesB;
	std::vector<Joueur*> mesJoueurs;

	Terrain(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
		Aloose = false;
		Bloose = false;

		if (!charger){
			if (deuxJoueurs){
				Joueur* joueurA = new Joueur(humain);
				Joueur* joueurB = new Joueur(humain);
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				Base* baseA = new Base(jA);
				Base* baseB = new Base(jB);
				mesEntitesA.push_back(baseA);
				mesEntitesB.push_back(baseB);
			}
			if (!deuxJoueurs){
				Joueur* joueurA = new Joueur(humain);
				Joueur* joueurB = new Joueur(ia);
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				Base* baseA = new Base(jA);
				Base* baseB = new Base(jB);
				mesEntitesA.push_back(baseA);
				mesEntitesB.push_back(baseB);
			}
		}
		else{
			if (deuxJoueurs){
				Joueur* joueurA = new Joueur(humain);
				Joueur* joueurB = new Joueur(humain);
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				this->lireSauvegarde(fichierSauvegarde);
			}
			if (!deuxJoueurs){
				Joueur* joueurA = new Joueur(humain);
				Joueur* joueurB = new Joueur(ia);
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				this->lireSauvegarde(fichierSauvegarde);
			}
		}


	}


	public :
		Terrain(){}
		~Terrain(){}

		static Terrain getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde);
		bool getAloose() const {return Aloose;}
		bool getBloose() const {return Bloose;}
		bool creerUnite(joueurEnum j, unitEnum type);
		void update();
		struct _Cible* cible(Unite* u) const;
		void afficherTerrain();
		void payDay();
		void effectuerTour(joueurEnum j);

 		void sauvegarder(std::string nomFichier);
		void lireSauvegarde(std::string nomFichier);

};
