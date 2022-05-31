#include <iostream>
#include <vector>

std::vector<std::vector<int>> souslistes(const std::vector<int> &l) {
  int s = 1;
  std::vector<std::vector<int>> out;
  int n = l.size();
  for (int s = 1; s <= n; s++) {
    for (int i = 0; i <= n - s; i++) {
      std::vector<int> el;
      int j = i + s;
      for (int a = i; a < j; a++)
        el.push_back(l[a]);
      out.push_back(el);
    }
  }
  return out;
}

int somme(const std::vector<int> &l) {
  int s = 0;
  for (int i : l)
    s += i;
  return s;
}

void affiche(const std::vector<int> &l1, const std::vector<int> &l2) {
  if (l1.size() > l2.size() || l1.size() == l2.size() && l1[0] > l2[0]) {
    for (int i = 0; i < l1.size(); i++)
      std::cout << " " << l1[i];
    std::cout << std::endl;
    for (int i = 0; i < l2.size(); i++)
      std::cout << l2[i] << (i != l2.size() ? " " : "");
    std::cout << std::endl;
  } else {
    for (int i = 0; i < l2.size(); i++)
      std::cout << l2[i] << (i != l2.size() ? " " : "");
    std::cout << std::endl;
    for (int i = 0; i < l1.size(); i++)
      std::cout << l1[i] << (i != l1.size() ? " " : "");
    std::cout << std::endl;
  }
}

/// \param x le nombre magique
/// \param n la longueur du code la Matriks
/// \param l le code de la Matriks
void resoudre(int x, int n, const std::vector<int> &l) {
  /* TODO Les deux clés (chacune sur une ligne) ou le message "IMPOSSIBLE".
   */
  std::vector combs = souslistes(l);
  for (std::vector<int> i : combs) {
    for (std::vector<int> j : combs) {
      if (i != j && somme(i) * somme(j) == x) {
        affiche(i, j);
        return;
      }
    }
  }
  std::cout << "IMPOSSIBLE" << std::endl;
}

int main() {
  int x; ///< le nombre magique
  std::cin >> x;
  int n; ///< la longueur du code la Matriks
  std::cin >> n;
  std::vector<int> l(n); ///< le code de la Matriks
  for (int &i : l)
    std::cin >> i;
  resoudre(x, n, l);
}
