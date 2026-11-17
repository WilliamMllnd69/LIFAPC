#include "ArbreBinaireRecherche.h"

ArbreBinaireRecherche::ArbreBinaireRecherche(){
    adRacine = nullptr;
}

void ArbreBinaireRecherche::recherche(const Element & e,Noeud *& pnoeud) const{
    pnoeud = adRacine;
    if(pnoeud!=nullptr){
        while(pnoeud->info!=e){
            if(pnoeud->info<e){
                if(pnoeud->fd!=nullptr){
                    pnoeud = pnoeud->fd;
                }
                else{
                    break;
                }
            }
            else{
                if(pnoeud->fg!=nullptr){
                    pnoeud=pnoeud->fg;
                }
                else{
                    break;
                }
            }
        }
    }
}

void ArbreBinaireRecherche::insertion(const Element & e){
    Noeud * pnoeud;
    recherche(e,pnoeud);
    if(pnoeud!=nullptr){
        if(pnoeud->info>e){
            pnoeud->fg=new Noeud(e);
        }
        else if (pnoeud->info<e)
        {
            pnoeud->fd=new Noeud(e);
        }
    }
    else{
        adRacine = new Noeud(e);
    }
}

void ArbreBinaireRecherche::affichage() const{
    if(adRacine!=nullptr){
        affichage(adRacine);
    }
}

void ArbreBinaireRecherche::affichage(const Noeud * pnoeud) const{
    if(pnoeud->fg!=nullptr){
        affichage(pnoeud->fg);
    }
    std::cout << pnoeud->info << " ";
    if(pnoeud->fd!=nullptr){
        affichage(pnoeud->fd);
    }
}

ArbreBinaireRecherche::~ArbreBinaireRecherche(){
    deleteNoeud(adRacine);
}

void ArbreBinaireRecherche::deleteNoeud(Noeud *& pnoeud){
    if(pnoeud!=nullptr){
        deleteNoeud(pnoeud->fg);
        deleteNoeud(pnoeud->fd);
        delete pnoeud;
        pnoeud = nullptr; 
    }
}

ArbreBinaireRecherche::ArbreBinaireRecherche(const ArbreBinaireRecherche & Arbre){
    adRacine = nullptr;
    if(Arbre.adRacine!=nullptr){
        copieNoeud(adRacine,Arbre.adRacine);
    }
}

void ArbreBinaireRecherche::copieNoeud(Noeud *& pnoeud1,const Noeud * pnoeud2){
    pnoeud1 = new Noeud(pnoeud2->info);
    if(pnoeud2->fd!=nullptr){
        copieNoeud(pnoeud1->fd,pnoeud2->fd);
    }
    if(pnoeud2->fg!=nullptr){
        copieNoeud(pnoeud1->fg,pnoeud2->fg);
    }
}

ArbreBinaireRecherche& ArbreBinaireRecherche::operator = (const ArbreBinaireRecherche & Arbre){
    if(this != &Arbre){
        deleteNoeud(adRacine);
        adRacine=nullptr;
        
        if(Arbre.adRacine!=nullptr){
            copieNoeud(adRacine,Arbre.adRacine);
        }
    }
    return *this;
}

void ArbreBinaireRecherche::suppression(const Element & e){
    Noeud * pnoeud;
    recherche(e,pnoeud);
    if(pnoeud!=nullptr && pnoeud->info==e){
        replace(pnoeud);
    }
}

void ArbreBinaireRecherche::replace(Noeud *& pnoeud){
    if(pnoeud!=nullptr){
        if(pnoeud->fg!=nullptr){
            Noeud * pnoeud1 = pnoeud->fg;
            while(pnoeud1->fd!=nullptr){
                pnoeud1 = pnoeud1->fd;
            }
            pnoeud->info = pnoeud1->info;
            replace(pnoeud1);
        }
        else{
            if(pnoeud->fd!=nullptr){
                Noeud * pnoeud1 = pnoeud->fd;
                while(pnoeud1->fg!=nullptr){
                    pnoeud1 = pnoeud1->fg;
                }
                pnoeud->info = pnoeud1->info;
                replace(pnoeud1);
            }
            else{
                delete pnoeud;
                pnoeud = nullptr;
            }
        }
    }
}