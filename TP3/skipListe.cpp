#include <thread>
#include <chrono>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "element.h"
#include "skipListe.h"
#include <cassert>
#include <cmath>
#include <iostream>

skipListe::skipListe(const float & proba){
    assert(proba<1.0&&proba>0.0);
    taille=0;
    sentinelle = new SCellule;
    for(int i=0;i<NIV_MAX;i++){
        sentinelle->psuivant[i] = nullptr;
    }
    p = proba;
    srand((unsigned int)time(NULL));
}

skipListe::skipListe(const skipListe & l)
    : p(l.p), taille(0)
{
    sentinelle = new SCellule;
    for (int i = 0; i < NIV_MAX; i++){
        sentinelle->psuivant[i] = nullptr;
    }
    SCellule * psc = sentinelle;
    SCellule * pscl = l.sentinelle;
    while(pscl->psuivant[0]!=nullptr){
        SCellule* nouvelle = new SCellule;

        nouvelle->info = pscl->psuivant[0]->info;

        for (int i = 0; i < NIV_MAX; i++) {
            nouvelle->psuivant[i] = nullptr;
        }

        psc->psuivant[0] = nouvelle;
        psc = nouvelle;
        pscl = pscl->psuivant[0];
    }
    psc = sentinelle;
    pscl = l.sentinelle;
    SCellule ** tab = new SCellule*[NIV_MAX];
    while (pscl->psuivant[0]!=nullptr)
    {
        int i=1;
        while((i<NIV_MAX)&&(pscl->psuivant[i]!=nullptr)){
            psc->psuivant[i]=recherche(pscl->psuivant[i]->info,tab);
            i++;
        }
        psc = psc->psuivant[0];
        pscl = pscl->psuivant[0];
    }
    delete[] tab;
    taille = l.taille;
}

skipListe::~skipListe(){
    while (taille>0)
    {
        supprimeQueue();
    }
    delete sentinelle;
}

SCellule* skipListe::recherche(const Elem & e, SCellule ** tab) const{
    SCellule *psc= sentinelle;
    int niveau = NIV_MAX-1;
    while(niveau>=0){
        if((psc->psuivant[niveau]==nullptr)||(psc->psuivant[niveau]->info>e)){
            tab[niveau] = psc;
            niveau--;
        }
        else{
            psc=psc->psuivant[niveau];
        }
    }
    if(psc!=sentinelle&&psc->info==e){
        return psc;
    }
    return nullptr;
}

void skipListe::insere(const Elem & e){
    SCellule **tab = new SCellule*[NIV_MAX];
    if(recherche(e,tab)==nullptr){
        int niveau = 1;
        while (niveau < NIV_MAX && ((float)rand() / RAND_MAX) < p)
        {
            niveau++;
        }
        SCellule*scellule = new SCellule;
        scellule->info = e;
        int i=0;
        while(i<niveau){
            scellule->psuivant[i] = tab[i]->psuivant[i];
            tab[i]->psuivant[i]=scellule;
            i++;
        }
        for(i = niveau;i<NIV_MAX;i++){
            scellule->psuivant[i] = nullptr;
        }
        taille++;
    }
    delete[] tab;
}

void skipListe::supprimeQueue()
{
    if (sentinelle->psuivant[0] == nullptr)
        return;
    SCellule * psc = sentinelle;
    while (psc->psuivant[0]!=nullptr)
    {
        psc=psc->psuivant[0];
    }
    SCellule * psc2 = sentinelle;
    int niveau = NIV_MAX-1;
    while(niveau>=0){
        if(psc2->psuivant[niveau]==psc||psc2->psuivant[niveau]==nullptr){
            psc2->psuivant[niveau] = nullptr;
            niveau--;
        }
        else{
            psc2=psc2->psuivant[niveau];
        }
    }
    delete psc;
    taille--;
}

void skipListe::affichage() const{
    SCellule * psc = sentinelle;
    while(psc->psuivant[0]!=nullptr){
        psc=psc->psuivant[0];
        std::cout << psc->info << " ";
    }
    std::cout << std::endl;
}

void skipListe::suppressionEnTete(){
    SCellule * psc = sentinelle;
    if(psc->psuivant[0]!=nullptr){
        SCellule * psc0 = psc->psuivant[0];
        
        for (int i = 0; i < NIV_MAX; i++)
        {
            if (sentinelle->psuivant[i] == psc0)
            {
                sentinelle->psuivant[i] = psc0->psuivant[i];
            }
        }
        delete psc0;
        taille--;
    }
}

void skipListe::vide(){
    while(taille>0){
        suppressionEnTete();
    }
}

void skipListe::init_insere(const Elem & e){
    SCellule ** tab = new SCellule*[NIV_MAX];
    insere(e,sentinelle,NIV_MAX-1,tab);
    delete[] tab;
}

void skipListe::insere(const Elem & e, SCellule * psc,int niveau, SCellule ** tab){
    if(niveau>-1){
        if(psc->psuivant[niveau]==nullptr||psc->psuivant[niveau]->info>e){
            tab[niveau] = psc;
            insere(e,psc,niveau-1,tab);
        }
        else{
            if(psc->psuivant[niveau]->info<e){
                insere(e,psc->psuivant[niveau],niveau,tab);
            }
        }
    }
    else{
        SCellule * psce= new SCellule;
        psce->info = e;

        niveau = 1;
        while(niveau < NIV_MAX && ((float) rand()/RAND_MAX)<p){
            niveau++;
        }

        int i = 0;
        while(i<niveau){
            psce->psuivant[i] = tab[i]->psuivant[i];
            tab[i]->psuivant[i] = psce;
            i++;
        }
        
        for(i = niveau; i<NIV_MAX;i++){
            psce->psuivant[i] = nullptr;
        }

        taille++;
    }
}