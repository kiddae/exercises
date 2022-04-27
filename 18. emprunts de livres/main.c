// http://www.france-ioi.org/algo/task.php?idChapter=656&idTask=2273
/* La bibliothèque possède nbLivres livres indexés de 0 à nbLivres - 1. Chaque
 * jour, un certain nombre de clients demandent à emprunter des livres pour une
 * certaine durée. Si le livre est disponible, la requête du client est
 * satisfaite, sinon le client repart sans livre. */

/* Votre programme doit d'abord lire sur une première ligne deux entiers :
 * nbLivres <= 1000 et nbJours. Pour chacun des jours, votre programme lira un
 * entier nbClients sur une ligne puis nbClients lignes de deux entiers. Le
 * premier entier correspond à l'indice du livre et le second la durée
 * correspondante. (voir l'exemple d'entrée). Il affichera ensuite, sur des
 * lignes séparées, pour chaque client un 1 si le livre peut être prêté et 0
 * dans le cas contraire. */

/* On remarquera que si un client emprunte un livre le jour iJour pendant une
 * durée duree alors celui-ci ne sera de nouveau disponible qu'au jour iJour +
 * duree. De plus, si plusieurs personnes demandent le même livre pendant une
 * journée, seule la première a une chance d'être satisfaite. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  // code
  int nbLivres, nbJours, nbClients_jour;
  scanf("%d %d", &nbLivres, &nbJours);
  int *bibliotheque =
      malloc(sizeof(int) *
             nbLivres); // Initialisation d'un tableau bibliotheque de taille
                        // nbLivres, prenant la durée d'emprunt de chaque livre
  for (int i = 0; i < nbLivres; i++)
    bibliotheque[i] = 0;     // Important, initialisation
  char *clients = malloc(0); // initialisation du tableau des clients (portée)
  int nbClients = 0;
  // Pour chaque jour, les clients
  for (int i = 0; i < nbJours; i++) {
    scanf("%d", &nbClients_jour);
    char *clients_jour = malloc(nbClients_jour); // On enregistre chaque client
    for (int j = 0; j < nbClients_jour; j++) {
      clients_jour[j] = 0;
    }
    // Pour chaque client, les emprunts
    for (int j = 0; j < nbClients_jour; j++) {
      int livre, duree;
      scanf("%d %d", &livre, &duree);
      // On ne laisse emprunter que si la durée avant la fin d'un emprunt est
      // nulle (le livre est disponible)
      if (bibliotheque[livre] == 0) {
        bibliotheque[livre] = duree;
        clients_jour[j] = 1;
      }
    }
    for (int k = 0; k < nbLivres; k++) {
      if (bibliotheque[k] > 0)
        bibliotheque[k]--; // Une journée passe, on décrémente la durée de
                           // chaque livre.
    }
    clients = realloc(clients, nbClients + nbClients_jour);
    memcpy(clients + nbClients, clients_jour, nbClients_jour);
    nbClients += nbClients_jour;
    free(clients_jour);
  }
  free(bibliotheque);
  // Affichage du résultat
  for (int i = 0; i < nbClients; i++) {
    printf("%d\n", clients[i]);
  }

  free(clients);

  return 0;
}
