CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = starforce.cpp equipment.cpp utility.cpp database.cpp
OBJ = $(SRC:.cc=.o)
EXEC = starforce

all: $(EXEC)
	./starforce

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(EXEC)