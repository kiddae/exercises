# https://prologin.org/train/2022/qualification/enter-the-matriks

# Énoncé

# Vous êtes l'élu, le maître de la Matriks. Cependant, comme vous le savez car vous êtes un fan incontestable de la trilogie des sœurs Wachowskis, il y a eu plusieurs versions de la matrice avant d'aboutir à celle dans laquelle ont vécu Neo, Morpheus et Trinity.

# En effet, au lieu d'être dans la matrice (forme finale du cocon informatique dans lequel sont immergés les êtres humains), vous êtes dans une version plus primaire, une version Test. Cette pre-release de la matrice s'appelle la "Matriks". Pour en sortir et sauver Sion, la dernière ville des Hommes encore debout, vous devez trouver deux clés (des listes d'entiers). Ces deux clés sont cachées dans le code de la Matriks (une grosse liste d'entiers écrits en vert sur fond noir qui descend en colonnes de manière assez stylé).

# Vous savez deux choses : le produit des sommes de ces deux clés est égal à un nombre magique

# , qui vous est donné. Et vous savez que les deux clés doivent être les plus longues possibles (maximiser la somme des longueurs des sous-listes). À vous de trouver ces clés !

# Attention, l'ordre des clés importe, vous devez d'abord afficher la plus grande des deux listes, si elles sont de même taille, affichez d'abord celle dont la somme est la plus grande.

# S'il n'y a pas de sous-liste qui respectent ces conditions, écrire "IMPOSSIBLE" (vous n'êtes alors peut-être pas l'élu ?).

# Note : une sous-liste d'une liste L est une sous-partie contiguë de L. Par exemple si L = [1 2 3 4 5], alors [1 2 3] et [3 4] sont des sous-listes mais pas [1 3 4].
# Entrée

# L’entrée contiendra :

#     Sur la première ligne, un entier :

# , le nombre magique.
# Sur la ligne suivante, un entier :
# , la longueur du code la Matriks.
# Sur la ligne suivante, une liste de

#     entiers séparés par des espaces : L, le code de la Matriks.

# Sortie

# Les deux clés (chacune sur une ligne) ou le message "IMPOSSIBLE".
# Contraintes

# Runtime constraints

# Maximum memory usage
#     10000 kilobytes
# Maximum execution time
#     2000 milliseconds

# Input/output samples

# Sample input

#     105
#     5
#     1 2 3 4 5

# Sample output

#     1 2 3 4 5
#     3 4

# Note

#     On a

# et . Ce qui nous donne

#     !

# Sample input

#     6
#     2
#     2 3

# Sample output

#     3
#     2

def resoudre(x, n, l):
    """
    :param x: le nombre magique
    :type x: int
    :param n: la longueur du code la Matriks
    :type n: int
    :param l: le code de la Matriks
    :type l: list[int]
    """
    # TODO Les deux clés (chacune sur une ligne) ou le message "IMPOSSIBLE".

    # Lister les ensembles possibles pour lesquels la somme divise X.
    cles_possibles = []
    for i in range(n+1):
        for j in range(i+1, n+1):
            if sum(l[i:j]) in [a for a in range(1, x+1) if x % a == 0] and l[i:j] not in cles_possibles:
                cles_possibles.append(l[i:j])

    # Identifier les cles qui correspondent, tels que leur taille/somme est la plus grande possible et que somme(cle1) * somme(cle2) = X
    # Liste de tous les couples possibles
    couples_possibles = []
    for i in range(len(cles_possibles)):
        for j in range(i+1, len(cles_possibles)):
            couple = sorted((cles_possibles[i], cles_possibles[j]), key=lambda i: (
                len(i), sum(i)), reverse=True)  # Trié pour obtenir le bon ordre
            if couple not in couples_possibles and sum(cles_possibles[i])*sum(cles_possibles[j]) == x:
                couples_possibles.append(couple)
    # Obtention des cles correspondantes
    couples_possibles = sorted(
        couples_possibles, key=lambda i: (len(i[0])+len(i[1]), sum(i[0])+sum(i[1])), reverse=True)
    if len(couples_possibles) != 0:
        cle1, cle2 = couples_possibles[0]
    else:
        cle1 = []
        cle2 = []

    # Résultats.
    if cle1 != [] and cle2 != []:
        print(" ".join([str(i) for i in cle1]))
        print(" ".join([str(i) for i in cle2]))
    else:
        print("IMPOSSIBLE")
    pass


if __name__ == '__main__':
    x = int(input())
    n = int(input())
    l = list(map(int, input().split()))
    resoudre(x, n, l)
