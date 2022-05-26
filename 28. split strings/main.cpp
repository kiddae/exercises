#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> solution(const std::string &s) {
  std::vector<std::string> o;
  for (int i = 0; i < s.length(); i += 2) {
    if (i + 1 == s.size())
      o.push_back(std::string(1, s[i]) + "_");
    else
      o.push_back(std::string(1, s[i]) + std::string(1, s[i + 1]));
  }
  return o; // Your code here
}

int main() {
  std::vector<std::string> expect = {"ab", "cd", "e_"};
  std::vector<std::string> actual = solution("abcde");
  std::cout << (expect == actual) << std::endl;
  for (std::string i : actual)
    std::cout << i << ",";
  return 0;
}
