# https://prologin.org/train/2022/qualification/fuite_de_clavier

# Énoncé

# Joseph Marchand est un petit brigand. Il a installé sur l'ordinateur de son amie Alice un keylogger (un logiciel espion qui capture les entrées du clavier) en dépit des réglementations en vigueur qui condamnent fermement ce genre de pratique.

# Il essaie en effet de récupérer le mot de passe Prologin d'Alice ! Malheureusement pour lui, le keylogger a enregistré toutes les frappes sur le clavier, sans distinction de s'il s'agissait d'un mot de passe ou non.

# Joseph se retrouve donc avec une suite de caractères composé de lettres minuscules, majuscules, de nombres et de caractères spéciaux.

# Il sait juste que le mot de passe d'Alice répond aux exigences de sécurité suivantes:

#     Contenir au moins une minuscule (a-z)
#     Contenir au moins une majuscule (A-Z)
#     Contenir au moins un nombre (0-9),
#     Contenir au moins un caractère spécial (!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~),
#     La taille du mot de passe est de

#     caractères.

# Aidez Joseph à savoir combien de chaines de k caractères pourraient être le mot de passe d'Alice.
# Entrée

# L’entrée contiendra :

#     Sur la première ligne, un entier : n, taille de la chaîne.
#     Sur la ligne suivante, un entier : k, taille du mot de passe.
#     Sur la ligne suivante, une liste de n caractères juxtaposés : chaine, la chaîne de caractères récupérée du keylogger.

# Sortie

# Afficher le nombre de mots de passes possibles parmi la chaîne
# Contraintes

# Runtime constraints

# Maximum memory usage
#     1000 kilobytes
# Maximum execution time
#     1000 milliseconds

# Input/output samples

# Sample input

#     30
#     6
#     G=d:Dl:T=9NS1c$9qC%,^EdUVLnU-7

# Sample output

#     11

# Note

#     Si on liste toutes les sous-chaines possibles de longueur 6, on obtient:

#      1
#      2
#      3
#      4
#      5
#      6
#      7
#      8
#      9
#     10
#     11
#     12
#     13
#     14
#     15
#     16
#     17
#     18
#     19
#     20
#     21
#     22
#     23
#     24
#     25


#     G=d:Dl -> Invalide
#     =d:Dl: -> Invalide
#     d:Dl:T -> Invalide
#     :Dl:T= -> Invalide
#     Dl:T=9 -> Valide
#     l:T=9N -> Valide
#     :T=9NS -> Invalide
#     T=9NS1 -> Invalide
#     =9NS1c -> Valide
#     9NS1c$ -> Valide
#     NS1c$9 -> Valide
#     S1c$9q -> Valide
#     1c$9qC -> Valide
#     c$9qC% -> Valide
#     $9qC%, -> Valide
#     9qC%,^ -> Valide
#     qC%,^E -> Invalide
#     C%,^Ed -> Invalide
#     %,^EdU -> Invalide
#     ,^EdUV -> Invalide
#     ^EdUVL -> Invalide
#     EdUVLn -> Invalide
#     dUVLnU -> Invalide
#     UVLnU- -> Invalide
#     VLnU-7 -> Valide

#     On récupère donc 11 sous-chaines qui répondent aux exigences.

# Sample input

#     10
#     4
#     !84cDc1s_p

# Sample output

#     0

# Note

#     A nouveau, si on liste toutes les sous-chaînes de 4 caractères, on obtient :

#     1
#     2
#     3
#     4
#     5
#     6
#     7


#     !84c -> Invalide
#     84cD -> Invalide
#     4cDc -> Invalide
#     cDc1 -> Invalide
#     Dc1s -> Invalide
#     c1s_ -> Invalide
#     1s_p -> Invalide

#     Aucune sous-chaîne ne réponds aux exigences.

import re


def fuite_de_clavier(n, k, chaine):
    """
    :param n: taille de la chaîne
    :type n: int
    :param k: taille du mot de passe
    :type k: int
    :param chaine: la chaîne contenant le mot de passe
    :type chaine: list[str]
    """
    # TODO afficher le nombre de mots de passes possibles parmi la chaîne
    count = 0
    for i in range(n-k+1):
        s = "".join(chaine[i:i+k])
        if re.search(r"[a-z]+", s) and re.search(r"[A-Z]+", s) and re.search(r"[0-9]+", s) and re.search(r"[!\"#\$%&\'\(\)\*\+,\-\.\/:;<=>\?@\[\\\]\^_`\{\|\}~]+", s):
            count += 1
    print(count)
    pass


if __name__ == '__main__':
    n = int(input())
    k = int(input())
    chaine = list(input())
    fuite_de_clavier(n, k, chaine)
