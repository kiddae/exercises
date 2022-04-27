#include <stdio.h>
#include <stdlib.h>
void afficheLigne(int ligne, int nbLettres);

int main(int argc, char **argv) {
  int nbLettres;
  scanf("%d", &nbLettres);
  for (int l = 0; l < nbLettres;
       l++) // on compte à partir de 0, on s'arrête à nbLettres
    afficheLigne(l, nbLettres);
  /* printf("---\n"); */
  for (int l = nbLettres - 2; l >= 0;
       l--) // chemin inverse, - 2 pour ne pas répéter.
    afficheLigne(l, nbLettres);
  return 0;
}

void afficheLigne(int ligne, int nbLettres) {
  for (int i = 0; i < ligne; i++)
    printf("%c", 97 + i); // 97 = 'a'
  for (int i = 0; i < nbLettres * 2 - 1 - (ligne * 2); i++)
    printf("%c", 97 + ligne);
  for (int i = ligne - 1; i >= 0; i--)
    printf("%c", 97 + i);
  printf("\n");
}
