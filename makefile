all:
	g++ -o fslua.so src/main.cpp -shared -fpic -Iinclude

clean:
	rm -rf fslua.so
