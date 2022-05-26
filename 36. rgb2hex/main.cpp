#include <iostream>
#include <string>
#define test(a, b)                                                             \
  { std::cout << (a == b) << std::endl; }

class RGBToHex {
public:
  static std::string rgb(int r, int g, int b);

private:
  static std::string dec2hex(int n);
};

std::string RGBToHex::rgb(int r, int g, int b) {
  std::string hexr;
  std::string hexg;
  std::string hexb;
  return hexr + hexg + hexb;
}

int main() {
  ;
  return 0;
}
