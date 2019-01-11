CXX=g++
CXXFLAGS= -Wall -Wextra -std=c++11 #-Werror
DEPS = jeu.hpp Entite.hpp Unite.hpp Base.hpp Catapulte.hpp Joueur.hpp Humain.hpp IA.hpp

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@


jeu: jeu.o Entite.o Unite.o Base.o Catapulte.o Joueur.o Humain.o IA.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core
