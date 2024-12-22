all:
	g++ -o $(PWD)/bin/fstream.so $(PWD)/src/fstream.cpp -shared -fpic -L $(PWD)/include -I $(PWD)/include
	clear
	luajit bin/main.lua