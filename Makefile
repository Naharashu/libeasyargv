CXX=g++
CXX_FLAGS=-O2 -g

all: main

main:
	$(CXX) $(CXX_FLAGS) -c -fPIC libeasyargv.cpp -o libeasyargv.o
	$(CXX) -shared libeasyargv.o -o libeasyargv.so

install:
	sudo cp libeasyargv.h /usr/local/include/libeasyargv.h
	sudo cp libeasyargv.so /usr/lib/libeasyargv.so

clean:
	rm -f libeasyargv.so libeasyargv.o

uninstall:
	rm -f /usr/lib/libeasyargv.so
	rm -f /usr/local/include/libeasyargv.h
