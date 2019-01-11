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
				Joueur joueurA;
				Joueur joueurB;
				Base baseA(100, 0, jA);
				Base baseB(100, 11, jB);

			}
		}


	}
	~Terrain(){}


	public :
		Terrain getInstance();
		void afficher();
		int ajouterUnite(Unite& u);

};

#endif
