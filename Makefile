CXX=g++
CXXFLAGS= -Wall -Wextra -Werror -std=c++11
DEPS = vector.hpp

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $< -c -o $@


jeu: jeu.o
	$(CXX) $^ -o $@

.PHONY: clean

clean:
	rm -f *.o *~ core
