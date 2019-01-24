#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "Entite.hpp"
#include "Joueur.hpp"
#include "Base.hpp"
#include "Unite.hpp"
#include <string>


class Terrain{
	static Terrain *monTerrain;
	std::vector<Entite> mesEntites;
	std::vector<Joueur> mesJoueurs;

	Terrain(bool deuxJoueurs, bool charger, std::string fichierSauvegarde){
		if (!charger){
			if (deuxJoueurs){
				Humain joueurA;
				Humain joueurB;
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				Base baseA(jA);
				Base baseB(jB);
				mesEntites.push_back(baseA);
				mesEntites.push_back(baseB);
			}
			if (!deuxJoueurs){
				Humain joueurA;
				IA joueurB;
				mesJoueurs.push_back(joueurA);
				mesJoueurs.push_back(joueurB);
				Base baseA(jA);
				Base baseB(jB);
				mesEntites.push_back(baseA);
				mesEntites.push_back(baseB);
			}
		}


	}
	~Terrain(){}


	public :
		Terrain getInstance(bool deuxJoueurs, bool charger, std::string fichierSauvegarde);
		void afficher();
		int ajouterUnite(Unite& u);

};

#endif
