// LIFAPC - R. Chaine
#include <thread>
#include <chrono>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "element.h" //offrant le type Elem
#include "listeTriee.h"
//#include <cassert> //Si on veut faire des tests de preconditions en mode debug


Liste_Triee::Liste_Triee()
{
    sentinelle.psuivant=nullptr; 
    sentinelle.psecond=nullptr;
    taille=0;
    chainage_niveau_deux = true;
}

bool Liste_Triee::testVide() const
{
    return taille==0; 
}

Elem Liste_Triee::premierElement() const
{
    return sentinelle.psuivant->info; 
}

Cellule * Liste_Triee::premiereCellule() const
{
    return sentinelle.psuivant; 
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

void Liste_Triee::etablissementSecondNiveau()
{
  Cellule * pc1 = &sentinelle;
  while(pc1!=nullptr){
    pc1->psecond = nullptr;
    pc1=pc1->psuivant;
  }
  pc1 = &sentinelle;
  Cellule * pc2 = pc1->psuivant;
  pc1->psecond = pc2;
  while(pc2!=nullptr){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    srand((unsigned int)time(NULL));
    if(rand()%2==1){
      pc1->psecond = pc2;
      pc2 = pc2->psuivant;
    }
    else{
      pc1 = pc1->psecond;
      pc1->psecond = pc2;
    }
  }
  /*
  pc->psecond = pc->psuivant;
  pc = pc->psuivant;
  while(pc!=nullptr && pc->psuivant!=nullptr && pc->psuivant->psuivant!=nullptr){
    pc->psecond = pc->psuivant->psuivant;
    pc = pc->psecond;
  }*/
  chainage_niveau_deux = true;
}

void Liste_Triee::suppressionEnTete()
{
  //assert(testVide()); //Si on veut faire des tests en mode debug
  Cellule *temp = sentinelle.psuivant; 
  sentinelle.psuivant=sentinelle.psuivant->psuivant;
  delete temp;
  taille--; 
  chainage_niveau_deux = false;
  etablissementSecondNiveau();
}

void Liste_Triee::affichageSecondNiveau() const{
  std::printf("Liste (it) ");
  const Cellule * pc = &sentinelle;
  while(pc!=nullptr){
    if(pc!=&sentinelle){
      affichageElement(pc->info);
    }
    pc=pc->psecond;
  }
  std::putchar('\n');
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
    chainage_niveau_deux = false;
    etablissementSecondNiveau();
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
