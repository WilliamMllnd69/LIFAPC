// LIFAPC - R. Chaine

#include <cstdio>
#include "element.h" //offrant le type Elem
#include "listeTriee.h"
//#include <cassert> //Si on veut faire des tests de preconditions en mode debug


Liste_Triee::Liste_Triee()
{
    sentinelle.psuivant=nullptr; //this->ad=nullptr;
    taille=0;
}

bool Liste_Triee::testVide() const
{
    return taille==0; //this->ad==nullptr;
}

Elem Liste_Triee::premierElement() const
{
    return sentinelle.psuivant->info; //this->ad->info;
}

Cellule * Liste_Triee::premiereCellule() const
{
    return sentinelle.psuivant; //this->ad;
}

Cellule * Liste_Triee::celluleSuivante(const Cellule *c) const
{
  return c->psuivant;
}

Elem Liste_Triee::elementCellule(const Cellule * c) const
{
  return c->info;
}

#ifndef _RECURSIF 
void Liste_Triee::affichage() const
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


void Liste_Triee::suppressionEnTete()
{
  //assert(testVide()); //Si on veut faire des tests en mode debug
  Cellule *temp = sentinelle.psuivant; // temp=this->ad; On memorise l'adresse de la premiere Cellule
  sentinelle.psuivant=sentinelle.psuivant->psuivant; //this->ad=this->ad->psuivant; La deuxieme Cellule de *this devient la premiere
  delete temp;//L'espace occupe par la Cellule abandonnee est restitue
  taille--; // this->taille--;
}

#ifndef _RECURSIF 
void Liste_Triee::vide()
{
  while(!testVide()) //while(!this->testVide())
    {
      suppressionEnTete(); //this->suppressionEnTete();
    }
}
#endif
void Liste_Triee::insere(const Elem &e)
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

Liste_Triee::Liste_Triee(const Liste_Triee & l)
{ 
  sentinelle.psuivant=nullptr;
  this->taille=0;
  if(!l.testVide())
    {
      Cellule *temp1=l.sentinelle.psuivant;
      insere(temp1->info);
      temp1=temp1->psuivant;
      while(temp1!=nullptr)
      { 
        insere(temp1->info);
        temp1=temp1->psuivant; //tmp1 pointe sur la premiere Cellule de l
                                // dont l'info n'a pas ete ajoutee a *this
      }
    }
}

Liste_Triee::~Liste_Triee()
{
  this->vide();
}

Liste_Triee & Liste_Triee::operator=(const Liste_Triee & l)
{
  if (this!=&l)
    {
      this->vide();
      if(!l.testVide())
	   {
	     Cellule *temp1=l.sentinelle.psuivant;
       insere(temp1->info);
	     temp1=temp1->psuivant;
         while(temp1!=nullptr)
	      { 
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
void Liste_Triee::affichageDepuisCellule(const Cellule * c) const
{
    if(c!=nullptr) //il reste des cellules a afficher
    {
        affichageElement(c->info);
        affichageDepuisCellule(c->psuivant);//this->afficheDepuisCellule(c->psuivant);
    }
}

void Liste_Triee::affichage() const
{
    std::printf("Liste (rec) :");
    affichageDepuisCellule(sentinelle.psuivant); // this->afficheDepuisCellule(this->ad);
    std::putchar('\n');
}

void Liste_Triee::vide()
{
    if(!testVide()) //  if(!this->testVide())
    {
        suppressionEnTete(); //this->suppressionEnTete()
        vide(); //this->vide()
    }
}

#endif
