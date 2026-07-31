CXX := g++
CXXFLAGS := -std=c++17 -O2 -pipe -Wall -Wextra

code: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o code

.PHONY: clean

clean:
	rm -f code
