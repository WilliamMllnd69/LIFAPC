all: executable.out

executable.out: main.o liste.o element.o
	g++ main.o liste.o element.o -o executable.out

main.o: main.cpp liste.h element.h
	g++ -c main.cpp

liste.o: liste.h liste.cpp element.h
	g++ -c liste.cpp

element.o: element.h element.cpp
	g++ -c element.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out