all: main

main: main.cpp product.cpp sum.cpp functions.h
	g++ -std=c++11 -o main main.cpp product.cpp sum.cpp
	exit 0

debug:
	g++ -std=c++11 -DDEBUG -g -o main main.cpp product.cpp sum.cpp
	exit 0

clean:
	rm -f main.exe || true
	exit 0