all: main

main: main.cpp library.cpp book.cpp library.h book.h
	g++ -std=c++11 -o main main.cpp library.cpp book.cpp
	exit 0

clean:
	rm -f main.exe || true
	exit 0