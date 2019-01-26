#pragma once
#include <vector>
#include "Joueur.hpp"
#include "Entite.hpp"
#include "IA.hpp"
#include "Humain.hpp"
#include "Base.hpp"
#include "Unite.hpp"
#include <string>


class Terrain{
	static Terrain *monTerrain;
	std::vector<Entite> mesEntitesA;
	std::vector<Entite> mesEntitesB;
	std::vector<Joueur> mesJoueurs;

	Terrain(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
		if (!charger){
			if (deuxJoueurs){
				Humain joueurA;
				Humain joueurB;
				mesJoueurs.push_back((Joueur) joueurA);
				mesJoueurs.push_back((Joueur) joueurB);
				Base baseA(jA);
				Base baseB(jB);
				mesEntitesA.push_back((Entite) baseA);
				mesEntitesB.push_back((Entite) baseB);
			}
			if (!deuxJoueurs){
				Humain joueurA;
				IA joueurB;
				mesJoueurs.push_back((Joueur) joueurA);
				mesJoueurs.push_back((Joueur) joueurB);
				Base baseA(jA);
				Base baseB(jB);
				mesEntitesA.push_back((Entite) baseA);
				mesEntitesB.push_back((Entite) baseB);
			}
		}


	}
	~Terrain(){}


	public :
		static Terrain getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde);
		void afficher();
		bool creerUnite(Base b, unitEnum type);
		void update();
		Entite* cible(Unite u) const;
		void afficherTerrain();

};
