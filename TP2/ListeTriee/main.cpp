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
  Liste_Triee lolo(lili);
  std::printf("Lolo\n");
  lolo.affichage();
  lili.vide();
  std::printf("Lili\n");
  lili.affichage();
  lili=lolo;
  printf("Lili\n");
  lili.affichage();/**/
  return 0;
}
