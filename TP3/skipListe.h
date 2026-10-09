#ifndef _SKIP_LISTE
#define _SKIP_LISTE

#include "element.h"

class skipListe;

const int NIV_MAX = 20;

class SCellule
{
    friend class skipListe;

    
    Elem info;
    SCellule * psuivant[NIV_MAX];
};

class skipListe
{
private:
    float p;//probabilité d'un étage
    SCellule * sentinelle;
    int taille;
public:
    skipListe(const float & proba);
    skipListe(const skipListe & l);
    ~skipListe();
    SCellule* recherche(const Elem & e, SCellule ** tab) const;
    void insere(const Elem & e);
    void supprimeQueue();
    void affichage() const;
    void suppressionEnTete();
    void vide();
    void init_insere(const Elem & e);
    void insere(const Elem & e, SCellule * psc,int niveau,SCellule**tab);
};

#endif