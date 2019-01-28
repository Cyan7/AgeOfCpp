CXX=g++
CXXFLAGS= -Wall -Wextra -std=c++11 #-Werror
DEPS = jeu.hpp Terrain.hpp Entite.hpp Unite.hpp Base.hpp Catapulte.hpp Archer.hpp Fantassin.hpp Joueur.hpp

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@


jeu: Terrain.o Entite.o Unite.o Base.o Catapulte.o Archer.o Fantassin.o Joueur.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core
