clean:
	rm *.o
vector: 
	g++ -c function.cpp && g++ -o vector vector.cpp function.o
list: 
	g++ -c function.cpp && g++ -o list list.cpp function.o
deque: 
	g++ -c function.cpp && g++ -o deque deque.cpp function.o
