#include <iostream>
#include <string>
#define test(a, b)                                                             \
  { std::cout << a << " " << b << ": " << (a == b) << std::endl; }

std::string add(const std::string &a, const std::string &b) {
  std::string longest = a.length() > b.length() ? a : b;
  std::string out;
  int carry = 0;
  int add;
  for (int i = 0; i < longest.length(); i++) {
    add = 0;
    if (i < a.length() && i < b.length())
      add = a[a.length() - 1 - i] - '0' + b[b.length() - 1 - i] - '0';
    else
      add = longest[longest.length() - 1 - i] - '0';
    add += carry;
    if (add >= 10) {
      int u = add % 10;
      carry = (add - u) / 10;
      add = i != longest.length() - 1 ? u : add;
    } else {
      carry = 0;
    }
    out = std::to_string(add) + out;
  }
  return out;
}

int main() {
  test(add("123", "456"), "579");
  test(add("0", "0"), "0");
  test(add("99", "2"), "101");
  test(add("10", "35679"), "35689");
  test(add("", "5"), "5");
  test(add("9999", "1111"), "11110");
  return 0;
}
