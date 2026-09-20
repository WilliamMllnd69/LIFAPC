
#ifndef _LISTE
#define _LISTE

/* Inclusion des modules utilises par le module Liste */
/* (A l'exclusion de ceux qui sont seulement utilises dans l'implantation : */
/* ceux la sont inclus dans le fichier d'implantation) */

#include "element.h" //offrant le type Elem

typedef struct _Cellule
{
  Elem info;
  struct _Cellule *psuivant;
} Cellule;

typedef struct _Liste
{
  Cellule *ad;
  int nb_elem;
} Liste;


void initialiseListeDefaut(Liste *pl);
/* Précondition : *pl non préalablement initialisée */
/* Postcondition : la liste *pl initialisée est vide */

void initialiseListeCopie(Liste *pl1, Liste l2);
/* Précondition : *pl1 non préalablement initialisée,  */
/*                        l2 préalablement initialisée */
/* Postcondition : la liste *pl1 est initialisée avec une copie
/*                         profonde de l2 */

void testamentListe(Liste *pl);
/* Précondition : *pl préalablement initialisée */
/* Postcondition : *pl prête à être détruite */

void affectationListe(Liste *pl1, Liste l2);
/*Précondition : *pl1 et l2 préalablement initialisées  */
/* Postcondition : la liste *pl1 correspond à une copie */
/*                         profonde de l2  après affectation*/

int testListeVide(Liste l);
/* Précondition : l préalablement initialisée */
/* Résultat : 1 si l est vide, 0 sinon */

Elem premierElementListe(Liste l);
/* Précondition : testListeVide(l)==false */
/* Résultat : valeur de l'Elem contenu dans la 1ere Cellule */

Cellule * premiereCelluleListe(Liste l);
/* Précondition : l initialisée  */
/* Resultat : adresse de la premiere cellule de l si testListeVide(l)==false */
/*            NULL sinon */
/*            Attention : la liste l pourra ensuite être modifiée à travers  */
/*            la connaissance de l'adresse de sa première cellule */

Cellule * celluleSuivanteListe(const Cellule *pc, Liste l);
/* Précondition : pc adresse valide d'une Cellule de la Liste l */
/* Résultat : adresse de la cellule suivante si elle existe */
/*            NULL sinon */
/*            Attention : la liste l pourra ensuite être modifiée à travers  */
/*            la connaissance de l'adresse d'une de ses cellules */

Elem elementCelluleListe(const Cellule * pc);
/* Précondition : pc adresse valide d'une Cellule d'une Liste */
/* Résultat : valeur de l'Elem contenu dans la Cellule */

void affichageListe(Liste l);
/* Précondition : l initialisée  */
/* Postcondition : Affichage exhaustif de tous les elements de l */

void ajoutEnTeteListe(Elem e,Liste *pl);
/* Précondition : *pl et e initialisés  */
/* Postcondition : L'Elem e est ajouté en tête de *pl */

void suppressionEnTeteListe(Liste *pl);
/* Précondition : testListeVide(*pl)==false */
/* Postcondition : la liste *pl perd son premier élément */

void videListe(Liste *pl);
/* Précondition : aucune  */
/*                (*pl initialisée)  */
/* Postcondition : testlisteVide(*pl)==true */
/*                 tous les éléments ont été retirés */

void ajoutEnQueueListe(Elem e,Liste *pl);
/* Précondition : *pl et e initialisés  */
/* Postcondition : L'Elem e est ajoute en fin de la liste *pl */

#endif


