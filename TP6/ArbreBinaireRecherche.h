#ifndef _ABR
#define _ABR

#include <iostream>

class ArbreBinaireRecherche;

typedef float Element;

class Noeud {
    friend class ArbreBinaireRecherche;
    private:
        Element info;
        Noeud * fg;
        Noeud * fd;
    public:
        Noeud(Element e) : info(e), fg(nullptr), fd(nullptr) {}
};

class ArbreBinaireRecherche
{
private:
    Noeud * adRacine;
public:
    ArbreBinaireRecherche();
    ArbreBinaireRecherche(const ArbreBinaireRecherche & Arbre);
    void copieNoeud(Noeud *& pnoeud1,const Noeud * pnoeud2);
    ArbreBinaireRecherche& operator = (const ArbreBinaireRecherche & Arbre);
    void recherche(const Element & e,Noeud *& pnoeud) const;
    void insertion(const Element & e);
    void affichage() const;
    void affichage(const Noeud * pnoeud) const;
    ~ArbreBinaireRecherche();
    void deleteNoeud(Noeud *& pnoeud);
    void suppression(const Element & e);
    void replace(Noeud *& pnoeud);
};

#endif