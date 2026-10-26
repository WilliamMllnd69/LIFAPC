#include <iostream>

#ifndef _TABLE
#define _TABLE

class Table;

typedef unsigned int clé;
typedef double information_associée;
typedef (int)(fonctionHachage)(clé);
typedef (int)(fonctionRehachage)(int);



class Case {
    clé c;
    information_associée info;
    int nb_essaie;
}

class Table
{
    private:
        int M;
        int m;
        Case * tab;
        fonctionHachage fH;
        fonctionRehachage fR;
    public:
        Case& recherche(const clé & c) const;
        Table(const fonctionHachage & fHachage,const fonctionRehachage & fRehachage);
        void insertion(const clé & c);
        void suppression(const clé & c);
}
#endif
