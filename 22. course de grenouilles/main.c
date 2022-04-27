#include <stdio.h>
#include <stdlib.h>

int max(int[], size_t);
int max_strict(int[], size_t);
/* void printArr(int[], size_t); */

int main(int argc, char **argv) {
  int nbGrenouilles, nbTours;
  int tempsEnTeteGrenouilles[100], posGrenouilles[100];
  for (int i = 0; i < 100; i++) {
    tempsEnTeteGrenouilles[i] = 0;
    posGrenouilles[i] = 0;
  }
  scanf("%100d", &nbGrenouilles);
  scanf("%1000d", &nbTours);
  for (int tour = 0; tour < nbTours; tour++) {
    int m = max_strict(posGrenouilles, nbGrenouilles);
    if (m != -1)
      tempsEnTeteGrenouilles[m]++;
    /* printf("%d:\n", tour + 1); */
    /* printArr(posGrenouilles, nbGrenouilles); */
    /* printArr(tempsEnTeteGrenouilles, nbGrenouilles); */
    int g, d;
    scanf("%d %d", &g, &d);
    posGrenouilles[g - 1] += d;
  }
  // Trouver le gagnant
  printf("%d", max(tempsEnTeteGrenouilles, nbGrenouilles) + 1);
  return 0;
}

int max(int a[], size_t t) {
  // Renvoie l'indice du maximum STRICT du tableau a.
  // Renoive -1 si pas de maximum strict.
  int idxMax = 0;
  int val = -1;
  for (int i = 0; i < t; i++) {
    if (a[i] > val) {
      idxMax = i;
      val = a[i];
    }
  }
  return idxMax;
}
int max_strict(int a[], size_t t) {
  // Renvoie l'indice du maximum STRICT du tableau a.
  // Renoive -1 si pas de maximum strict.
  int idxMax = 0;
  int val = -1;
  int eq = -1;
  for (int i = 0; i < t; i++) {
    if (a[i] > val) {
      idxMax = i;
      val = a[i];
    } else if (a[i] == val) {
      eq = idxMax;
    }
  }
  if (eq != -1 && a[eq] == val)
    return -1;
  else
    return idxMax;
  /* return (val != -1 ? idxMax : -1); */
}

/* void printArr(int a[], size_t t) { */
/*   for (int i = 0; i < t; i++) { */
/*     printf("%d ", a[i]); */
/*   } */
/*   printf("\n"); */
/* } */
