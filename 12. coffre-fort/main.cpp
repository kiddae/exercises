// https://prologin.org/train/2022/qualification/coffre-fort
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

struct Fil {
  int puce1;
  int puce2;
};

struct Question {
  int puce_a;
  int puce_b;
};

std::vector<int> puces_adj(std::vector<Fil> fils, int p) {
  std::vector<int> out;
  for (Fil f : fils) {
    if (f.puce1 == p)
      out.push_back(f.puce2);
    else if (f.puce2 == p)
      out.push_back(f.puce1);
  }
  return out;
}

std::vector<int> bfs(std::vector<Fil> fils, int a, int b) {
  // bfs
  std::vector<int> explored;
  std::queue<int> q;
  std::map<int, int> parents;
  explored.push_back(a);
  q.push(a);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == b)
      break;
    std::vector<int> adj = puces_adj(fils, v);
    for (int i : adj) {
      if (std::find(explored.begin(), explored.end(), i) == explored.end()) {
        explored.push_back(i);
        parents[i] = v;
        q.push(i);
      }
    }
  }
  // retracer le chemin à partir des parents
  std::vector<int> chemin = {b};
  int i = b;
  while (i != a) {
    chemin.push_back(parents[i]);
    i = parents[i];
  }
  return chemin;
}

std::vector<int> search(std::vector<Fil> Fils, int a, int b) {
  std::vector<int> explored;
  std::map<int, int> parents;
  std::deque<int> q;
  explored.push_back(a);
  q.push_back(a);
  while (!q.empty()) {
    int v = q.back();
    q.pop_back();
    if (v == b)
      break;
    for (auto i : puces_adj(Fils, v)) {
      if (std::find(explored.begin(), explored.end(), i) == explored.end()) {
        explored.push_back(i);
        q.push_back(i);
        parents[i] = v;
      }
    }
  }
  std::vector<int> chemin = {b};
  int i = b;
  while (i != a) {
    chemin.push_back(parents[i]);
    i = parents[i];
  }
  return chemin;
}

void calcul_signaux(int n, int m, int r, const std::vector<int> &signaux,
                    const std::vector<Fil> &fils,
                    const std::vector<Question> &questions) {
  for (Question q : questions) {
    auto sea = bfs(fils, q.puce_a, q.puce_b);
    /* for (int i : sea) */
    /*   std::cout << i << " "; */
    /* std::cout << std::endl; */
    int s = 1;
    for (int i : sea)
      s *= signaux[i];
    std::cout << s << std::endl;
    std::cout << (s % 1671404011) << std::endl;
  }
}

int main() {
  int n, m, r;
  std::cin >> n >> m >> r;

  std::vector<int> signaux(n);
  std::vector<Fil> fils(m);
  std::vector<Question> questions(r);
  for (int &i : signaux)
    std::cin >> i;
  for (Fil &i : fils)
    std::cin >> i.puce1 >> i.puce2;
  for (Question &i : questions)
    std::cin >> i.puce_a >> i.puce_b;

  calcul_signaux(n, m, r, signaux, fils, questions);
}
