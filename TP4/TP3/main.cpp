#include "element.h"
#include "skipListe.h"
#include <cstdio>
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <cstdlib> 

const int NB_SKIP_LISTE = 100;
const int NB_MAX_ELEMENTS = 1000;
const int STEP = 20;

int main(){
    std::ofstream ofs;
    ofs.open("performance.txt");
    if(ofs.bad()) 
        {std::cout<<"Impossible d'ouvrir le fichier performance.txt en ecriture \n"; exit(1);}
    skipListe * tabSkipListe = new skipListe[NB_SKIP_LISTE];
    srand((unsigned int)time(NULL));        
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for(int i=0;i<NB_MAX_ELEMENTS;i++){
        for(int j=0;j<NB_SKIP_LISTE;j++){
            tabSkipListe[j].insere(rand());
            if((i%STEP==0)&&(i!=0)&&(j==NB_SKIP_LISTE-1)){
                end = std::chrono::system_clock::now();
                int temps = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
                temps = temps/(NB_SKIP_LISTE);
                std::cout << temps << std::endl;
                ofs << i << ' ' << temps << std::endl;
            }
        }
    }
    ofs.close();
    delete[] tabSkipListe;
    return 0;
}