CXX=g++
CXXFLAGS= -Wall -Wextra -std=c++11 #-Werror
DEPS = jeu.hpp Entite.hpp Unite.hpp

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@


jeu: jeu.o Entite.o Unite.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core
