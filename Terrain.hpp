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
	bool Aloose;
	bool Bloose;
	static Terrain *monTerrain;
	std::vector<Entite> mesEntitesA;
	std::vector<Entite> mesEntitesB;
	std::vector<Joueur> mesJoueurs;

	Terrain(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
		Aloose = false;
		Bloose = false;
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


	public :
		~Terrain(){}

		static Terrain getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde);
<<<<<<< HEAD
		void afficher();
		bool creerUnite(joueurEnum j, unitEnum type);
=======
		bool creerUnite(Base b, unitEnum type);
>>>>>>> 6d19e483d1110cfee8a29e09473efdfbb45ea144
		void update();
		Entite* cible(Unite u) const;
		void afficherTerrain();

};
