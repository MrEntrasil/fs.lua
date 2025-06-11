COMPILER=g++
FLAGS=-shared -fpic -Iinclude -std=c++17

all:
	$(COMPILER) -o fslua.so src/main.cpp $(FLAGS)

clean:
	rm -rf fslua.so
