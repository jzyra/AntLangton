CXX=g++
CXXFLAGS=-W -Wall
LDFLAGS=`sdl-config --cflags --libs` -ljson
EXEC=antlangton

all: $(EXEC)

antlangton: Config.o AntLangton.o Window.o
	$(CXX) -o antlangton Config.o AntLangton.o Window.o main.cpp $(CXXFLAGS) $(LDFLAGS)

Config.o: Config.cpp
	$(CXX) -o Config.o -c Config.cpp $(CXXFLAGS) $(LDFLAGS)

AntLangton.o: AntLangton.cpp
	$(CXX) -o AntLangton.o -c AntLangton.cpp $(CXXFLAGS) $(LDFLAGS)

Window.o: Window.cpp
	$(CXX) -o Window.o -c Window.cpp $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
