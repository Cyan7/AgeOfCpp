#pragma once
#include <vector>
#include "Joueur.hpp"
#include "Entite.hpp"
#include "IA.hpp"
#include "Humain.hpp"
#include "Base.hpp"
#include "Unite.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include <string>


class Terrain{
	bool Aloose;
	bool Bloose;
	static Terrain *monTerrain;
	public :
	std::vector<Entite*> mesEntitesA;
	std::vector<Entite*> mesEntitesB;
	std::vector<Joueur*> mesJoueurs;

private:
	Terrain(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
		Aloose = false;
		Bloose = false;

		if (!charger){
			if (deuxJoueurs){
				Humain* joueurA = new Humain();
				Humain* joueurB = new Humain();
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				Base* baseA = new Base(jA);
				Base* baseB = new Base(jB);
				mesEntitesA.push_back(baseA);
				mesEntitesB.push_back(baseB);
			}
			if (!deuxJoueurs){
				Humain* joueurA = new Humain();
				IA* joueurB = new IA();
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				Base* baseA = new Base(jA);
				Base* baseB = new Base(jB);
				mesEntitesA.push_back(baseA);
				mesEntitesB.push_back(baseB);
			}
		}


	}


	public :
		~Terrain(){}

		static Terrain getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde);
		bool creerUnite(joueurEnum j, unitEnum type);
		void update();
		Entite* cible(Unite* u) const;
		void afficherTerrain();

};
