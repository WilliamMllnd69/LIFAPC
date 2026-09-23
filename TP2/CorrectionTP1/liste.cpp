// LIFAPC - R. Chaine

#include <cstdio>
#include "element.h" //offrant le type Elem
#include "liste.h"
//#include <cassert> //Si on veut faire des tests de preconditions en mode debug


Liste::Liste()
{
    sentinelle.psuivant=nullptr; //this->ad=nullptr;
    taille=0;
}

bool Liste::testVide() const
{
    return taille==0; //this->ad==nullptr;
}

Elem Liste::premierElement() const
{
    return sentinelle.psuivant->info; //this->ad->info;
}

Cellule * Liste::premiereCellule() const
{
    return sentinelle.psuivant; //this->ad;
}

Cellule * Liste::celluleSuivante(const Cellule *c) const
{
  return c->psuivant;
}

Elem Liste::elementCellule(const Cellule * c) const
{
  return c->info;
}

#ifndef _RECURSIF 
void Liste::affichage() const
{
  std::printf("Liste (it) ");
  Cellule *temp=sentinelle.psuivant; 
  while(temp!=nullptr)
    {
      affichageElement(temp->info);
      temp=temp->psuivant;
    }
  std::putchar('\n');
}
#endif
/*
void Liste::ajoutEnTete(const Elem & e)
{
  //Creation d'une nouvelle Cellule
  Cellule *temp=new Cellule;
  temp->info=e;
  temp->psuivant=sentinelle.psuivant;//dont la cellule suivante est la premiere Cellule
                          //de la Liste (*this)
  sentinelle.psuivant=temp; // this->ad=temp; *temp devient la premiere Cellule de la liste (*this)
  taille++; // this->taille++;
}*/

void Liste::suppressionEnTete()
{
  //assert(testVide()); //Si on veut faire des tests en mode debug
  Cellule *temp = sentinelle.psuivant; // temp=this->ad; On memorise l'adresse de la premiere Cellule
  sentinelle.psuivant=sentinelle.psuivant->psuivant; //this->ad=this->ad->psuivant; La deuxieme Cellule de *this devient la premiere
  delete temp;//L'espace occupe par la Cellule abandonnee est restitue
  taille--; // this->taille--;
}

#ifndef _RECURSIF 
void Liste::vide()
{
  while(!testVide()) //while(!this->testVide())
    {
      suppressionEnTete(); //this->suppressionEnTete();
    }
}
#endif
void Liste::insere(const Elem &e)
{
    Cellule *temp1 = sentinelle.psuivant;
    Cellule *temp2 = &sentinelle;

    while (temp1 != nullptr && temp1->info < e)
    {
        temp2 = temp1;
        temp1 = temp1->psuivant;
    }

    Cellule *c = new Cellule;
    c->info = e;
    c->psuivant = temp1;

    temp2->psuivant = c;

    taille++;
}

/*
#ifndef _RECURSIF 
void Liste::ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
// procedure interne au module : 
// *this NON VIDE et c est l'adresse d'une Cellule de *this
{
  //assert(!testVide()); //Si on veut faire des tests en mode debug
  Cellule *temp=c;
  while(temp->psuivant!=nullptr)
    temp=temp->psuivant;
  //temp pointe sur la derniere cellule
  temp->psuivant=new Cellule;
  temp->psuivant->info=e;
  temp->psuivant->psuivant=nullptr;
  taille++; // this->taille++;
}
#endif

void Liste::ajoutEnQueue(const Elem & e)
{ // Remarque : Si on utilisait une cellule sentinelle, il ne serait
  // plus necessaire de distinguer le cas vide du cas non vide.
  if(this->testVide())
    this->ajoutEnTete(e);
  else
    this->ajoutEnQueueConnaissantUneCellule(e,sentinelle.psuivant);
}*/


Liste::Liste(const Liste & l)
{ 
  sentinelle.psuivant=nullptr;
  this->taille=0;
  if(!l.testVide())
    {
      Cellule *temp1=l.sentinelle.psuivant;
      insere(temp1->info);
      //this->ajoutEnQueue(temp1->info);
      //Cellule *temp2=sentinelle.psuivant;
      temp1=temp1->psuivant;
      while(temp1!=nullptr)
      { //Il reste des elements a ajouter
          //this->ajoutEnQueueConnaissantUneCellule(temp1->info,temp2);
          //temp2=temp2->psuivant; //Ainsi temp2 pointe sur la derniere cellule de *this
          insere(temp1->info);
          temp1=temp1->psuivant; //tmp1 pointe sur la premiere Cellule de l
                                // dont l'info n'a pas ete ajoutee a *this
      }
    }
}

Liste::~Liste()
{
  this->vide();
}

Liste & Liste::operator=(const Liste & l)
{
  if (this!=&l)
    {
      this->vide();
      if(!l.testVide())
	   {
	     Cellule *temp1=l.sentinelle.psuivant;
	     //this->ajoutEnQueue(temp1->info);
       insere(temp1->info);
	     //Cellule *temp2=sentinelle.psuivant;
	     temp1=temp1->psuivant;
         while(temp1!=nullptr)
	      { //Il reste des elements a ajouter
	        //this->ajoutEnQueueConnaissantUneCellule(temp1->info,temp2);
	        //temp2=temp2->psuivant; //Ainsi temp2 pointe sur la derniere cellule de *this
          insere(temp1->info);
	        temp1=temp1->psuivant;
	      }
	   }
     }
  return *this;
}/**/

#ifdef _RECURSIF
// Version recursive de certaines fonctions/procedures
// pour lesquelles on a donne une version iterative plus haut

//Procedure interne au module
void Liste::affichageDepuisCellule(const Cellule * c) const
{
    if(c!=nullptr) //il reste des cellules a afficher
    {
        affichageElement(c->info);
        affichageDepuisCellule(c->psuivant);//this->afficheDepuisCellule(c->psuivant);
    }
}

void Liste::affichage() const
{
    std::printf("Liste (rec) :");
    affichageDepuisCellule(sentinelle.psuivant); // this->afficheDepuisCellule(this->ad);
    std::putchar('\n');
}

void Liste::vide()
{
    if(!testVide()) //  if(!this->testVide())
    {
        suppressionEnTete(); //this->suppressionEnTete()
        vide(); //this->vide()
    }
}
/*
void Liste::ajoutEnQueueConnaissantUneCellule(const Elem & e, Cellule *c)
//procedure interne au module :
// *this NON VIDE et c est l'adresse d'une Cellule de *this
{
    //assert(!testVide()); //Si on veut faire des tests en mode debug
    if(c->psuivant==nullptr)
    {
        c->psuivant=new Cellule;
        c->psuivant->info=e;
        c->psuivant->psuivant=nullptr;
        taille++; // this->taille++;
    }
    else
        this->ajoutEnQueueConnaissantUneCellule(e,c->psuivant);
}
*/

#endif
