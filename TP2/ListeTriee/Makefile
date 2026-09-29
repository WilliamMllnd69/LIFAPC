# LIFAP6 - Automne 2017 - R. Chaine

# Pour compiler utiliser simplement la commande make (ou make main.ex)
# Pour compiler la version r�cursive utiliser la commande make main_rec.ex


main.exe : main.o listeTriee.o element.o
# L'executable main.ex doit �tre remis � jour si certains des fichiers 
# main.o liste.o et element.o sont plus r�cents
	g++ main.o listeTriee.o element.o -o main.exe

main_rec.ex : main.o liste_rec.o  element.o
# L'executable main_rec.ex doit �tre remis � jour si certains des fichiers 

# main.o liste_rec.o et element.o sont plus r�cents
	g++ main.o liste_rec.o element.o -o main_rec.exe

element.o : element.cpp element.h
# Le fichier objet element.o doit �tre remis � jour si certains des fichiers
#  element.cpp et element.h sont plus r�cents
	g++ -Wall -std=c++11 -c element.cpp

listeTriee.o : listeTriee.cpp listeTriee.h element.h
# Le fichier objet liste.o doit �tre remis � jour si certains des fichiers
# liste.cpp liste.h et element.h sont plus r�cents
	g++ -Wall -std=c++11 -c listeTriee.cpp

liste_rec.o : listeTriee.cpp listeTriee.h element.h
# Le fichier objet liste_rec.o doit �tre remis � jour si certains des fichiers
# liste.cpp liste.h et element.h sont plus r�cents
	g++ -D_RECURSIF -Wall -std=c++11 -c listeTriee.cpp -o liste_rec.o

main.o : main.cpp listeTriee.h element.h
# Le fichier objet main.o doit �tre remis � jour si certains des fichiers
# main.cpp liste.h et element.h sont plus r�cents
	g++ -Wall -ansi -std=c++11 -c main.cpp

clean :
	-rm *.o *~

veryclean : clean 
	-rm *.exe

