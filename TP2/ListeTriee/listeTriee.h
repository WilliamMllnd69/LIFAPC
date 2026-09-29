// LIFAP6 - R. Chaine

#ifndef _LISTE_TRIEE
#define _LISTE_TRIEE

#include "element.h" //offrant le type Elem

class Liste_Triee; // declaration

class Cellule
{
    friend class Liste_Triee;

    private :
        Elem info;
        Cellule * psuivant;
        Cellule * psecond;
};

class Liste_Triee
{
    public :
    //Constructeurs-------------------------------------------------------------
    Liste_Triee();
    //Postcondition : la liste *this est  initialisée comme étant vide
    Liste_Triee(const Liste_Triee & l);
    //Postcondition :  la liste *this est initialisée en copie profonde de l
    //         (mais elles sont totalement independantes l'une de l'autre)
    
    //Destructeur---------------------------------------------------------------
    ~Liste_Triee();
     //Postcondition : l'espace occupé par *this  peut-être restitué
    
    //Affectation---------------------------------------------------------------
    Liste_Triee & operator = (const Liste_Triee & l);
    //Précondition : aucune
    //       (la liste *this à affecter et l doivent être initialisées)
    //Postcondition : la liste *this correspond à une copie profonde de l
    //           (mais elles sont totalement independantes l'une de l'autre)
    
    bool testVide() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : true si *this est vide, false sinon
    
    Elem premierElement() const;
    //Précondition : testListeVide(l)==false
    //Résultat : valeur de l'Elem contenu dans la 1ere Cellule
    
    Cellule * premiereCellule() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : adresse de la premiere cellule de *this si this->testVide()==false
    //           nullptr sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse de sa première cellule
    
    Cellule * celluleSuivante(const Cellule *pc) const;
    //Précondition : pc adresse valide d'une Cellule de la Liste *this
    //Résultat : adresse de la cellule suivante si elle existe
    //           nullptr sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse d'une de ses cellules
    
    Elem elementCellule(const Cellule * pc) const;
    //Précondition : pc adresse valide d'une Cellule de la Liste *this
    //Résultat : valeur de l'Elem contenu dans la Cellule
    
    void affichage() const;
    //Précondition : aucune
    //               (*this initialisée)
    //Postcondition : Affichage exhaustif de tous les éléments de *this
    
    void suppressionEnTete();
    //Précondition : this->testVide()==false
    //Postcondition : la liste *this perd son premier élément
    
    void vide();
    //Précondition : aucune
    //               (*this initialisée)
    //Postcondition : this->testVide()==true (tous les éléments sont retirés)
    
    //OPERATIONS QUI POURRAIENT ETRE AJOUTEES AU MODULE LISTE
    
    Cellule * rechercheElement(const Elem & e) const;
    //Précondition : aucune
    //               (*this initialisée)
    //Résultat : Adresse de la première Cellule de *this contenant e, nullptr sinon
    //           Attention : la liste *this pourrait ensuite etre modifiée à travers
    //           la connaissance de l'adresse d'une de ses cellules

    void insere(const Elem & e);

    void affichageSecondNiveau() const;
 
    private :
    void affichageDepuisCellule(const Cellule * pc) const;
    void etablissementSecondNiveau();
    //Donnees membres-----------------------------------------------------------
        Cellule sentinelle;
        int taille;
        bool chainage_niveau_deux;
};


#endif
