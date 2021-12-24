# https://prologin.org/train/2022/qualification/coffre-fort

# Énoncé

# Joseph Marchand doit ouvrir un coffre électronique sécurisé.

# Le coffre contient un circuit complexe, décrit sous la forme d'un ensemble de puces, reliées entre elles par des fils. Il existe toujours exactement un chemin entre chaque paire de puces. Chaque puce envoie un signal

# au verrou lorsqu'elle est activée. Joseph Marchand tente de passer outre la sécurité du coffre et a besoin de votre aide pour calculer rapidement les effets de ses manipulations.

# Il veut régulièrement connecter les deux bornes d'un générateur électrique à deux puces
# et du circuit, et se demande quel signal est envoyé au verrou du coffre suite à cette opération. Une puce est activée s'il existe un chemin de vers passant par , qui ne repasse pas deux fois par le même fil. Le signal reçu par le verrou est alors le produit du signal envoyé par chaque puce activée, modulo

# (car on ne peut pas représenter de trop grands nombres par un signal électrique).
# Exemple

# exemple
# Entrée

# L'entrée contiendra :

#     Sur la première ligne, un entier : N, nombre de puces.
#     Sur la ligne suivante, un entier : M, nombre de fils, égal à N-1
#     Sur la ligne suivante, un entier : R, nombre de questions.
#     Sur la ligne suivante, une liste de N entiers séparés par des espaces : signaux, liste des signaux.
#     Sur les lignes suivantes, une liste de M éléments : fils, liste des fils entre les puces.
#         Une ligne par élément de la liste : séparés par des espaces, un entier puce1 (première extrémité du fil), et un entier puce2 (seconde extrémité du fil).
#     Sur les lignes suivantes, une liste de R éléments : questions, liste des questions.
#         Une ligne par élément de la liste : séparés par des espaces, un entier puce a (première extrémité alimentée), et un entier puce b (seconde extrémité alimentée).

# Sortie

# Affiche le signal envoyé au coffre-fort pour chaque requête.
# Contraintes

# Runtime constraints

# Maximum memory usage
#     20000 kilobytes
# Maximum execution time
#     1000 milliseconds

# Input/output samples

# Sample input

#     6
#     5
#     5
#     4 9 7 2 3 0
#     0 1
#     1 3
#     1 2
#     2 4
#     4 5
#     0 3
#     1 3
#     0 4
#     0 5
#     1 2

# Sample output

#     72
#     18
#     756
#     0
#     63

# Sample input

#     12
#     11
#     5
#     1671404010 1671404009 1371404010 1 3 8 2 7 10 4 0 6
#     0 1
#     2 0
#     3 2
#     3 4
#     9 3
#     5 3
#     7 5
#     5 6
#     8 4
#     9 10
#     11 10
#     1 8
#     7 7
#     6 8
#     9 7
#     2 10

# Sample output

#     385444061
#     7
#     480
#     224
#     0

def calculer_signaux(n, m, r, signaux, fils, questions):
    """
    :param n: nombre de puces
    :type n: int
    :param m: nombre de fils
    :type m: int
    :param r: nombre de questions
    :type r: int
    :param signaux: liste des signaux
    :type signaux: list[int]
    :param fils: liste des fils entre les puces
    :type fils: list[dict["puce1": int, "puce2": int]]
    :param questions: liste des questions
    :type questions: list[dict["puce a": int, "puce b": int]]
    """
    # TODO Affiche le signal envoyé au coffre-fort pour chaque requête
    liaisons = {}
    for i in range(m):
        liaisons[i] = []
        for f in fils:
            if i in f.values():
                liaisons[i].append(f)
    for q in questions:
        # Obtention du chemin
        i = q['puce a']
        chemin = [i]
        faux_chemins = []
        parcouru = []
        while i != q['puce b']:
            fils_parcours = [
                x for x in liaisons[i] if x not in faux_chemins and x not in parcouru]
            for f in fils_parcours:
                i = f['puce2'] if i == f['puce1'] else f['puce1']
                chemin.append(i)
                dernier_f = f
                parcouru.append(f)
                break
            if len(fils_parcours) == 0:
                faux_chemins.append(dernier_f)
                i = q['puce a']
                chemin = [i]
                parcouru = []
        # Calcul et affichage
        p = 1
        for x in chemin:
            p *= signaux[x]
        print(p % 1671404011)
    pass


if __name__ == '__main__':
    n = int(input())
    m = int(input())
    r = int(input())
    signaux = list(map(int, input().split()))
    fils = [
        dict(zip(("puce1", "puce2"), map(int, input().split())))
        for _ in range(m)
    ]
    questions = [
        dict(zip(("puce a", "puce b"), map(int, input().split())))
        for _ in range(r)
    ]
    calculer_signaux(n, m, r, signaux, fils, questions)
