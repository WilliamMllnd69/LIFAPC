#include <cstdio> 
#include "liste.h"
#include <iostream>

Liste::Liste(){
    taille = 0;
    ad = nullptr;
}

void Liste::affichage() const{
    Cellule*pc=ad;
    while(pc!=nullptr){
        std::cout << pc->info << std::endl;
        pc = pc->psuivant;
    }
}

void Liste::ajoutEnTete(const Elem & e){
    Cellule * pc=new Cellule;
    pc->info = e;
    pc->psuivant = ad;
    ad = pc;
    taille++;
}

void Liste::suppressionEnTete(){
    if(!testVide()){
        Cellule * pc = ad;
        ad = ad->psuivant;
        taille--;
        delete pc;
    }
}

bool Liste::testVide() const{
    return ad==nullptr;
}

Liste::~Liste(){
    while(!testVide()){
        suppressionEnTete();
    }
}

Liste& Liste::operator=(const Liste& l)
{
    if (this != &l) {
        // On vide la liste actuelle
        while (!testVide()) {
            suppressionEnTete();
        }

        // On copie les éléments de l
        Cellule* pc1 = l.ad;
        Cellule* pc2 = nullptr;

        while (pc1 != nullptr) {
            Cellule* nouvelle = new Cellule;
            nouvelle->info = pc1->info;
            nouvelle->psuivant = nullptr;

            if (ad == nullptr) {
                ad = nouvelle;
            }
            else {
                pc2->psuivant = nouvelle;
            }

            pc2 = nouvelle;
            pc1 = pc1->psuivant;
        }

        taille = l.taille;
    }

    return *this;
}

Liste::Liste(const Liste& l)
{
    ad = nullptr;
    taille = l.taille;

    Cellule* pc1 = l.ad;
    Cellule* pc2 = nullptr;

    while (pc1 != nullptr) {
        Cellule* nouvelle = new Cellule;

        nouvelle->info = pc1->info;
        nouvelle->psuivant = nullptr;

        if (ad == nullptr) {
            ad = nouvelle;
        }
        else {
            pc2->psuivant = nouvelle;
        }

        pc2 = nouvelle;
        pc1 = pc1->psuivant;
    }
}

Elem Liste::premierElement() const{
    if(!testVide()){
        return ad->info;
    }
}

Cellule * Liste::premiereCellule() const{
    if(!testVide()){
        return ad;
    }
    return 0;
}

Cellule * Liste::celluleSuivante(const Cellule *pc) const{
    Cellule * pc1 = ad;
    while(pc1!=pc){
        if(pc1==nullptr){
            return nullptr;
        }
        pc1=pc1->psuivant;
    }
    return pc1->psuivant;
}

Elem Liste::elementCellule(const Cellule * pc) const{
    return pc->info;
}

void Liste::ajoutEnQueue(const Elem & e){
    if(ad!=nullptr){
        Cellule*pc = ad;
        while(pc->psuivant!=nullptr){
            pc=pc->psuivant;
        }
        pc->psuivant = new Cellule;
        pc->psuivant->info = e;
        pc->psuivant->psuivant = nullptr;
    }
    else{
        ad = new Cellule;
        ad->info = e;
        ad->psuivant = nullptr;
    }

}

Cellule * Liste::rechercheElement(const Elem & e) const{
    Cellule * pc = ad;
    while(pc!=nullptr){
        if(pc->info == e){
            return pc;
        }
        pc = pc->psuivant;
    }
    return 0;
}

void Liste::insereElementApresCellule(const Elem & e,Cellule *pc){
    if(rechercheElement(pc->info)==pc){
        Cellule * nouvelle = new Cellule;
        nouvelle->info = e;
        nouvelle->psuivant = pc->psuivant;
        pc->psuivant = nouvelle;
    }
}

void Liste::modifieInfoCellule(const Elem & e,Cellule *pc){
    if(rechercheElement(pc->info)==pc){
        pc->info = e;
    }
}