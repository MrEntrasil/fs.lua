COMPILER=g++
FLAGS=-O2 -shared -fpic -I/usr/include -std=c++17 -L/usr/lib/lua5.4 -llua

all:
	$(COMPILER) -o fslua.so src/main.cpp $(FLAGS)

clean:
	rm -rf fslua.so
