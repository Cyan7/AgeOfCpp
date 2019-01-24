#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include "Joueur.hpp"
#include "Entite.hpp"
#include "IA.hpp"
#include "Humain.hpp"
#include "Base.hpp"
#include "Unite.hpp"
#include <string>


class Terrain{
	std::vector<Entite> mesEntites;
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
				mesEntites.push_back((Entite) baseA);
				mesEntites.push_back((Entite) baseB);
			}
			if (!deuxJoueurs){
				Humain joueurA;
				IA joueurB;
				mesJoueurs.push_back((Joueur) joueurA);
				mesJoueurs.push_back((Joueur) joueurB);
				Base baseA(jA);
				Base baseB(jB);
				mesEntites.push_back((Entite) baseA);
				mesEntites.push_back((Entite) baseB);
			}
		}


	}
	~Terrain(){}


	public :
		void afficher();
		int ajouterUnite(Unite& u);

};

#endif
