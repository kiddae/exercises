#include <iostream>
#include <string>
#include <vector>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

std::vector<std::string> string_to_array(const std::string &s) {
  std::vector<std::string> out;
  std::string word;
  for (auto &i : s) {
    if (word.length() != 0 && i == ' ') {
      out.push_back(word);
      word = "";
      continue;
    }
    word += i;
  }
  out.push_back(word);
  return out;
}

int main() {
  auto out = string_to_array("Hello World");
  for (auto i : out)
    std::cout << '\"' << i << '\"' << std::endl;
  return 0;
}
