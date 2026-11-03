#include "table.h"
#include "infoAssociee.h"
#include "cle.h"
const int M = 1000;

int premierHachage(const cle & c, const int & taille){
    return c%taille;
}

int reHachageQuadratique(const int & compteur){
    return (compteur-1)*(compteur-1);
}

int main(){
    Table table(M,premierHachage,reHachageQuadratique);
    return 0;
}