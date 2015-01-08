CXX=clang++-mp-3.4
CC=clang++-mp-3.4
CXXFLAGS=`pkg-config --cflags --libs opencv`
LDFLAGS=`pkg-config --cflags --libs opencv`
main: main.o
clean:
	rm -f *.o
	rm -f main
