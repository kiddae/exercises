# https://prologin.org/train/2022/qualification/derniere_piece

# Énoncé

# Après avoir traversé les dimensions, Joseph Marchand se retrouve face à une porte gigantesque. Cependant, ce n'est pas une porte normale : il s'agit d'un puzzle. Pour ne pas arranger les choses, les pièces ne ressemblent en rien à des pièces de puzzle ordinaire. Ce sont des polygones de toutes sortes ! Triangles, rectangles, octogones et j'en passe... Mais bonne nouvelle : il est presque terminé, il ne manque plus qu'une pièce. Dans un coin au sol se trouve de nombreuses pièces, l'une d'entre elle pourrait bien lui permettre de terminer ce puzzle.

# En plus de chercher une pièce avec le bon nombre de côtés, il faut également que la pièce soit d'une couleur différente de celles des pièces adjacentes.

# Déjà fatigué par son saut inter-dimensionnel, Joseph Marchand souhaite transporter le moins de pièces possible. Il lui faut donc identifier les pièces qui pourraient potentiellement convenir pour ne déplacer que ces dernières. Aide-le à ouvrir la porte rapidement !
# Entrée

# L'entrée contiendra :

#     Sur la première ligne, un entier : nCouleurs, le nombre de couleurs.
#     Sur les lignes suivantes, une liste de nCouleurs éléments : couleurs, les différentes couleurs possibles.
#         Une ligne par élément de la liste : une chaine de caractères.
#     Sur la ligne suivante, un entier : nCotes, le nombre de côtés de la pièce manquante.
#     Sur les lignes suivantes, une liste de nCotes éléments : couleurscotes, les couleurs des pièces adjacentes à la pièce manquante.
#         Une ligne par élément de la liste : une chaine d'au maximum 10 caractères.
#     Sur la ligne suivante, un entier : nPieces, le nombre de pièces à trier.
#     Sur les lignes suivantes, une liste de nPieces éléments : pieces, les pièces à trier.
#         Chaque élément de la liste est sur plusieurs lignes : une struct structpiece.
#             Sur la première ligne, un entier : nCotesPiece, le nombre de cotes de la pièce.
#             Sur la ligne suivante, une chaine d'au maximum 10 caractères : couleurPiece, la couleur de la pièce.

# Sortie

# Affiche sur la première ligne pour chaque pièce un caractère :

#     'O' si la pièce peut correspondre à celle recherchée
#     'X' sinon.

# Sur la ligne suivante, le nombre de pièces qui peuvent correspondre.
# Contraintes

# Runtime constraints

# Maximum memory usage
#     1000 kilobytes
# Maximum execution time
#     1000 milliseconds

# Input/output samples

# Sample input

#     5
#     blue
#     red
#     yellow
#     green
#     pink
#     3
#     blue
#     red
#     yellow
#     7
#     5
#     blue
#     8
#     pink
#     3
#     pink
#     6
#     blue
#     3
#     green
#     5
#     pink
#     5
#     yellow

# Sample output

#     XXOXOXX
#     2

# Sample input

#     1
#     rose
#     3
#     rose
#     rose
#     rose
#     3
#     1
#     rose
#     3
#     rose
#     6
#     rose

# Sample output

#     XXX
#     0

# Sample input

#     4
#     bleu
#     rouge
#     jaune
#     rose
#     3
#     bleu
#     bleu
#     bleu
#     5
#     3
#     rouge
#     3
#     rouge
#     3
#     jaune
#     3
#     rose
#     3
#     rouge

# Sample output

#     OOOOO
#     5

def resoudre(ncouleurs, couleurs, ncotes, couleurscotes, npieces, pieces):
    """
    :param ncouleurs: le nombre de couleurs
    :type ncouleurs: int
    :param couleurs: les différentes couleurs possibles
    :type couleurs: list[str]
    :param ncotes: le nombre de côtés de la pièce manquante
    :type ncotes: int
    :param couleurscotes: les couleurs des pièces adjacentes à la pièce manquante
    :type couleurscotes: list[str]
    :param npieces: le nombre de pièces à trier
    :type npieces: int
    :param pieces: les pièces à trier
    :type pieces: list[dict["nCotesPiece": int, "couleurPiece": str]]
    """
    # TODO Affiche sur la première ligne, pour chaque pièce un caractère 'O' si
    # la pièce peut correspondre à celle recherchée, 'X' sinon. Affiche sur la
    # ligne suivante le nombre de pièces qui peuvent correspondre.
    compte = 0
    for piece in pieces:
        if piece["nCotesPiece"] == ncotes and piece["couleurPiece"] not in couleurscotes:
            print('O', end='')
            compte += 1
        else:
            print('X', end='')
    print('\n{}'.format(compte))
    pass


if __name__ == '__main__':
    ncouleurs = int(input())
    couleurs = [input() for _ in range(ncouleurs)]
    ncotes = int(input())
    couleurscotes = [input() for _ in range(ncotes)]
    npieces = int(input())
    pieces = [{
        "nCotesPiece": int(input()),
        "couleurPiece": input()
    } for _ in range(npieces)]
    resoudre(ncouleurs, couleurs, ncotes, couleurscotes, npieces, pieces)
