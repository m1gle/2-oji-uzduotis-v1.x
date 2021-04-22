clean:
	rm *.o
main: 
	g++ -c function.cpp && g++ -o main main.cpp function.o
maino1: 
	g++ -c function.cpp && g++ -o1 -o main main.cpp function.o
maino2: 
	g++ -c function.cpp && g++ -o2 -o main main.cpp function.o -02
maino3: 
	g++ -c function.cpp && g++ -o3 -o main main.cpp function.o
