#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

using namespace std;
int main() {
  int taille;
  cin >> taille;
  vector<string> noms(taille);
  for (string &i : noms)
    getline(cin >> ws, i);

  map<string, int> mp;
  sort(noms.begin(), noms.end(),
       [](string &left, string &right) { return left.size() > right.size(); });
  for (int s = 2; s <= noms[0].size(); s++) {
    for (string n : noms)
      if (n.length() >= s)
        mp[n.substr(0, s)]++;
  }
  string max =
      max_element(mp.begin(), mp.end(),
                  [](const pair<string, int> &p1, const pair<string, int> &p2) {
                    if (p1.second != p2.second)
                      return p1.second < p2.second;
                    else if (p1.first.length() != p2.first.length())
                      return p1.first.length() < p2.first.length();
                    else
                      return p1.first < p2.first;
                  })
          ->first;
  std::cout << max << std::endl;

  return 0;
}
