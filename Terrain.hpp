#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "Entite.hpp"
#include "Joueur.hpp"
#include <string>


class Terrain{
	static Terrain *monTerrain;
	std::vector<Entite> mesEntites;
	std::vector<Joueur> mesJoueurs;
	
	Terrain(bool deuxJoueurs, bool charger, string fichierSauvegarde){
		if (!charger){
			if (deuxJoueurs){
				Joueur joueurA;
				Joueur joueurB;
				Base baseA;
				Base baseB;
				
			}
		}
		
		
	}
	~Terrain(){}
	
	
	public :
		Terrain getInstance();
		void afficher();
		int ajouterUnite(Unite u);
		
};

#endif
