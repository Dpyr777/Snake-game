CXX = g++
CXXFLAGS = -c

all: snake

snake: main.o NewFood.o Menu.o Draw.o Input.o Logic.o Result.o Again.o 
	$(CXX) $^ -o $@ -lncurses

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $< 

NewFood.o: NewFood.cpp
	$(CXX) $(CXXFLAGS) $<

Menu.o: Menu.cpp
	$(CXX) $(CXXFLAGS) $<

Draw.o: Draw.cpp
	$(CXX) $(CXXFLAGS) $< 

Input.o: Input.cpp
	$(CXX) $(CXXFLAGS) $< 

Logic.o: Logic.cpp
	$(CXX) $(CXXFLAGS) $< 

Result.o: Result.cpp
	$(CXX) $(CXXFLAGS) $< 

Again.o: Again.cpp
	$(CXX) $(CXXFLAGS) $< 

run: snake
	./snake

clean:
	rm -rf *.o


