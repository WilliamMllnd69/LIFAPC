// LIFAP6 - Automne 2017 - R. Chaine

#include "element.h"
#include "listeTriee.h"
#include <cstdio>

int main()
{
  Liste_Triee lili;
  std::printf("Lili\n");
  lili.affichage();
  for(int i=5;i>0;i--)
    lili.insere(i);
  std::printf("Lili\n");
  lili.affichage();
  std::printf("Lili\n");
  lili.affichageSecondNiveau();
  Liste_Triee lolo(lili);
  std::printf("Lolo\n");
  lolo.affichage();
  std::printf("Lolo\n");
  lolo.affichageSecondNiveau();
  lili.vide();
  std::printf("Lili\n");
  lili.affichage();
  lili=lolo;
  printf("Lili\n");
  lili.affichage();/**/
  std::printf("Lili\n");
  lili.affichageSecondNiveau();
  return 0;
}
