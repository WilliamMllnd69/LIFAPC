all: executable.out

executable.out: main.o table.o infoAssociee.o cle.o
	g++ main.o table.o infoAssociee.o cle.o -o executable.out

main.o: main.cpp table.h infoAssociee.h cle.h
	g++ -c main.cpp

table.o: table.cpp table.h infoAssociee.h cle.h
	g++ -c table.cpp

infoAssociee.o: infoAssociee.cpp infoAssociee.h
	g++ -c infoAssociee.cpp

cle.o: cle.cpp cle.h
	g++ -c cle.cpp

clean:
	rm *.o

veryclean:
	rm *.out