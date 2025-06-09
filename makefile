all:
	g++ -o fslua.so src/main.cpp -shared -fpic -Iinclude -std=c++17

clean:
	rm -rf fslua.so
