#include "element.h"
#include "skipListe.h"
#include <cstdio>
#include <iostream>

int main(){
    skipListe sl1(0.3);
    for(int i = 5;i>-1;i--){
        sl1.insere(i);
        std::printf("sl1\n");
        sl1.affichage();
    }
    skipListe sl2(sl1);
    std::printf("sl2\n");
    sl2.affichage();
    sl1.supprimeQueue();
    std::printf("sl1\n");
    sl1.affichage();
    sl1.suppressionEnTete();
    std::printf("sl1\n");
    sl1.affichage();
    return 0;
}