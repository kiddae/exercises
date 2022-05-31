#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

/// Représentation d'un véhicule
struct Vehicule {
  int m; ///< le numéro de série du véhicule
  int p; ///< le prix initial
  int r; ///< la taille du réservoir
  int c; ///< le coût au kilomètre
};

/// \param n le nombre de véhicules disponibles
/// \param d la distance à parcourir
/// \param v la liste des véhicules
void rent(int n, int d, const std::vector<Vehicule> &v) {
  /* TODO Le numéro de modèle du véhicule revenant le moins cher ou $-1$ si
  aucun véhicule n'est disponible (la liste est vide ou aucun véhicule ne
  possède un réservoir suffisamment grand). Si deux modèles sont équivalents,
  le véhicule retenu sera celui-ci ayant été considéré en premier dans
  l'ordre de la liste. */
  std::vector<std::pair<int, int>> prix;
  for (Vehicule veh : v) {
    if (veh.r >= d) {
      prix.push_back(std::pair<int, int>({veh.m, veh.p + veh.c * d}));
    }
  }
  if (prix.empty()) {
    std::cout << -1 << std::endl;
    return;
  }
  std::sort(prix.begin(), prix.end(),
            [](std::pair<int, int> left, std::pair<int, int> right) {
              return left.second < right.second;
            });
  std::cout << prix[0].first << std::endl;
}

int main() {
  int n; ///< le nombre de véhicules disponibles
  std::cin >> n;
  int d; ///< la distance à parcourir
  std::cin >> d;
  std::vector<Vehicule> v(n); ///< la liste des véhicules
  for (Vehicule &i : v) {
    std::cin >> i.m >> i.p >> i.r >> i.c;
  }
  rent(n, d, v);
}
