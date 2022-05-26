#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

std::string duplicate_encoder(const std::string &word) {
  std::unordered_map<char, int> dict;
  std::string out;
  for (char c : word)
    dict[std::toupper(c)]++;
  for (char c : word)
    out.append(dict[std::toupper(c)] > 1 ? ")" : "(");
  return out;
}

int main() {
  std::cout << (duplicate_encoder("din") == "(((") << std::endl;
  std::cout << (duplicate_encoder("recede") == "()()()") << std::endl;
  std::cout << (duplicate_encoder("CodeWarrior") == "()(((())())") << std::endl;
  std::cout << (duplicate_encoder("Supralapsarian") == ")()))()))))()(")
            << std::endl;
  std::cout << (duplicate_encoder("(( @") == "))((") << std::endl;
  return 0;
}
