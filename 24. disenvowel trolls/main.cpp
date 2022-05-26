#include <algorithm>
#include <iostream>
#include <string>

std::string disemvowel(std::string str) {
  /* char vowels[13] = "aeiouAEIOU"; */
  /* std::string out; */
  /* for (char i : str) { */
  /*   bool in = false; */
  /*   for (char v : vowels) { */
  /*     if (i == v) */
  /*       in = true; */
  /*   } */
  /*   if (!in) */
  /*     out.push_back(i); */
  /* } */
  /* return out; */
  for (char i : "aeiouAEIOU")
    str.erase(std::remove(str.begin(), str.end(), i), str.end());
  return str;
}

int main() {
  std::cout << disemvowel("This website is for losers LOL!") << std::endl;
}
