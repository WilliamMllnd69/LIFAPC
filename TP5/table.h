#include <iostream>
#include "cle.h"
#include "infoAssociee.h"

#ifndef _TABLE
#define _TABLE

class Table;

typedef int (*fonctionHachage)(const cle&,const int&);
typedef int (*fonctionRehachage)(const int&);

enum statut {
    VIDE,
    OCCUPE,
    SUPPRIME
};

class Case {
    friend class Table;
    private : 
        cle c;
        information_associee info;
        int nb_essaie;
        statut s;
        int index;
};

class Table
{
    private :
        int taille;
        int taille_utilise;
        Case * tab;
        fonctionHachage fH;
        fonctionRehachage fR;
    public:
        Case recherche(const cle & c) const;
        Table(const int & t,const fonctionHachage & fHachage,const fonctionRehachage & fRehachage);
        void insertion(const cle & c,const information_associee & info);
        void suppression(const cle & c);
        ~Table();
        void affichage() const;
        void modifInfo(const cle & c,const information_associee & info);
        information_associee returnInfo(const cle & c) const;
        int returnIndex(const cle & c) const;
};
#endif
