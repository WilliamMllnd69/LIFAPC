#include "table.h"

Table::Table(const int & t,const fonctionHachage & fHachage,const fonctionRehachage & fRehachage){
    taille = t;
    taille_utilise = 0;
    tab = new Case[t];
    for(int i=0;i<t;i++){
        tab[i].s = VIDE;
        tab[i].index = i;
    }
    fH = fHachage;
    fR = fRehachage;
}

Table::~Table(){
    delete [] tab;
}

Case Table::recherche(const cle & c) const {
    int index1 = fH(c,taille);
    int compteur = 1;
    int pas;
    int index=index1;
    while(((tab[index].s!=OCCUPE)||((tab[index].s==OCCUPE)&&(tab[index].c!=c)))&&(compteur<(taille+1)/2)){
        compteur++;
        pas = fR(compteur);
        index = (index1 + pas) % taille;
    }
    Case sentinelle;
    sentinelle.index = index;
    sentinelle.nb_essaie = compteur;
    return sentinelle;
}

void Table::insertion(const cle & c,const information_associee & info){
    Case sentinelle = recherche(c);
    int indice = sentinelle.index;
    if(tab[indice].s!=OCCUPE){
        tab[indice].c = c;
        tab[indice].info = info;
        tab[indice].nb_essaie = sentinelle.nb_essaie;
        tab[indice].s = OCCUPE;
        taille_utilise++;
    }
}

void Table::suppression(const cle & c){
    if(returnIndex(c)!=taille){
        tab[returnIndex(c)].s = SUPPRIME;
        taille_utilise--;
    }
}

void Table::affichage() const{
    for(int i=0;i<taille;i++){
        if(tab[i].s==OCCUPE){
            std::cout <<"cle : "<< tab[i].c << " nb essaie : " << tab[i].nb_essaie << std::endl;
        }
    }
}

void Table::modifInfo(const cle & c,const information_associee & info){
    if(returnIndex(c)!=taille){
        tab[returnIndex(c)].info = info;
    }
}

information_associee Table::returnInfo(const cle & c) const{
    if(returnIndex(c)!=taille){
        return tab[returnIndex(c)].info;
    }
    return 0.0;
}

int Table::returnIndex(const cle & c) const {
    int indice = recherche(c).index;
    if((tab[indice].c == c)&&(tab[indice].s == OCCUPE)){
        return indice;
    }
    return taille;
}