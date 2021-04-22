clean:
	rm *.o
main: 
	g++ -c function.cpp && g++ -o main main.cpp function.o
