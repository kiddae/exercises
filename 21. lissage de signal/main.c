#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void lisse(float valeurs[100], int nbMesures);
int checkDist(float valeurs[], int nbMesures, float diff);

int main(int argc, char **argv) {
  // Input et remplissage du tableau.
  int nbMesures;
  float diffMax;
  float valeurs[100];
  scanf("%d", &nbMesures);
  scanf("%f", &diffMax);
  for (int i = 0; i < 100; i++) {
    float v;
    if (i < nbMesures) {
      scanf("%f", &v);
    } else {
      v = 0;
    }
    valeurs[i] = v;
  }
  // comptage
  int c = 0;
  while (!checkDist(valeurs, nbMesures, diffMax)) {
    c++;
    lisse(valeurs, nbMesures);
  }
  printf("%d\n", c);

  return 0;
}

void lisse(float valeurs[100], int nbMesures) {
  float copie[100];
  for (int i = 0; i < nbMesures; i++)
    copie[i] = valeurs[i];
  for (int i = 1; i < nbMesures - 1; i++) {
    valeurs[i] = (copie[i - 1] + copie[i + 1]) / 2;
  }
}

int checkDist(float valeurs[], int nbMesures, float diff) {
  int i = 0;
  while (i < nbMesures - 1 && fabs(valeurs[i] - valeurs[i + 1]) < diff)
    i++;
  return (i < nbMesures - 1 ? 0 : 1);
}
